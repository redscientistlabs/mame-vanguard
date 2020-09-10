// license:BSD-3-Clause
// copyright-holders:Aaron Giles

#include "emu.h"
#include "ym2612.h"


DEFINE_DEVICE_TYPE(YM2612, ym2612_device, "ym2612", "YM2612 OPN2")
DEFINE_DEVICE_TYPE(YM3438, ym3438_device, "ym3438", "YM3438 OPN2C")
DEFINE_DEVICE_TYPE(YMF276, ymf276_device, "ymf276", "YMF276 OPN2L")


//*********************************************************
//  YM2612 DEVICE
//*********************************************************

//-------------------------------------------------
//  ym2612_device - constructor
//-------------------------------------------------

ym2612_device::ym2612_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock, device_type type) :
	device_t(mconfig, type, tag, owner, clock),
	device_sound_interface(mconfig, *this),
	m_opn(*this, true),
	m_stream(nullptr),
	m_address(0),
	m_dac_data(0),
	m_dac_enable(0)
#if MULTIPLEX_YM2612_YM3438_OUTPUT
	,m_channel(0)
#endif
{
}


//-------------------------------------------------
//  read - handle a read from the device
//-------------------------------------------------

u8 ym2612_device::read(offs_t offset)
{
	u8 result = 0;
	switch (offset & 3)
	{
		case 0:	// status port, YM2203 compatible
			result = m_opn.status();
			break;

		case 1: // data port (unused)
		case 2:	// status port, extended
		case 3:	// data port (unused)
			printf("Unexpected read from YM2612 offset %d\n", offset & 3);
			break;
	}
	return result;
}


//-------------------------------------------------
//  write - handle a write to the register
//  interface
//-------------------------------------------------

void ym2612_device::write(offs_t offset, u8 value)
{
	switch (offset & 3)
	{
		case 0:	// address port
			m_address = value;
			break;

		case 1: // data port

			// ignore if paired with upper address
			if (BIT(m_address, 8))
				break;

			// force an update
			m_stream->update();

			// DAC data
			if (m_address == 0x2a)
				m_dac_data = (m_dac_data & ~0x1fe) | (value << 1);

			// DAC enable
			else if (m_address == 0x2b)
				m_dac_enable = BIT(value, 7);

			// test/low DAC bit
			else if (m_address == 0x2c)
				m_dac_data = (m_dac_data & ~1) | BIT(value, 3);

			// write to OPN
			else
				m_opn.write(m_address, value);

			// mark busy for a bit
			m_opn.set_busy();
			break;

		case 2: // upper address port
			m_address = 0x100 | value;
			break;

		case 3: // upper data port

			// ignore if paired with lower address
			if (!BIT(m_address, 8))
				break;

			// write to OPN
			m_stream->update();
			m_opn.write(m_address, value);

			// mark busy for a bit
			m_opn.set_busy();
			break;
	}
}


//-------------------------------------------------
//  device_start - start of emulation
//-------------------------------------------------

void ym2612_device::device_start()
{
	// create our stream
#if MULTIPLEX_YM2612_YM3438_OUTPUT
	m_stream = stream_alloc(0, 2, clock() / (4 * 6));
#else
	m_stream = stream_alloc(0, 2, clock() / (4 * 6 * 6));
#endif

	// call this for the variants that need to adjust the rate
	device_clock_changed();

	// save our data
	save_item(YMOPN_NAME(m_address));
	save_item(YMOPN_NAME(m_dac_data));
	save_item(YMOPN_NAME(m_dac_enable));
#if MULTIPLEX_YM2612_YM3438_OUTPUT
	save_item(YMOPN_NAME(m_channel));
#endif

	// save the the engines
	m_opn.save(*this);
}


//-------------------------------------------------
//  device_reset - start of emulation
//-------------------------------------------------

void ym2612_device::device_reset()
{
	// reset the the engines
	m_opn.reset();

	// reset our internal state
	m_dac_enable = 0;
#if MULTIPLEX_YM2612_YM3438_OUTPUT
	m_channel = 0;
#endif
}


//-------------------------------------------------
//  device_clock_changed - update if clock changes
//-------------------------------------------------

void ym2612_device::device_clock_changed()
{
#if MULTIPLEX_YM2612_YM3438_OUTPUT
	m_stream->set_sample_rate(clock() / (4 * 6));
#else
	m_stream->set_sample_rate(clock() / (4 * 6 * 6));
#endif
}


//-------------------------------------------------
//  sound_stream_update - update the sound stream
//-------------------------------------------------

void ym2612_device::sound_stream_update(sound_stream &stream, stream_sample_t **inputs, stream_sample_t **outputs, int samples)
{
	sound_stream_update_common(outputs[0], outputs[1], samples, true);
}


//-------------------------------------------------
//  sound_stream_update_common - shared stream
//  update function among subclasses
//-------------------------------------------------

void ym2612_device::sound_stream_update_common(stream_sample_t *outl, stream_sample_t *outr, int samples, bool discontinuity)
{
	// mask off channel 6 if DAC is enabled
	u8 const opn_mask = m_dac_enable ? 0x1f : 0x3f;

#if MULTIPLEX_YM2612_YM3438_OUTPUT

	// iterate over all target samples
	for (int sampindex = 0; sampindex < samples; sampindex++)
	{
		// clock the OPN when we hit channel 0
		if (m_channel == 0)
			m_opn.clock(opn_mask);

		// update the OPN content; OPN2 is 9-bit with intermediate clipping
		s32 lsum = 0, rsum = 0;
		if (m_channel == 5 && m_dac_enable)
			lsum = rsum = m_dac_data;
		else
			m_opn.output(lsum, rsum, 5, 256, 1 << m_channel);

		// hiccup in the DAC means that there is a larger gap between 0 and -1
		if (discontinuity)
		{
			if (lsum < 0)
				lsum--;
			if (rsum < 0)
				rsum--;
		}

		// shift up to 16 bits
		lsum <<= 7;
		rsum <<= 7;

		// YM2612 is stereo
		outl[sampindex] = lsum;
		outr[sampindex] = rsum;

		// next channel
		m_channel++;
		if (m_channel >= 6)
			m_channel = 0;
	}

#else

	// iterate over all target samples
	for (int sampindex = 0; sampindex < samples; sampindex++)
	{
		// clock the OPN
		m_opn.clock(opn_mask);

		// update the OPN content; OPN2 is 9-bit with intermediate clipping
		s32 lsum = 0, rsum = 0;
		m_opn.output(lsum, rsum, 5, 256, opn_mask);

		// add in DAC if enabled
		if (m_dac_enable)
		{
			lsum += m_dac_data;
			rsum += m_dac_data;
		}

		// hiccup in the DAC means that there is a larger gap between 0 and -1
		if (discontinuity)
		{
			if (lsum < 0)
				lsum--;
			if (rsum < 0)
				rsum--;
		}

		// shift back up to 14 bits
		lsum <<= 5;
		rsum <<= 5;

		// OPN2 is stereo
		if (lsum < -32768)
			lsum = -32768;
		else if (lsum > 32767)
			lsum = 32767;
		if (rsum < -32768)
			rsum = -32768;
		else if (rsum > 32767)
			rsum = 32767;
		outl[sampindex] = lsum;
		outr[sampindex] = rsum;
	}

#endif
}



//*********************************************************
//  YM3438 DEVICE
//*********************************************************

//-------------------------------------------------
//  ym3438_device - constructor
//-------------------------------------------------

ym3438_device::ym3438_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock) :
	ym2612_device(mconfig, tag, owner, clock, YM3438)
{
}


//-------------------------------------------------
//  sound_stream_update - update the sound stream
//-------------------------------------------------

void ym3438_device::sound_stream_update(sound_stream &stream, stream_sample_t **inputs, stream_sample_t **outputs, int samples)
{
	sound_stream_update_common(outputs[0], outputs[1], samples, false);
}



//*********************************************************
//  YMF276 DEVICE
//*********************************************************

//-------------------------------------------------
//  ymf276_device - constructor
//-------------------------------------------------

ymf276_device::ymf276_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock) :
	ym2612_device(mconfig, tag, owner, clock, YMF276)
{
}


//-------------------------------------------------
//  device_clock_changed - update if clock changes
//-------------------------------------------------

void ymf276_device::device_clock_changed()
{
	m_stream->set_sample_rate(clock() / (4 * 6 * 6));
}


//-------------------------------------------------
//  sound_stream_update - update the sound stream
//-------------------------------------------------

void ymf276_device::sound_stream_update(sound_stream &stream, stream_sample_t **inputs, stream_sample_t **outputs, int samples)
{
	// mask off channel 6 if DAC is enabled
	u8 const opn_mask = m_dac_enable ? 0x1f : 0x3f;

	// iterate over all target samples
	for (int sampindex = 0; sampindex < samples; sampindex++)
	{
		// clock the OPN
		m_opn.clock(opn_mask);

		// update the OPN content; OPN2L is 14-bit with intermediate clipping
		s32 lsum = 0, rsum = 0;
		m_opn.output(lsum, rsum, 0, 8191, opn_mask);

		// shifted down 1 bits after mixer
		lsum >>= 1;
		rsum >>= 1;

		// add in DAC if enabled
		if (m_dac_enable)
		{
			lsum += m_dac_data << 4;
			rsum += m_dac_data << 4;
		}

		// YMF3438 is stereo
		if (lsum < -32768)
			lsum = -32768;
		else if (lsum > 32767)
			lsum = 32767;
		if (rsum < -32768)
			rsum = -32768;
		else if (rsum > 32767)
			rsum = 32767;
		outputs[0][sampindex] = lsum;
		outputs[1][sampindex] = rsum;
	}
}

