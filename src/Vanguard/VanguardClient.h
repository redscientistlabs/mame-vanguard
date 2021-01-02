
#pragma once
#include <string>


class VanguardClientUnmanaged
{
public:
    static void CORE_STEP();
    static void LOAD_GAME_START(std::string romPath);
    static void LOAD_GAME_DONE();
    static void LOAD_STATE_DONE();
    static void GAME_CLOSED();
    static void CLOSE_GAME();
    static void InvokeEmuThread();
    static bool RTC_OSD_ENABLED();
    static void SAVE_STATE_DONE();
    /*static void DOSBOX_LOADEXE();
    static void DOSBOX_LOADROM();
    static void DOSBOX_LOADROM(char const* lTheOpenFileName);
    static void DOSBOX_SAVEROM();
    static void LoadExecutable(char const* lTheOpenFileName);*/
};
