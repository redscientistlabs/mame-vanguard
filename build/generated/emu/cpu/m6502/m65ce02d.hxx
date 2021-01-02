const m65ce02_disassembler::disasm_entry m65ce02_disassembler::disasm_entries[0x100] = {

	{ "brk", DASM_imp, 0 },
	{ "ora", DASM_idx, 0 },
	{ "cle", DASM_imp, 0 },
	{ "see", DASM_imp, 0 },
	{ "tsb", DASM_zpg, 0 },
	{ "ora", DASM_zpg, 0 },
	{ "asl", DASM_zpg, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "php", DASM_imp, 0 },
	{ "ora", DASM_imm, 0 },
	{ "asl", DASM_acc, 0 },
	{ "tsy", DASM_imp, 0 },
	{ "tsb", DASM_aba, 0 },
	{ "ora", DASM_aba, 0 },
	{ "asl", DASM_aba, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "bpl", DASM_rel, 0 },
	{ "ora", DASM_idy, 0 },
	{ "ora", DASM_idz, 0 },
	{ "bpl", DASM_rw2, 0 },
	{ "trb", DASM_zpg, 0 },
	{ "ora", DASM_zpx, 0 },
	{ "asl", DASM_zpx, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "clc", DASM_imp, 0 },
	{ "ora", DASM_aby, 0 },
	{ "inc", DASM_acc, 0 },
	{ "inz", DASM_imp, 0 },
	{ "trb", DASM_aba, 0 },
	{ "ora", DASM_abx, 0 },
	{ "asl", DASM_abx, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "jsr", DASM_adr, STEP_OVER },
	{ "and", DASM_idx, 0 },
	{ "jsr", DASM_ind, STEP_OVER },
	{ "jsr", DASM_iax, STEP_OVER },
	{ "bit", DASM_zpg, 0 },
	{ "and", DASM_zpg, 0 },
	{ "rol", DASM_zpg, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "plp", DASM_imp, 0 },
	{ "and", DASM_imm, 0 },
	{ "rol", DASM_acc, 0 },
	{ "tys", DASM_imp, 0 },
	{ "bit", DASM_aba, 0 },
	{ "and", DASM_aba, 0 },
	{ "rol", DASM_aba, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "bmi", DASM_rel, 0 },
	{ "and", DASM_idy, 0 },
	{ "and", DASM_idz, 0 },
	{ "bmi", DASM_rw2, 0 },
	{ "bit", DASM_zpx, 0 },
	{ "and", DASM_zpx, 0 },
	{ "rol", DASM_zpx, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "sec", DASM_imp, 0 },
	{ "and", DASM_aby, 0 },
	{ "dec", DASM_acc, 0 },
	{ "dez", DASM_imp, 0 },
	{ "bit", DASM_abx, 0 },
	{ "and", DASM_abx, 0 },
	{ "rol", DASM_abx, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "rti", DASM_imp, STEP_OUT },
	{ "eor", DASM_idx, 0 },
	{ "neg", DASM_acc, 0 },
	{ "asr", DASM_acc, 0 },
	{ "asr", DASM_zpg, 0 },
	{ "eor", DASM_zpg, 0 },
	{ "lsr", DASM_zpg, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "pha", DASM_imp, 0 },
	{ "eor", DASM_imm, 0 },
	{ "lsr", DASM_acc, 0 },
	{ "taz", DASM_imp, 0 },
	{ "jmp", DASM_adr, 0 },
	{ "eor", DASM_aba, 0 },
	{ "lsr", DASM_aba, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "bvc", DASM_rel, 0 },
	{ "eor", DASM_idy, 0 },
	{ "eor", DASM_idz, 0 },
	{ "bvc", DASM_rw2, 0 },
	{ "asr", DASM_zpx, 0 },
	{ "eor", DASM_zpx, 0 },
	{ "lsr", DASM_zpx, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "cli", DASM_imp, 0 },
	{ "eor", DASM_aby, 0 },
	{ "phy", DASM_imp, 0 },
	{ "tab", DASM_imp, 0 },
	{ "aug", DASM_iw3, 0 },
	{ "eor", DASM_abx, 0 },
	{ "lsr", DASM_abx, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "rts", DASM_imp, STEP_OUT },
	{ "adc", DASM_idx, 0 },
	{ "rtn", DASM_imm, STEP_OUT },
	{ "bsr", DASM_rw2, STEP_OVER },
	{ "stz", DASM_zpg, 0 },
	{ "adc", DASM_zpg, 0 },
	{ "ror", DASM_zpg, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "pla", DASM_imp, 0 },
	{ "adc", DASM_imm, 0 },
	{ "ror", DASM_acc, 0 },
	{ "tza", DASM_imp, 0 },
	{ "jmp", DASM_ind, 0 },
	{ "adc", DASM_aba, 0 },
	{ "ror", DASM_aba, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "bvs", DASM_rel, 0 },
	{ "adc", DASM_idy, 0 },
	{ "adc", DASM_idz, 0 },
	{ "bvs", DASM_rw2, 0 },
	{ "stz", DASM_zpx, 0 },
	{ "adc", DASM_zpx, 0 },
	{ "ror", DASM_zpx, 0 },
	{ "rmb", DASM_bzp, 0 },
	{ "sei", DASM_imp, 0 },
	{ "adc", DASM_aby, 0 },
	{ "ply", DASM_imp, 0 },
	{ "tba", DASM_imp, 0 },
	{ "jmp", DASM_iax, 0 },
	{ "adc", DASM_abx, 0 },
	{ "ror", DASM_abx, 0 },
	{ "bbr", DASM_zpb, 0 },
	{ "bra", DASM_rel, 0 },
	{ "sta", DASM_idx, 0 },
	{ "sta", DASM_isy, 0 },
	{ "bra", DASM_rw2, 0 },
	{ "sty", DASM_zpg, 0 },
	{ "sta", DASM_zpg, 0 },
	{ "stx", DASM_zpg, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "dey", DASM_imp, 0 },
	{ "bit", DASM_imm, 0 },
	{ "txa", DASM_imp, 0 },
	{ "sty", DASM_abx, 0 },
	{ "sty", DASM_aba, 0 },
	{ "sta", DASM_aba, 0 },
	{ "stx", DASM_aba, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "bcc", DASM_rel, 0 },
	{ "sta", DASM_idy, 0 },
	{ "sta", DASM_idz, 0 },
	{ "bcc", DASM_rw2, 0 },
	{ "sty", DASM_zpx, 0 },
	{ "sta", DASM_zpx, 0 },
	{ "stx", DASM_zpy, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "tya", DASM_imp, 0 },
	{ "sta", DASM_aby, 0 },
	{ "txs", DASM_imp, 0 },
	{ "stx", DASM_aby, 0 },
	{ "stz", DASM_aba, 0 },
	{ "sta", DASM_abx, 0 },
	{ "stz", DASM_abx, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "ldy", DASM_imm, 0 },
	{ "lda", DASM_idx, 0 },
	{ "ldx", DASM_imm, 0 },
	{ "ldz", DASM_imm, 0 },
	{ "ldy", DASM_zpg, 0 },
	{ "lda", DASM_zpg, 0 },
	{ "ldx", DASM_zpg, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "tay", DASM_imp, 0 },
	{ "lda", DASM_imm, 0 },
	{ "tax", DASM_imp, 0 },
	{ "ldz", DASM_aba, 0 },
	{ "ldy", DASM_aba, 0 },
	{ "lda", DASM_aba, 0 },
	{ "ldx", DASM_aba, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "bcs", DASM_rel, 0 },
	{ "lda", DASM_idy, 0 },
	{ "lda", DASM_idz, 0 },
	{ "bcs", DASM_rw2, 0 },
	{ "ldy", DASM_zpx, 0 },
	{ "lda", DASM_zpx, 0 },
	{ "ldx", DASM_zpy, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "clv", DASM_imp, 0 },
	{ "lda", DASM_aby, 0 },
	{ "tsx", DASM_imp, 0 },
	{ "ldz", DASM_abx, 0 },
	{ "ldy", DASM_abx, 0 },
	{ "lda", DASM_abx, 0 },
	{ "ldx", DASM_aby, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "cpy", DASM_imm, 0 },
	{ "cmp", DASM_idx, 0 },
	{ "cpz", DASM_imm, 0 },
	{ "dew", DASM_zpg, 0 },
	{ "cpy", DASM_zpg, 0 },
	{ "cmp", DASM_zpg, 0 },
	{ "dec", DASM_zpg, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "iny", DASM_imp, 0 },
	{ "cmp", DASM_imm, 0 },
	{ "dex", DASM_imp, 0 },
	{ "asw", DASM_aba, 0 },
	{ "cpy", DASM_aba, 0 },
	{ "cmp", DASM_aba, 0 },
	{ "dec", DASM_aba, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "bne", DASM_rel, 0 },
	{ "cmp", DASM_idy, 0 },
	{ "cmp", DASM_idz, 0 },
	{ "bne", DASM_rw2, 0 },
	{ "cpz", DASM_zpg, 0 },
	{ "cmp", DASM_zpx, 0 },
	{ "dec", DASM_zpx, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "cld", DASM_imp, 0 },
	{ "cmp", DASM_aby, 0 },
	{ "phx", DASM_imp, 0 },
	{ "phz", DASM_imp, 0 },
	{ "cpz", DASM_aba, 0 },
	{ "cmp", DASM_abx, 0 },
	{ "dec", DASM_abx, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "cpx", DASM_imm, 0 },
	{ "sbc", DASM_idx, 0 },
	{ "lda", DASM_isy, 0 },
	{ "inw", DASM_zpg, 0 },
	{ "cpx", DASM_zpg, 0 },
	{ "sbc", DASM_zpg, 0 },
	{ "inc", DASM_zpg, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "inx", DASM_imp, 0 },
	{ "sbc", DASM_imm, 0 },
	{ "nop", DASM_imp, 0 },
	{ "row", DASM_aba, 0 },
	{ "cpx", DASM_aba, 0 },
	{ "sbc", DASM_aba, 0 },
	{ "inc", DASM_aba, 0 },
	{ "bbs", DASM_zpb, 0 },
	{ "beq", DASM_rel, 0 },
	{ "sbc", DASM_idy, 0 },
	{ "sbc", DASM_idz, 0 },
	{ "beq", DASM_rw2, 0 },
	{ "phw", DASM_iw2, 0 },
	{ "sbc", DASM_zpx, 0 },
	{ "inc", DASM_zpx, 0 },
	{ "smb", DASM_bzp, 0 },
	{ "sed", DASM_imp, 0 },
	{ "sbc", DASM_aby, 0 },
	{ "plx", DASM_imp, 0 },
	{ "plz", DASM_imp, 0 },
	{ "phw", DASM_aba, 0 },
	{ "sbc", DASM_abx, 0 },
	{ "inc", DASM_abx, 0 },
	{ "bbs", DASM_zpb, 0 },
};

