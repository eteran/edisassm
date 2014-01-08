/*
Copyright (C) 2006 - 2014 Evan Teran
                          eteran@alum.rit.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPTABLE_1BYTE_20080314_TCC_
#define OPTABLE_1BYTE_20080314_TCC_

namespace edisassm {

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes[0x100] = {

	/* 0x00 - 0x0f */
	{ "add",   &instruction::decode_Eb_Gb,  OP_ADD,   FLAG_W_FLAGS },
	{ "add",   &instruction::decode_Ev_Gv,  OP_ADD,   FLAG_W_FLAGS },
	{ "add",   &instruction::decode_Gb_Eb,  OP_ADD,   FLAG_W_FLAGS },
	{ "add",   &instruction::decode_Gv_Ev,  OP_ADD,   FLAG_W_FLAGS },
	{ "add",   &instruction::decode_AL_Ib,  OP_ADD,   FLAG_W_FLAGS },
	{ "add",   &instruction::decode_rAX_Iz, OP_ADD,   FLAG_W_FLAGS },
	{ "push",  &instruction::decode_SegES,  OP_PUSH,  FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "pop",   &instruction::decode_SegES,  OP_POP,   FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "or",    &instruction::decode_Eb_Gb,  OP_OR,    FLAG_W_FLAGS },
	{ "or",    &instruction::decode_Ev_Gv,  OP_OR,    FLAG_W_FLAGS },
	{ "or",    &instruction::decode_Gb_Eb,  OP_OR,    FLAG_W_FLAGS },
	{ "or",    &instruction::decode_Gv_Ev,  OP_OR,    FLAG_W_FLAGS },
	{ "or",    &instruction::decode_AL_Ib,  OP_OR,    FLAG_W_FLAGS },
	{ "or",    &instruction::decode_rAX_Iz, OP_OR,    FLAG_W_FLAGS },
	{ "push",  &instruction::decode_SegCS,  OP_PUSH,  FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "2byte", &instruction::decode_2byte,  OP_2BYTE, FLAG_NONE },

	/* 0x10 - 0x1f */
	{ "adc",  &instruction::decode_Eb_Gb,  OP_ADC,  FLAG_RW_FLAGS },
	{ "adc",  &instruction::decode_Ev_Gv,  OP_ADC,  FLAG_RW_FLAGS },
	{ "adc",  &instruction::decode_Gb_Eb,  OP_ADC,  FLAG_RW_FLAGS },
	{ "adc",  &instruction::decode_Gv_Ev,  OP_ADC,  FLAG_RW_FLAGS },
	{ "adc",  &instruction::decode_AL_Ib,  OP_ADC,  FLAG_RW_FLAGS },
	{ "adc",  &instruction::decode_rAX_Iz, OP_ADC,  FLAG_RW_FLAGS },
	{ "push", &instruction::decode_SegSS,  OP_PUSH, FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "pop",  &instruction::decode_SegSS,  OP_POP,  FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "sbb",  &instruction::decode_Eb_Gb,  OP_SBB,  FLAG_RW_FLAGS },
	{ "sbb",  &instruction::decode_Ev_Gv,  OP_SBB,  FLAG_RW_FLAGS },
	{ "sbb",  &instruction::decode_Gb_Eb,  OP_SBB,  FLAG_RW_FLAGS },
	{ "sbb",  &instruction::decode_Gv_Ev,  OP_SBB,  FLAG_RW_FLAGS },
	{ "sbb",  &instruction::decode_AL_Ib,  OP_SBB,  FLAG_RW_FLAGS },
	{ "sbb",  &instruction::decode_rAX_Iz, OP_SBB,  FLAG_RW_FLAGS },
	{ "push", &instruction::decode_SegDS,  OP_PUSH, FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "pop",  &instruction::decode_SegDS,  OP_POP,  FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only

	/* 0x20 - 0x2f */
	{ "and",       &instruction::decode_Eb_Gb,   OP_AND,    FLAG_W_FLAGS },
	{ "and",       &instruction::decode_Ev_Gv,   OP_AND,    FLAG_W_FLAGS },
	{ "and",       &instruction::decode_Gb_Eb,   OP_AND,    FLAG_W_FLAGS },
	{ "and",       &instruction::decode_Gv_Ev,   OP_AND,    FLAG_W_FLAGS },
	{ "and",       &instruction::decode_AL_Ib,   OP_AND,    FLAG_W_FLAGS },
	{ "and",       &instruction::decode_rAX_Iz,  OP_AND,    FLAG_W_FLAGS },
	{ "prefix es", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "daa",       &instruction::decode0,        OP_DAA,    FLAG_32BIT_ONLY | FLAG_RW_FLAGS }, // ia-32 only
	{ "sub",       &instruction::decode_Eb_Gb,   OP_SUB,    FLAG_W_FLAGS },
	{ "sub",       &instruction::decode_Ev_Gv,   OP_SUB,    FLAG_W_FLAGS },
	{ "sub",       &instruction::decode_Gb_Eb,   OP_SUB,    FLAG_W_FLAGS },
	{ "sub",       &instruction::decode_Gv_Ev,   OP_SUB,    FLAG_W_FLAGS },
	{ "sub",       &instruction::decode_AL_Ib,   OP_SUB,    FLAG_W_FLAGS },
	{ "sub",       &instruction::decode_rAX_Iz,  OP_SUB,    FLAG_W_FLAGS },
	{ "prefix cs", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "das",       &instruction::decode0,        OP_DAS,    FLAG_32BIT_ONLY | FLAG_RW_FLAGS }, // ia-32 only

	/* 0x30 - 0x3f */
	{ "xor",       &instruction::decode_Eb_Gb,   OP_XOR,    FLAG_W_FLAGS },
	{ "xor",       &instruction::decode_Ev_Gv,   OP_XOR,    FLAG_W_FLAGS },
	{ "xor",       &instruction::decode_Gb_Eb,   OP_XOR,    FLAG_W_FLAGS },
	{ "xor",       &instruction::decode_Gv_Ev,   OP_XOR,    FLAG_W_FLAGS },
	{ "xor",       &instruction::decode_AL_Ib,   OP_XOR,    FLAG_W_FLAGS },
	{ "xor",       &instruction::decode_rAX_Iz,  OP_XOR,    FLAG_W_FLAGS },
	{ "prefix ss", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "aaa",       &instruction::decode0,        OP_AAA,    FLAG_32BIT_ONLY | FLAG_RW_FLAGS }, // ia-32 only
	{ "cmp",       &instruction::decode_Eb_Gb,   OP_CMP,    FLAG_W_FLAGS },
	{ "cmp",       &instruction::decode_Ev_Gv,   OP_CMP,    FLAG_W_FLAGS },
	{ "cmp",       &instruction::decode_Gb_Eb,   OP_CMP,    FLAG_W_FLAGS },
	{ "cmp",       &instruction::decode_Gv_Ev,   OP_CMP,    FLAG_W_FLAGS },
	{ "cmp",       &instruction::decode_AL_Ib,   OP_CMP,    FLAG_W_FLAGS },
	{ "cmp",       &instruction::decode_rAX_Iz,  OP_CMP,    FLAG_W_FLAGS },
	{ "prefix ds", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "aas",       &instruction::decode0,        OP_AAS,    FLAG_32BIT_ONLY | FLAG_RW_FLAGS }, // ia-32 only

	/* 0x40 - 0x4f */
	{ "inc", &instruction::decode_rAX, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rCX, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rDX, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rBX, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rSP, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rBP, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rSI, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "inc", &instruction::decode_rDI, OP_INC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rAX, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rCX, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rDX, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rBX, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rSP, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rBP, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rSI, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)
	{ "dec", &instruction::decode_rDI, OP_DEC, FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only (REX byte)

	/* 0x50 - 0x5f */
	{ "push", &instruction::decode_rAX, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rCX, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rDX, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rBX, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rSP, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rBP, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rSI, OP_PUSH, FLAG_STACK },
	{ "push", &instruction::decode_rDI, OP_PUSH, FLAG_STACK },
	{ "pop",  &instruction::decode_rAX, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rCX, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rDX, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rBX, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rSP, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rBP, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rSI, OP_POP,  FLAG_STACK },
	{ "pop",  &instruction::decode_rDI, OP_POP,  FLAG_STACK },

	/* 0x60 - 0x6f */
	{ "pushaw/pushad", &instruction::decode_pushaw_pushad_invalid, OP_GROUP,   FLAG_NONE },
	{ "popaw/popad",   &instruction::decode_popaw_popad_invalid,   OP_GROUP,   FLAG_NONE },
	{ "bound",         &instruction::decode_Gv_Ma,                 OP_BOUND,   FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only
	{ "arpl",          &instruction::decode_Ew_Gw,                 OP_ARPL,    FLAG_W_FLAGS }, // x86-64: movsxd Gv,Ev
	{ "prefix fs",     &instruction::decode_invalid,               OP_PREFIX,  FLAG_NONE },
	{ "prefix gs",     &instruction::decode_invalid,               OP_PREFIX,  FLAG_NONE },
	{ "prefix data16", &instruction::decode_invalid,               OP_PREFIX,  FLAG_NONE },
	{ "prefix addr16", &instruction::decode_invalid,               OP_PREFIX,  FLAG_NONE },
	{ "push",          &instruction::decode_Iz,                    OP_PUSH,    FLAG_STACK },
	{ "imul",          &instruction::decode_Gv_Ev_Iz,              OP_IMUL,    FLAG_W_FLAGS },
	{ "push",          &instruction::decode_Ib,                    OP_PUSH,    FLAG_STACK },
	{ "imul",          &instruction::decode_Gv_Ev_Ib,              OP_IMUL,    FLAG_W_FLAGS },
	{ "insb",          &instruction::decode0,                      OP_INS,     FLAG_R_FLAGS },
	{ "insw/insd",     &instruction::decode_insw_insd_invalid,     OP_GROUP,   FLAG_NONE },
	{ "outsb",         &instruction::decode0,                      OP_OUTS,    FLAG_R_FLAGS },
	{ "outsw/outsd",   &instruction::decode_outsw_outsd_invalid,   OP_GROUP,   FLAG_NONE },

	/* 0x70 - 0x7f */
	{ "jo",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },

	/* 0x80 - 0x8f */
	{ "group1",  &instruction::decode_group1,  OP_GROUP, FLAG_NONE },
	{ "group1",  &instruction::decode_group1,  OP_GROUP, FLAG_NONE },
	{ "group1",  &instruction::decode_group1,  OP_GROUP, FLAG_NONE },
	{ "group1",  &instruction::decode_group1,  OP_GROUP, FLAG_NONE },
	{ "test",    &instruction::decode_Eb_Gb,   OP_TEST,  FLAG_W_FLAGS },
	{ "test",    &instruction::decode_Ev_Gv,   OP_TEST,  FLAG_W_FLAGS },
	{ "xchg",    &instruction::decode_Gb_Eb,   OP_XCHG,  FLAG_NONE },
	{ "xchg",    &instruction::decode_Gv_Ev,   OP_XCHG,  FLAG_NONE },
	{ "mov",     &instruction::decode_Eb_Gb,   OP_MOV,   FLAG_NONE },
	{ "mov",     &instruction::decode_Ev_Gv,   OP_MOV,   FLAG_NONE },
	{ "mov",     &instruction::decode_Gb_Eb,   OP_MOV,   FLAG_NONE },
	{ "mov",     &instruction::decode_Gv_Ev,   OP_MOV,   FLAG_NONE },
	{ "mov",     &instruction::decode_Ev_Sw,   OP_MOV,   FLAG_NONE },
	{ "lea",     &instruction::decode_Gv_M,    OP_LEA,   FLAG_NONE },
	{ "mov",     &instruction::decode_Sw_Ew,   OP_MOV,   FLAG_NONE },
	{ "group10", &instruction::decode_group10, OP_GROUP, FLAG_NONE },

	/* 0x90 - 0x9f */
	{ "xchg",                 &instruction::decode_rAX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rCX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rDX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rBX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rSP_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rBP_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rSI_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &instruction::decode_rDI_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "cbw/cwde/cdqe",        &instruction::decode_cbw_cwde_cdqe,        OP_GROUP,   FLAG_NONE },
	{ "cwd/cdq/cqo",          &instruction::decode_cwd_cdq_cqo,          OP_GROUP,   FLAG_NONE },
	{ "callf",                &instruction::decode_Ap,                   OP_CALL,    FLAG_32BIT_ONLY | FLAG_STACK }, // ia-32 only
	{ "wait/prefix wait",     &instruction::wait_or_wait_prefix,         OP_GROUP,   FLAG_NONE },
	{ "pushfw/pushfd/pushfq", &instruction::decode_pushfw_pushfd_pushfq, OP_GROUP,   FLAG_NONE },
	{ "popfw/popfd/popfq",    &instruction::decode_popfw_popfd_popfq,    OP_GROUP,   FLAG_NONE },
	{ "sahf",                 &instruction::decode0,                     OP_SAHF,    FLAG_NONE },
	{ "lahf",                 &instruction::decode0,                     OP_LAHF,    FLAG_R_FLAGS },

	/* 0xa0 - 0xaf */
	{ "mov",               &instruction::decode_AL_Ob,             OP_MOV,   FLAG_NONE },
	{ "mov",               &instruction::decode_rAX_Ov,            OP_MOV,   FLAG_NONE },
	{ "mov",               &instruction::decode_Ob_AL,             OP_MOV,   FLAG_NONE },
	{ "mov",               &instruction::decode_Ov_rAX,            OP_MOV,   FLAG_NONE },
	{ "movsb",             &instruction::decode0,                  OP_MOVS,  FLAG_R_FLAGS },
	{ "movsw/movsd/movsq", &instruction::decode_movsw_movsd_movsq, OP_GROUP, FLAG_NONE },
	{ "cmpsb",             &instruction::decode0,                  OP_CMPS,  FLAG_RW_FLAGS },
	{ "cmpsw/cmpsd/cmpsq", &instruction::decode_cmpsw_cmpsd_cmpsq, OP_GROUP, FLAG_NONE },
	{ "test",              &instruction::decode_AL_Ib,             OP_TEST,  FLAG_R_FLAGS },
	{ "test",              &instruction::decode_rAX_Iz,            OP_TEST,  FLAG_R_FLAGS },
	{ "stosb",             &instruction::decode0,                  OP_STOS,  FLAG_R_FLAGS },
	{ "stosw/stosd/stosq", &instruction::decode_stosw_stosd_stosq, OP_GROUP, FLAG_NONE },
	{ "lodsb",             &instruction::decode0,                  OP_LODS,  FLAG_R_FLAGS },
	{ "lodsw/lodsd/lodsq", &instruction::decode_lodsw_lodsd_lodsq, OP_GROUP, FLAG_NONE },
	{ "scasb",             &instruction::decode0,                  OP_SCAS,  FLAG_RW_FLAGS },
	{ "scasw/scasd/scasq", &instruction::decode_scasw_scasd_scasq, OP_GROUP, FLAG_NONE },

	/* 0xb0 - 0xbf */
	{ "mov", &instruction::decode_AL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_CL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_DL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_BL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_AH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_CH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_DH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_BH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rAX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rCX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rDX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rBX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rSP_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rBP_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rSI_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &instruction::decode_rDI_Iv, OP_MOV, FLAG_NONE },

	/* 0xc0 - 0xcf */
	{ "group2",           &instruction::decode_group2,           OP_GROUP, FLAG_NONE },
	{ "group2",           &instruction::decode_group2,           OP_GROUP, FLAG_NONE },
	{ "ret",              &instruction::decode_Iw,               OP_RET,   FLAG_STACK },
	{ "ret",              &instruction::decode0,                 OP_RET,   FLAG_STACK },
	{ "les",              &instruction::decode_Gz_Mp,            OP_LES,   FLAG_32BIT_ONLY }, // ia-32 only
	{ "lds",              &instruction::decode_Gz_Mp,            OP_LDS,   FLAG_32BIT_ONLY }, // ia-32 only
	{ "group12",          &instruction::decode_group12,          OP_GROUP, FLAG_NONE },
	{ "group12",          &instruction::decode_group12,          OP_GROUP, FLAG_NONE },
	{ "enter",            &instruction::decode_Iw_Ib,            OP_ENTER, FLAG_STACK },
	{ "leave",            &instruction::decode0,                 OP_LEAVE, FLAG_STACK },
	{ "retf",             &instruction::decode_Iw,               OP_RETF,  FLAG_STACK },
	{ "retf",             &instruction::decode0,                 OP_RETF,  FLAG_STACK },
	{ "int3",             &instruction::decode0,                 OP_INT3,  FLAG_W_FLAGS },
	{ "int",              &instruction::decode_Ib,               OP_INT,   FLAG_W_FLAGS },
	{ "into",             &instruction::decode0,                 OP_INTO,  FLAG_RW_FLAGS | FLAG_32BIT_ONLY }, // ia-32 only
	{ "iretw/iret/iretq", &instruction::decode_iretw_iret_iretq, OP_GROUP, FLAG_NONE },

	/* 0xd0 - 0xdf */
	{ "group2", &instruction::decode_group2D, OP_GROUP, FLAG_NONE },
	{ "group2", &instruction::decode_group2D, OP_GROUP, FLAG_NONE },
	{ "group2", &instruction::decode_group2D, OP_GROUP, FLAG_NONE },
	{ "group2", &instruction::decode_group2D, OP_GROUP, FLAG_NONE },
	{ "aam",    &instruction::decode_Ib,      OP_AAM,   FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only
	{ "aad",    &instruction::decode_Ib,      OP_AAD,   FLAG_32BIT_ONLY | FLAG_W_FLAGS }, // ia-32 only
	{ "salc",   &instruction::decode0,        OP_SALC,  FLAG_UNDOCUMENTED | FLAG_R_FLAGS },
	{ "xlat",   &instruction::decode0,        OP_XLAT,  FLAG_NONE },
	{ "esc0",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc1",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc2",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc3",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc4",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc5",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc6",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },
	{ "esc7",   &instruction::decode_x87,     OP_FPU,   FLAG_NONE },

	/* 0xe0 - 0xef */
	{ "loopne",           &instruction::decode_Jb,               OP_LOOPNE, FLAG_R_FLAGS },
	{ "loope",            &instruction::decode_Jb,               OP_LOOPE,  FLAG_R_FLAGS },
	{ "loop",             &instruction::decode_Jb,               OP_LOOP,   FLAG_R_FLAGS },
	{ "jcxz/jecxz/jrcxz", &instruction::decode_jcxz_jecxz_jrcxz, OP_GROUP,  FLAG_NONE },
	{ "in",               &instruction::decode_AL_Ib,            OP_IN,     FLAG_NONE },
	{ "in",               &instruction::decode_eAX_Ib,           OP_IN,     FLAG_NONE },
	{ "out",              &instruction::decode_Ib_AL,            OP_OUT,    FLAG_NONE },
	{ "out",              &instruction::decode_Ib_eAX,           OP_OUT,    FLAG_NONE },
	{ "call",             &instruction::decode_Jz,               OP_CALL,   FLAG_STACK },
	{ "jmp",              &instruction::decode_Jz,               OP_JMP,    FLAG_NONE },
	{ "jmp",              &instruction::decode_Ap,               OP_JMP,    FLAG_32BIT_ONLY }, // ia-32 only
	{ "jmp",              &instruction::decode_Jb,               OP_JMP,    FLAG_NONE },
	{ "in",               &instruction::decode_AL_DX,            OP_IN,     FLAG_NONE },
	{ "in",               &instruction::decode_eAX_DX,           OP_IN,     FLAG_NONE },
	{ "out",              &instruction::decode_DX_AL,            OP_OUT,    FLAG_NONE },
	{ "out",              &instruction::decode_DX_eAX,           OP_OUT,    FLAG_NONE },

	/* 0xf0 - 0xff */
	{ "prefix lock",  &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "invalid",      &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "prefix repne", &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "prefix rep",   &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "hlt",          &instruction::decode0,        OP_HLT,     FLAG_RING0 },
	{ "cmc",          &instruction::decode0,        OP_CMC,     FLAG_RW_FLAGS },
	{ "group3",       &instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "group3",       &instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "clc",          &instruction::decode0,        OP_CLC,     FLAG_W_FLAGS },
	{ "stc",          &instruction::decode0,        OP_STC,     FLAG_W_FLAGS },
	{ "cli",          &instruction::decode0,        OP_CLI,     FLAG_W_FLAGS },
	{ "sti",          &instruction::decode0,        OP_STI,     FLAG_W_FLAGS },
	{ "cld",          &instruction::decode0,        OP_CLD,     FLAG_W_FLAGS },
	{ "std",          &instruction::decode0,        OP_STD,     FLAG_W_FLAGS },
	{ "group4",       &instruction::decode_group4,  OP_GROUP,   FLAG_NONE },
	{ "group5",       &instruction::decode_group5,  OP_GROUP,   FLAG_NONE },
};

}

#endif
