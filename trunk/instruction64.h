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

#include "instruction.h"

#ifndef INSTRUCTION64_20070427_TCC_
#define INSTRUCTION64_20070427_TCC_

namespace edisassm {

template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_cmpsw_cmpsd_cmpsq[3] = {
	{ "cmpsw",  &instruction::decode0, OP_CMPS, FLAG_RW_FLAGS },
	{ "cmpsd",  &instruction::decode0, OP_CMPS, FLAG_RW_FLAGS },
	{ "cmpsq",  &instruction::decode0, OP_CMPS, FLAG_RW_FLAGS | FLAG_64BIT_ONLY }, // x86: invalid
};

template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_Group7A[64] = {
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "vmcall",   &instruction::decode0,        OP_VMCALL,   FLAG_VMX },
	{ "vmlaunch", &instruction::decode0,        OP_VMLAUNCH, FLAG_VMX },
	{ "vmresume", &instruction::decode0,        OP_VMRESUME, FLAG_VMX },
	{ "vmxoff",   &instruction::decode0,        OP_VMXOFF,   FLAG_VMX },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	
	{ "monitor", &instruction::decode0,        OP_MONITOR, FLAG_SSE3 },
	{ "mwait",   &instruction::decode0,        OP_MWAIT,   FLAG_SSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "xgetbv", &instruction::decode0,         OP_XGETBV,  FLAG_NONE },
	{ "xsetbv", &instruction::decode0,         OP_XSETBV,  FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "vmrun",   &instruction::decode0, OP_VMRUN,   FLAG_AMD },
	{ "vmmcall", &instruction::decode0, OP_VMMCALL, FLAG_AMD },
	{ "vmload",  &instruction::decode0, OP_VMLOAD,  FLAG_AMD },
	{ "vmsave",  &instruction::decode0, OP_VMSAVE,  FLAG_AMD },
	{ "stgi",    &instruction::decode0, OP_STGI,    FLAG_AMD },
	{ "clgi",    &instruction::decode0, OP_CLGI,    FLAG_AMD },
	{ "skinit",  &instruction::decode0, OP_SKINIT,  FLAG_AMD },
	{ "invlpga", &instruction::decode0, OP_INVLPGA, FLAG_AMD },

	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },

	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &instruction::decode_Ew, OP_LMSW, FLAG_NONE },

	{ "swapgs",  &instruction::decode0,        OP_SWAPGS,  FLAG_NONE }, // x86: invalid
	{ "rdtscp",  &instruction::decode0,        OP_RDTSCP,  FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes[0x100] = {

	/* 0x00 - 0x0f */
	{ "add",     &instruction::decode_Eb_Gb,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &instruction::decode_Ev_Gv,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &instruction::decode_Gb_Eb,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &instruction::decode_Gv_Ev,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &instruction::decode_AL_Ib,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &instruction::decode_rAX_Iz,  OP_ADD,     FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "or",      &instruction::decode_Eb_Gb,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &instruction::decode_Ev_Gv,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &instruction::decode_Gb_Eb,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &instruction::decode_Gv_Ev,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &instruction::decode_AL_Ib,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &instruction::decode_rAX_Iz,  OP_OR,      FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "2byte",   &instruction::decode_2byte,   OP_2BYTE,   FLAG_NONE },

	/* 0x10 - 0x1f */
	{ "adc", &instruction::decode_Eb_Gb, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &instruction::decode_Ev_Gv, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &instruction::decode_Gb_Eb, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &instruction::decode_Gv_Ev, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &instruction::decode_AL_Ib, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &instruction::decode_rAX_Iz, OP_ADC, FLAG_RW_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "sbb", &instruction::decode_Eb_Gb, OP_SBB, FLAG_NONE },
	{ "sbb", &instruction::decode_Ev_Gv, OP_SBB, FLAG_NONE },
	{ "sbb", &instruction::decode_Gb_Eb, OP_SBB, FLAG_NONE },
	{ "sbb", &instruction::decode_Gv_Ev, OP_SBB, FLAG_NONE },
	{ "sbb", &instruction::decode_AL_Ib, OP_SBB, FLAG_NONE },
	{ "sbb", &instruction::decode_rAX_Iz, OP_SBB, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x20 - 0x2f */
	{ "and", &instruction::decode_Eb_Gb, OP_AND, FLAG_W_FLAGS },
	{ "and", &instruction::decode_Ev_Gv, OP_AND, FLAG_W_FLAGS },
	{ "and", &instruction::decode_Gb_Eb, OP_AND, FLAG_W_FLAGS },
	{ "and", &instruction::decode_Gv_Ev, OP_AND, FLAG_W_FLAGS },
	{ "and", &instruction::decode_AL_Ib, OP_AND, FLAG_W_FLAGS },
	{ "and", &instruction::decode_rAX_Iz, OP_AND, FLAG_W_FLAGS },
	{ "prefix es", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "sub", &instruction::decode_Eb_Gb, OP_SUB, FLAG_NONE },
	{ "sub", &instruction::decode_Ev_Gv, OP_SUB, FLAG_NONE },
	{ "sub", &instruction::decode_Gb_Eb, OP_SUB, FLAG_NONE },
	{ "sub", &instruction::decode_Gv_Ev, OP_SUB, FLAG_NONE },
	{ "sub", &instruction::decode_AL_Ib, OP_SUB, FLAG_NONE },
	{ "sub", &instruction::decode_rAX_Iz, OP_SUB, FLAG_NONE },
	{ "prefix cs", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x30 - 0x3f */
	{ "xor", &instruction::decode_Eb_Gb, OP_XOR, FLAG_NONE },
	{ "xor", &instruction::decode_Ev_Gv, OP_XOR, FLAG_NONE },
	{ "xor", &instruction::decode_Gb_Eb, OP_XOR, FLAG_NONE },
	{ "xor", &instruction::decode_Gv_Ev, OP_XOR, FLAG_NONE },
	{ "xor", &instruction::decode_AL_Ib, OP_XOR, FLAG_NONE },
	{ "xor", &instruction::decode_rAX_Iz, OP_XOR, FLAG_NONE },
	{ "prefix ss", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "cmp", &instruction::decode_Eb_Gb, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &instruction::decode_Ev_Gv, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &instruction::decode_Gb_Eb, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &instruction::decode_Gv_Ev, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &instruction::decode_AL_Ib, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &instruction::decode_rAX_Iz, OP_CMP, FLAG_W_FLAGS },
	{ "prefix ds", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x40 - 0x4f */
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)

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
	{ "invalid",       &instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",       &instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",       &instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "movsxd",        &instruction::decode_Gv_Ev,               OP_MOVSXD,  FLAG_NONE }, // x86: arpl Ew,Gw
	{ "prefix fs",     &instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix gs",     &instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix data16", &instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix addr16", &instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "push",          &instruction::decode_Iz,                  OP_PUSH,    FLAG_STACK },
	{ "imul",          &instruction::decode_Gv_Ev_Iz,            OP_IMUL,    FLAG_W_FLAGS },
	{ "push",          &instruction::decode_Ib,                  OP_PUSH,    FLAG_STACK },
	{ "imul",          &instruction::decode_Gv_Ev_Ib,            OP_IMUL,    FLAG_W_FLAGS },
	{ "insb",          &instruction::decode0,                    OP_INS,     FLAG_NONE },
	{ "insw/insd",     &instruction::decode_insw_insd_invalid,   OP_GROUP,   FLAG_NONE },
	{ "outsb",         &instruction::decode0,                    OP_OUTS,    FLAG_NONE },
	{ "outsw/outsd",   &instruction::decode_outsw_outsd_invalid, OP_GROUP,   FLAG_NONE },

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
	{ "group1",  &instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "group1",  &instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "group1",  &instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "test",    &instruction::decode_Eb_Gb,   OP_TEST,    FLAG_NONE },
	{ "test",    &instruction::decode_Ev_Gv,   OP_TEST,    FLAG_NONE },
	{ "xchg",    &instruction::decode_Gb_Eb,   OP_XCHG,    FLAG_NONE },
	{ "xchg",    &instruction::decode_Gv_Ev,   OP_XCHG,    FLAG_NONE },
	{ "mov",     &instruction::decode_Eb_Gb,   OP_MOV,     FLAG_NONE },
	{ "mov",     &instruction::decode_Ev_Gv,   OP_MOV,     FLAG_NONE },
	{ "mov",     &instruction::decode_Gb_Eb,   OP_MOV,     FLAG_NONE },
	{ "mov",     &instruction::decode_Gv_Ev,   OP_MOV,     FLAG_NONE },
	{ "mov",     &instruction::decode_Ev_Sw,   OP_MOV,     FLAG_NONE },
	{ "lea",     &instruction::decode_Gv_M,    OP_LEA,     FLAG_NONE },
	{ "mov",     &instruction::decode_Sw_Ew,   OP_MOV,     FLAG_NONE },
	{ "group10", &instruction::decode_group10, OP_GROUP,   FLAG_NONE },

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
	{ "invalid",              &instruction::decode_invalid,              OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "wait",                 &instruction::decode0,                     OP_WAIT,    FLAG_NONE },
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
	{ "test",              &instruction::decode_AL_Ib,             OP_TEST,  FLAG_NONE },
	{ "test",              &instruction::decode_rAX_Iz,            OP_TEST,  FLAG_NONE },
	{ "stosb",             &instruction::decode0,                  OP_STOS,  FLAG_NONE },
	{ "stosw/stosd/stosq", &instruction::decode_stosw_stosd_stosq, OP_GROUP, FLAG_NONE },
	{ "lodsb",             &instruction::decode0,                  OP_LODS,  FLAG_R_FLAGS },
	{ "lodsw/lodsd/lodsq", &instruction::decode_lodsw_lodsd_lodsq, OP_GROUP, FLAG_NONE },
	{ "scasb",             &instruction::decode0,                  OP_SCAS,  FLAG_NONE },
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
	{ "group2",           &instruction::decode_group2,           OP_GROUP,   FLAG_NONE },
	{ "group2",           &instruction::decode_group2,           OP_GROUP,   FLAG_NONE },
	{ "ret",              &instruction::decode_Iw,               OP_RET,     FLAG_NONE },
	{ "ret",              &instruction::decode0,                 OP_RET,     FLAG_NONE },
	{ "invalid",          &instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",          &instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "group12",          &instruction::decode_group12,          OP_GROUP,   FLAG_NONE },
	{ "group12",          &instruction::decode_group12,          OP_GROUP,   FLAG_NONE },
	{ "enter",            &instruction::decode_Iw_Ib,            OP_ENTER,   FLAG_STACK },
	{ "leave",            &instruction::decode0,                 OP_LEAVE,   FLAG_STACK },
	{ "retf",             &instruction::decode_Iw,               OP_RETF,    FLAG_NONE },
	{ "retf",             &instruction::decode0,                 OP_RETF,    FLAG_NONE },
	{ "int3",             &instruction::decode0,                 OP_INT3,    FLAG_W_FLAGS },
	{ "int",              &instruction::decode_Ib,               OP_INT,     FLAG_W_FLAGS },
	{ "invalid",          &instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "iretw/iret/iretq", &instruction::decode_iretw_iret_iretq, OP_GROUP,   FLAG_NONE },

	/* 0xd0 - 0xdf */
	{ "group2",  &instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID,  FLAG_NONE }, // ia-32 only
	{ "invalid", &instruction::decode_invalid, OP_INVALID,  FLAG_NONE }, // ia-32 only
	{ "invalid", &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "xlat",    &instruction::decode0,        OP_XLAT,     FLAG_NONE },
	{ "esc0",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc1",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc2",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc3",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc4",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc5",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc6",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc7",    &instruction::decode_x87,     OP_FPU,      FLAG_NONE },

	/* 0xe0 - 0xef */
	{ "loopne",           &instruction::decode_Jb,               OP_LOOPNE,  FLAG_R_FLAGS },
	{ "loope",            &instruction::decode_Jb,               OP_LOOPE,   FLAG_R_FLAGS },
	{ "loop",             &instruction::decode_Jb,               OP_LOOP,    FLAG_R_FLAGS },
	{ "jcxz/jecxz/jrcxz", &instruction::decode_jcxz_jecxz_jrcxz, OP_GROUP,   FLAG_NONE },
	{ "in",               &instruction::decode_AL_Ib,            OP_IN,      FLAG_NONE },
	{ "in",               &instruction::decode_eAX_Ib,           OP_IN,      FLAG_NONE },
	{ "out",              &instruction::decode_Ib_AL,            OP_OUT,     FLAG_NONE },
	{ "out",              &instruction::decode_Ib_eAX,           OP_OUT,     FLAG_NONE },
	{ "call",             &instruction::decode_Jz,               OP_CALL,    FLAG_STACK },
	{ "jmp",              &instruction::decode_Jz,               OP_JMP,     FLAG_NONE },
	{ "invalid",          &instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "jmp",              &instruction::decode_Jb,               OP_JMP,     FLAG_NONE },
	{ "in",               &instruction::decode_AL_DX,            OP_IN,      FLAG_NONE },
	{ "in",               &instruction::decode_eAX_DX,           OP_IN,      FLAG_NONE },
	{ "out",              &instruction::decode_DX_AL,            OP_OUT,     FLAG_NONE },
	{ "out",              &instruction::decode_DX_eAX,           OP_OUT,     FLAG_NONE },

	/* 0xf0 - 0xff */
	{ "prefix lock",  &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "invalid",      &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "prefix repne", &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "prefix rep",   &instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "hlt",          &instruction::decode0,        OP_HLT,     FLAG_NONE },
	{ "cmc",          &instruction::decode0,        OP_CMC,     FLAG_RW_FLAGS },
	{ "group3",       &instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "group3",       &instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "clc",          &instruction::decode0,        OP_CLC,     FLAG_W_FLAGS },
	{ "stc",          &instruction::decode0,        OP_STC,     FLAG_NONE },
	{ "cli",          &instruction::decode0,        OP_CLI,     FLAG_W_FLAGS },
	{ "sti",          &instruction::decode0,        OP_STI,     FLAG_NONE },
	{ "cld",          &instruction::decode0,        OP_CLD,     FLAG_W_FLAGS },
	{ "std",          &instruction::decode0,        OP_STD,     FLAG_NONE },
	{ "group4",       &instruction::decode_group4,  OP_GROUP,   FLAG_NONE },
	{ "group5",       &instruction::decode_group5,  OP_GROUP,   FLAG_NONE },
};


template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_2Byte_NA[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movups",   &instruction::decode_Vo_Wo,   OP_MOVUPS,   FLAG_SSE },
	{ "movups",   &instruction::decode_Wo_Vo,   OP_MOVUPS,   FLAG_SSE },
	{ "movlps",   &instruction::decode_Vq_Mq,   OP_MOVLPS,   FLAG_SSE }, // TODO: movhlps here too
	{ "movlps",   &instruction::decode_Mq_Vq,   OP_MOVLPS,   FLAG_SSE },
	{ "unpcklps", &instruction::decode_Vo_Wq,   OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &instruction::decode_Vo_Wq,   OP_UNPCKHPS, FLAG_SSE },
	{ "movhps",   &instruction::decode_Vq_Mq,   OP_MOVHPS,   FLAG_SSE },  // TODO: movlhps here too
	{ "movhps",   &instruction::decode_Mq_Vq,   OP_MOVHPS,   FLAG_SSE },
	{ "group17",  &instruction::decode_group17, OP_GROUP,    FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "nop",      &instruction::decode_Ev,      OP_NOP,      FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov",        &instruction::decode_Rd_Cd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Rd_Dd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Cd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Dd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movaps",     &instruction::decode_Vo_Wo,   OP_MOVAPS,    FLAG_SSE },
	{ "movaps",     &instruction::decode_Wo_Vo,   OP_MOVAPS,    FLAG_SSE },
	{ "cvtpi2ps",   &instruction::decode_Vo_Qq,   OP_CVTPI2PS,  FLAG_SSE },
	{ "movntps",    &instruction::decode_Mo_Vo,   OP_MOVNTPS,   FLAG_SSE },
	{ "cvttps2pi",  &instruction::decode_Pq_Wo,   OP_CVTTPS2PI, FLAG_SSE },
	{ "cvtps2pi",   &instruction::decode_Pq_Wo,   OP_CVTPS2PI,  FLAG_SSE },
	{ "ucomiss",    &instruction::decode_Vo_Wo,   OP_UCOMISS,   FLAG_SSE | FLAG_W_FLAGS },
	{ "comiss",     &instruction::decode_Vo_Wo,   OP_COMISS,    FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr",    &instruction::decode0,         OP_WRMSR,    FLAG_NONE },
	{ "rdtsc",    &instruction::decode0,         OP_RDTSC,    FLAG_NONE },
	{ "rdmsr",    &instruction::decode0,         OP_RDMSR,    FLAG_NONE },
	{ "rdpmc",    &instruction::decode0,         OP_RDPMC,    FLAG_NONE },
	{ "sysenter", &instruction::decode0,         OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit",  &instruction::decode0,         OP_SYSEXIT,  FLAG_PENTIUM_PRO },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "getsec",   &instruction::decode0,         OP_GETSEC,   FLAG_NONE },
	{ "3byte",    &instruction::decode_3byte_38, OP_3BYTE,    FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "3byte",    &instruction::decode_3byte_3A, OP_3BYTE,    FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtps",   &instruction::decode_Vo_Wo, OP_SQRTPS,   FLAG_SSE },
	{ "rsqrtps",  &instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andps",    &instruction::decode_Vo_Wo, OP_ANDPS,    FLAG_SSE },
	{ "andnps",   &instruction::decode_Vo_Wo, OP_ANDNPS,   FLAG_SSE },
	{ "orps",     &instruction::decode_Vo_Wo, OP_ORPS,     FLAG_SSE },
	{ "xorps",    &instruction::decode_Vo_Wo, OP_XORPS,    FLAG_SSE },
	{ "addps",    &instruction::decode_Vo_Wo, OP_ADDPS,    FLAG_SSE },
	{ "mulps",    &instruction::decode_Vo_Wo, OP_MULPS,    FLAG_SSE },
	{ "cvtps2pd", &instruction::decode_Vo_Wo, OP_CVTPS2PD, FLAG_SSE2 },
	{ "cvtdq2ps", &instruction::decode_Vo_Wo, OP_CVTDQ2PS, FLAG_SSE2 },
	{ "subps",    &instruction::decode_Vo_Wo, OP_SUBPS,    FLAG_SSE },
	{ "minps",    &instruction::decode_Vo_Wo, OP_MINPS,    FLAG_SSE },
	{ "divps",    &instruction::decode_Vo_Wo, OP_DIVPS,    FLAG_SSE },
	{ "maxps",    &instruction::decode_Vo_Wo, OP_MAXPS,    FLAG_SSE },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &instruction::decode_Pq_Qd,   OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &instruction::decode_Pq_Qd,   OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &instruction::decode_Pq_Qd,   OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb",  &instruction::decode_Pq_Qq,   OP_PACKSSWB,  FLAG_MMX },
	{ "pcmpgtb",   &instruction::decode_Pq_Qq,   OP_PCMPGTB,   FLAG_MMX },
	{ "pcmpgtw",   &instruction::decode_Pq_Qq,   OP_PCMPGTW,   FLAG_MMX },
	{ "pcmpgtd",   &instruction::decode_Pq_Qq,   OP_PCMPGTD,   FLAG_MMX },
	{ "packuswb",  &instruction::decode_Pq_Qq,   OP_PACKUSWB,  FLAG_MMX },
	{ "punpckhbw", &instruction::decode_Pq_Qd,   OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &instruction::decode_Pq_Qd,   OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &instruction::decode_Pq_Qd,   OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw",  &instruction::decode_Pq_Qq,   OP_PACKSSDW,  FLAG_MMX },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movq",      &instruction::decode_Pd_Eq,   OP_MOVQ,      FLAG_MMX }, // x86: movd Pd, Ed
	{ "movq",      &instruction::decode_Pq_Qq,   OP_MOVQ,      FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufw", &instruction::decode_Pq_Qq_Ib, OP_PSHUFW, FLAG_SSE },
	{ "group13", &instruction::decode_group13, OP_GROUP, FLAG_NONE },
	{ "group14", &instruction::decode_group14, OP_GROUP, FLAG_NONE },
	{ "group15", &instruction::decode_group15, OP_GROUP, FLAG_NONE },
	{ "pcmpeqb", &instruction::decode_Pq_Qq, OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &instruction::decode_Pq_Qq, OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &instruction::decode_Pq_Qq, OP_PCMPEQD, FLAG_MMX },
	{ "emms", &instruction::decode0, OP_EMMS, FLAG_MMX },
	{ "vmread", &instruction::decode_Eq_Gq, OP_VMREAD, FLAG_VMX },   // x86: vmread Ed, Gq
	{ "vmwrite", &instruction::decode_Gq_Eq, OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &instruction::decode_Eq_Pd, OP_MOVQ, FLAG_MMX },       // x86: movq Ed,Pd
	{ "movq", &instruction::decode_Qq_Pq, OP_MOVQ, FLAG_MMX },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &instruction::decode_Eb_Gb,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &instruction::decode_Ev_Gv,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss",     &instruction::decode_Gv_Mp,   OP_LSS,     FLAG_NONE },
	{ "btr",     &instruction::decode_Ev_Gv,   OP_BTR,     FLAG_W_FLAGS },
	{ "lfs",     &instruction::decode_Gv_Mp,   OP_LFS,     FLAG_NONE },
	{ "lgs",     &instruction::decode_Gv_Mp,   OP_LGS,     FLAG_NONE },
	{ "movzx",   &instruction::decode_Gv_Eb,   OP_MOVZX,   FLAG_NONE },
	{ "movzx",   &instruction::decode_Gv_Ew,   OP_MOVZX,   FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &instruction::decode_group11, OP_GROUP,   FLAG_NONE },
	{ "group8",  &instruction::decode_group8,  OP_GROUP,   FLAG_NONE },
	{ "btc",     &instruction::decode_Ev_Gv,   OP_BTC,     FLAG_W_FLAGS },
	{ "bsf",     &instruction::decode_Gv_Ev,   OP_BSF,     FLAG_W_FLAGS },
	{ "bsr",     &instruction::decode_Gv_Ev,   OP_BSR,     FLAG_W_FLAGS },
	{ "movsx",   &instruction::decode_Gv_Eb,   OP_MOVSX,   FLAG_NONE },
	{ "movsx",   &instruction::decode_Gv_Ew,   OP_MOVSX,   FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd",   &instruction::decode_Eb_Gb,       OP_XADD,   FLAG_NONE },
	{ "xadd",   &instruction::decode_Ev_Gv,       OP_XADD,   FLAG_NONE },
	{ "cmpps",  &instruction::decode_Vo_Wo_Ib,    OP_CMPPS,  FLAG_SSE },
	{ "movnti", &instruction::decode_Nq_Gq,       OP_MOVNTI, FLAG_SSE2 }, // x86: movnti Md, Gd
	{ "pinsrw", &instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &instruction::decode_Gd_Nq_Ib,    OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &instruction::decode_Vo_Wo_Ib,    OP_SHUFPS, FLAG_SSE },
	{ "group9", &instruction::decode_group9,      OP_GROUP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rAX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rCX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rDX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rBX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rSP,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rBP,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rSI,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &instruction::decode_rDI,         OP_BSWAP,  FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "psrlw",    &instruction::decode_Pq_Qq,   OP_PSRLW,    FLAG_MMX },
	{ "psrld",    &instruction::decode_Pq_Qq,   OP_PSRLD,    FLAG_NONE },
	{ "psrlq",    &instruction::decode_Pq_Qq,   OP_PSRLQ,    FLAG_MMX },
	{ "paddq",    &instruction::decode_Pq_Qq,   OP_PADDQ,    FLAG_SSE2 },
	{ "pmullw",   &instruction::decode_Pq_Qq,   OP_PMULLW,   FLAG_MMX },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pmovmskb", &instruction::decode_Gd_Nq,   OP_PMOVMSKB, FLAG_SSE },
    { "psubusb",  &instruction::decode_Pq_Qq,   OP_PSUBUSB,  FLAG_MMX },
    { "psubusw",  &instruction::decode_Pq_Qq,   OP_PSUBUSW,  FLAG_MMX },
    { "pminub",   &instruction::decode_Pq_Qq,   OP_PMINUB,   FLAG_SSE },
    { "pand",     &instruction::decode_Pq_Qq,   OP_PAND,     FLAG_MMX },
    { "paddusb",  &instruction::decode_Pq_Qq,   OP_PADDUSB,  FLAG_MMX },
    { "paddusw",  &instruction::decode_Pq_Qq,   OP_PADDUSW,  FLAG_MMX },
    { "pmaxub",   &instruction::decode_Pq_Qq,   OP_PMAXUB,   FLAG_SSE },
    { "pandn",    &instruction::decode_Pq_Qq,   OP_PANDN,    FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb",   &instruction::decode_Pq_Qq,   OP_PAVGB,   FLAG_SSE },
	{ "psraw",   &instruction::decode_Pq_Qq,   OP_PSRAW,   FLAG_MMX },
	{ "psrad",   &instruction::decode_Pq_Qq,   OP_PSRAD,   FLAG_MMX },
	{ "pavgw",   &instruction::decode_Pq_Qq,   OP_PAVGW,   FLAG_SSE },
	{ "pmulhuw", &instruction::decode_Pq_Qq,   OP_PMULHUW, FLAG_SSE },
	{ "pmulhw",  &instruction::decode_Pq_Qq,   OP_PMULHW,  FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movntq",  &instruction::decode_Mq_Pq,   OP_MOVNTQ,  FLAG_SSE },
	{ "psubsb",  &instruction::decode_Pq_Qq,   OP_PSUBSB,  FLAG_MMX },
	{ "psubsw",  &instruction::decode_Pq_Qq,   OP_PSUBSW,  FLAG_MMX },
	{ "pminsw",  &instruction::decode_Pq_Qq,   OP_PMINSW,  FLAG_SSE },
	{ "por",     &instruction::decode_Pq_Qq,   OP_POR,     FLAG_MMX },
	{ "paddsb",  &instruction::decode_Pq_Qq,   OP_PADDSB,  FLAG_MMX },
	{ "paddsw",  &instruction::decode_Pq_Qq,   OP_PADDSW,  FLAG_MMX },
	{ "pmaxsw",  &instruction::decode_Pq_Qq,   OP_PMAXSW,  FLAG_SSE },
	{ "pxor",    &instruction::decode_Pq_Qq,   OP_PXOR,    FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};


// 2 byte opcodes with a 66 prefix
template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_2Byte_66[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movupd",   &instruction::decode_Vo_Wo,   OP_MOVUPD,   FLAG_SSE2 },
	{ "movupd",   &instruction::decode_Wo_Vo,   OP_MOVUPD,   FLAG_SSE2 },
	{ "movlpd",   &instruction::decode_Vq_Mq,   OP_MOVLPD,   FLAG_SSE2 },
	{ "movlpd",   &instruction::decode_Mq_Vq,   OP_MOVLPD,   FLAG_SSE2 },
	{ "unpcklpd", &instruction::decode_Vo_Wq,   OP_UNPCKLPD, FLAG_SSE2 },
	{ "unpckhpd", &instruction::decode_Vo_Wq,   OP_UNPCKHPD, FLAG_SSE2 },
	{ "movhpd",   &instruction::decode_Vq_Mq,   OP_MOVHPD,   FLAG_SSE2 },
	{ "movhpd",   &instruction::decode_Mq_Vq,   OP_MOVHPD,   FLAG_SSE2 },
	{ "group17",  &instruction::decode_group17, OP_GROUP,    FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "nop",      &instruction::decode_Ev,      OP_NOP,      FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov",        &instruction::decode_Rd_Cd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Rd_Dd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Cd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &instruction::decode_Dd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movapd",     &instruction::decode_Vo_Wo,   OP_MOVAPD,    FLAG_SSE2 },
	{ "movapd",     &instruction::decode_Wo_Vo,   OP_MOVAPD,    FLAG_SSE2 },
	{ "cvtpi2pd",   &instruction::decode_Vo_Qq,   OP_CVTPI2PD,  FLAG_SSE2 },
	{ "movntpd",    &instruction::decode_Mo_Vo,   OP_MOVNTPD,   FLAG_SSE2 },
	{ "cvttpd2pi",  &instruction::decode_Pq_Wo,   OP_CVTTPD2PI, FLAG_SSE2 },
	{ "cvtpd2pi",   &instruction::decode_Qq_Wo,   OP_CVTPD2PI,  FLAG_SSE2 },
	{ "ucomisd",    &instruction::decode_Vo_Wo,   OP_UCOMISD,   FLAG_SSE2 },
	{ "comisd",     &instruction::decode_Vo_Wo,   OP_COMISD,    FLAG_SSE2 | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskpd", &instruction::decode_Gq_Uo, OP_MOVMSKPD, FLAG_SSE2 }, // x86: movmskpd Gd, Uo
	{ "sqrtpd",   &instruction::decode_Vo_Wo, OP_SQRTPD,   FLAG_SSE2 },
	{ "rsqrtps",  &instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andpd",    &instruction::decode_Vo_Wo, OP_ANDPD,    FLAG_SSE2 },
	{ "andnpd",   &instruction::decode_Vo_Wo, OP_ANDNPD,   FLAG_SSE2 },
	{ "orpd",     &instruction::decode_Vo_Wo, OP_ORPD,     FLAG_SSE2 },
	{ "xorpd",    &instruction::decode_Vo_Wo, OP_XORPD,    FLAG_SSE2 },
	{ "addpd",    &instruction::decode_Vo_Wo, OP_ADDPD,    FLAG_SSE2 },
	{ "mulpd",    &instruction::decode_Vo_Wo, OP_MULPD,    FLAG_SSE2 },
	{ "cvtpd2ps", &instruction::decode_Vo_Wo, OP_CVTPD2PS, FLAG_SSE2 },
	{ "cvtps2dq", &instruction::decode_Vo_Wo, OP_CVTPS2DQ, FLAG_SSE2 },
	{ "subpd",    &instruction::decode_Vo_Wo, OP_SUBPD,    FLAG_SSE2 },
	{ "minpd",    &instruction::decode_Vo_Wo, OP_MINPD,    FLAG_SSE2 },
	{ "divpd",    &instruction::decode_Vo_Wo, OP_DIVPD,    FLAG_SSE2 },
	{ "maxpd",    &instruction::decode_Vo_Wo, OP_MAXPD,    FLAG_SSE2 },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw",  &instruction::decode_Vo_Wo, OP_PUNPCKLBW,  FLAG_MMX },
	{ "punpcklwd",  &instruction::decode_Vo_Wo, OP_PUNPCKLWD,  FLAG_MMX },
	{ "punpckldq",  &instruction::decode_Vo_Wo, OP_PUNPCKLDQ,  FLAG_MMX },
	{ "packsswb",   &instruction::decode_Vo_Wo, OP_PACKSSWB,   FLAG_MMX },
	{ "pcmpgtb",    &instruction::decode_Vo_Wo, OP_PCMPGTB,    FLAG_MMX },
	{ "pcmpgtw",    &instruction::decode_Vo_Wo, OP_PCMPGTW,    FLAG_MMX },
	{ "pcmpgtd",    &instruction::decode_Vo_Wo, OP_PCMPGTD,    FLAG_MMX },
	{ "packuswb",   &instruction::decode_Vo_Wo, OP_PACKUSWB,   FLAG_MMX },
	{ "punpckhbw",  &instruction::decode_Vo_Wo, OP_PUNPCKHBW,  FLAG_MMX },
	{ "punpckhwd",  &instruction::decode_Vo_Wo, OP_PUNPCKHWD,  FLAG_MMX },
	{ "punpckhdq",  &instruction::decode_Vo_Wo, OP_PUNPCKHDQ,  FLAG_MMX },
	{ "packssdw",   &instruction::decode_Vo_Wo, OP_PACKSSDW,   FLAG_MMX },
	{ "punpcklqdq", &instruction::decode_Vo_Wo, OP_PUNPCKLQDQ, FLAG_SSE2 },
	{ "punpckhqdq", &instruction::decode_Vo_Wo, OP_PUNPCKHQDQ, FLAG_SSE2 },
	{ "movq",       &instruction::decode_Vo_Eq, OP_MOVQ,       FLAG_MMX }, // x86: movd Vo, Ed
	{ "movq",       &instruction::decode_Vo_Qq, OP_MOVQ,       FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufd",  &instruction::decode_Vo_Wo_Ib, OP_PSHUFD,  FLAG_SSE2 },
	{ "group13", &instruction::decode_group13,  OP_GROUP,   FLAG_NONE },
	{ "group14", &instruction::decode_group14,  OP_GROUP,   FLAG_NONE },
	{ "group15", &instruction::decode_group15,  OP_GROUP,   FLAG_NONE },
	{ "pcmpeqb", &instruction::decode_Vo_Wo,    OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &instruction::decode_Vo_Wo,    OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &instruction::decode_Vo_Wo,    OP_PCMPEQD, FLAG_MMX },
	{ "emms",    &instruction::decode0,         OP_EMMS,    FLAG_MMX },
	{ "vmread",  &instruction::decode_Eq_Gq,    OP_VMREAD,  FLAG_VMX }, // x86: vmread Ed, Gd
	{ "vmwrite", &instruction::decode_Gq_Eq,    OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "haddpd",  &instruction::decode_Vo_Wo,    OP_HADDPD,  FLAG_SSE3 },
	{ "hsubpd",  &instruction::decode_Vo_Wo,    OP_HSUBPD,  FLAG_SSE3 },
	{ "movq",    &instruction::decode_Eq_Vo,    OP_MOVD,    FLAG_MMX }, // x86: movd Ed, Vo
	{ "movdqa",  &instruction::decode_Wo_Vo,    OP_MOVDQA,  FLAG_SSE2 },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &instruction::decode_Eb_Gb,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &instruction::decode_Ev_Gv,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss",     &instruction::decode_Gv_Mp,   OP_LSS,     FLAG_NONE },
	{ "btr",     &instruction::decode_Ev_Gv,   OP_BTR,     FLAG_W_FLAGS },
	{ "lfs",     &instruction::decode_Gv_Mp,   OP_LFS,     FLAG_NONE },
	{ "lgs",     &instruction::decode_Gv_Mp,   OP_LGS,     FLAG_NONE },
	{ "movzx",   &instruction::decode_Gv_Eb,   OP_MOVZX,   FLAG_NONE },
	{ "movzx",   &instruction::decode_Gv_Ew,   OP_MOVZX,   FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &instruction::decode_group11, OP_GROUP,   FLAG_NONE },
	{ "group8",  &instruction::decode_group8,  OP_GROUP,   FLAG_NONE },
	{ "btc",     &instruction::decode_Ev_Gv,   OP_BTC,     FLAG_W_FLAGS },
	{ "bsf",     &instruction::decode_Gv_Ev,   OP_BSF,     FLAG_W_FLAGS },
	{ "bsr",     &instruction::decode_Gv_Ev,   OP_BSR,     FLAG_W_FLAGS },
	{ "movsx",   &instruction::decode_Gv_Eb,   OP_MOVSX,   FLAG_NONE },
	{ "movsx",   &instruction::decode_Gv_Ew,   OP_MOVSX,   FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmppd", &instruction::decode_Vo_Wo_Ib, OP_CMPPD, FLAG_SSE2 },
	{ "movnti", &instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &instruction::decode_Vo_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Vo, Rd/Mw,Ib
	{ "pextrw", &instruction::decode_Gd_Uo_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufpd", &instruction::decode_Vo_Wo_Ib, OP_SHUFPD, FLAG_SSE2 },
	{ "group9", &instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubpd", &instruction::decode_Vo_Wo, OP_ADDSUBPD, FLAG_SSE3 },
	{ "psrlw", &instruction::decode_Vo_Wo, OP_PSRLW, FLAG_MMX },
	{ "psrld", &instruction::decode_Vo_Wo, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &instruction::decode_Vo_Wo, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &instruction::decode_Vo_Wo, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &instruction::decode_Vo_Wo, OP_PMULLW, FLAG_MMX },
	{ "movq", &instruction::decode_Vo_Wo, OP_MOVQ, FLAG_MMX },
	{ "pmovmskb", &instruction::decode_Gd_Uo, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &instruction::decode_Vo_Wo, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &instruction::decode_Vo_Wo, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &instruction::decode_Vo_Wo, OP_PMINUB, FLAG_SSE },
    { "pand", &instruction::decode_Vo_Wo, OP_PAND, FLAG_MMX },
    { "paddusb", &instruction::decode_Vo_Wo, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &instruction::decode_Vo_Wo, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &instruction::decode_Vo_Wo, OP_PMAXUB, FLAG_SSE },
    { "pandn", &instruction::decode_Vo_Wo, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &instruction::decode_Vo_Wo, OP_PAVGB, FLAG_SSE },
	{ "psraw", &instruction::decode_Vo_Wo, OP_PSRAW, FLAG_MMX },
	{ "psrad", &instruction::decode_Vo_Wo, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &instruction::decode_Vo_Wo, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &instruction::decode_Vo_Wo, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &instruction::decode_Vo_Wo, OP_PMULHW, FLAG_MMX },
	{ "cvttpd2dq", &instruction::decode_Vo_Wo, OP_CVTTPD2DQ, FLAG_SSE2 },
	{ "movntdq", &instruction::decode_Mo_Vo, OP_MOVNTDQ, FLAG_SSE2 },
	{ "psubsb", &instruction::decode_Vo_Wo, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &instruction::decode_Vo_Wo, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &instruction::decode_Vo_Wo, OP_PMINSW, FLAG_SSE },
	{ "por", &instruction::decode_Vo_Wo, OP_POR, FLAG_MMX },
	{ "paddsb", &instruction::decode_Vo_Wo, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &instruction::decode_Vo_Wo, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &instruction::decode_Vo_Wo, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &instruction::decode_Vo_Wo, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &instruction::decode_Vo_Wo, OP_PSLLW, FLAG_MMX },
	{ "pslld", &instruction::decode_Vo_Wo, OP_PSLLD, FLAG_MMX },
	{ "psllq", &instruction::decode_Vo_Wo, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &instruction::decode_Vo_Wo, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &instruction::decode_Vo_Wo, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &instruction::decode_Vo_Wo, OP_PSADBW, FLAG_SSE },
	{ "maskmovdqu", &instruction::decode_Vo_Uo, OP_MASKMOVDQU, FLAG_SSE2 },
	{ "psubb", &instruction::decode_Vo_Wo, OP_PSUBB, FLAG_MMX },
	{ "psubw", &instruction::decode_Vo_Wo, OP_PSUBW, FLAG_MMX },
	{ "psubd", &instruction::decode_Vo_Wo, OP_PSUBD, FLAG_MMX },
	{ "psubq", &instruction::decode_Vo_Wo, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &instruction::decode_Vo_Wo, OP_PADDB, FLAG_MMX },
	{ "paddw", &instruction::decode_Vo_Wo, OP_PADDW, FLAG_MMX },
	{ "paddd", &instruction::decode_Vo_Wo, OP_PADDD, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

// 2 byte opcodes with a f2 prefix
template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_2Byte_F2[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movsd", &instruction::decode_Vo_Wo, OP_MOVSD, FLAG_SSE2 },
	{ "movsd", &instruction::decode_Wo_Vo, OP_MOVSD, FLAG_SSE2 },
	{ "movddup", &instruction::decode_Vq_Mq, OP_MOVDDUP, FLAG_SSE3 },
	{ "movlps", &instruction::decode_Mq_Vq, OP_MOVLPS, FLAG_SSE },
	{ "unpcklps", &instruction::decode_Vo_Wq, OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &instruction::decode_Vo_Wq, OP_UNPCKHPS, FLAG_SSE },
	{ "movhps", &instruction::decode_Vq_Mq, OP_MOVHPS, FLAG_SSE },
	{ "movhps", &instruction::decode_Mq_Vq, OP_MOVHPS, FLAG_SSE },
	{ "group17", &instruction::decode_group17, OP_GROUP, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &instruction::decode_Ev, OP_NOP, FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &instruction::decode_Rd_Cd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Rd_Dd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Cd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Dd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movaps", &instruction::decode_Vo_Wo, OP_MOVAPS, FLAG_SSE },
	{ "movaps", &instruction::decode_Wo_Vo, OP_MOVAPS, FLAG_SSE },
	{ "cvtsi2sd", &instruction::decode_Vo_Eq, OP_CVTSI2SD, FLAG_SSE2 },    // x86: cvtsi2sd Vo, Ed
	{ "movntps",  &instruction::decode_Mo_Vo, OP_MOVNTPS, FLAG_SSE },
	{ "cvttsd2si",  &instruction::decode_Gq_Wo, OP_CVTTSD2SI, FLAG_SSE2 }, // x86: cvttsd2si Gd, Wo
	{ "cvtsd2si",  &instruction::decode_Gq_Wo, OP_CVTSD2SI, FLAG_SSE2 },   // x86: cvtsd2si Gd, Wo
	{ "ucomiss",  &instruction::decode_Vo_Wo, OP_UCOMISS, FLAG_SSE },
	{ "comiss",  &instruction::decode_Vo_Wo, OP_COMISS, FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtsd",   &instruction::decode_Vo_Wo, OP_SQRTSD,   FLAG_SSE2 },
	{ "rsqrtps",  &instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andps",    &instruction::decode_Vo_Wo, OP_ANDPS,    FLAG_SSE },
	{ "andnps",   &instruction::decode_Vo_Wo, OP_ANDNPS,   FLAG_SSE },
	{ "orps",     &instruction::decode_Vo_Wo, OP_ORPS,     FLAG_SSE },
	{ "xorps",    &instruction::decode_Vo_Wo, OP_XORPS,    FLAG_SSE },
	{ "addsd",    &instruction::decode_Vo_Wo, OP_ADDSD,    FLAG_SSE2 },
	{ "mulsd",    &instruction::decode_Vo_Wo, OP_MULSD,    FLAG_SSE2 },
	{ "cvtsd2ss", &instruction::decode_Vo_Wo, OP_CVTSD2SS, FLAG_SSE2 },
	{ "cvtdq2ps", &instruction::decode_Vo_Wo, OP_CVTDQ2PS, FLAG_SSE2 },
	{ "subsd",    &instruction::decode_Vo_Wo, OP_SUBSD,    FLAG_SSE2 },
	{ "minsd",    &instruction::decode_Vo_Wo, OP_MINSD,    FLAG_SSE2 },
	{ "divsd",    &instruction::decode_Vo_Wo, OP_DIVSD,    FLAG_SSE2 },
	{ "maxsd",    &instruction::decode_Vo_Wo, OP_MAXSD,    FLAG_SSE2 },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &instruction::decode_Pq_Qd, OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &instruction::decode_Pq_Qd, OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &instruction::decode_Pq_Qd, OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb", &instruction::decode_Pq_Qq, OP_PACKSSWB, FLAG_MMX },
	{ "pcmpgtb", &instruction::decode_Pq_Qq, OP_PCMPGTB, FLAG_MMX },
	{ "pcmpgtw", &instruction::decode_Pq_Qq, OP_PCMPGTW, FLAG_MMX },
	{ "pcmpgtd", &instruction::decode_Pq_Qq, OP_PCMPGTD, FLAG_MMX },
	{ "packuswb", &instruction::decode_Pq_Qq, OP_PACKUSWB, FLAG_MMX },
	{ "punpckhbw", &instruction::decode_Pq_Qd, OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &instruction::decode_Pq_Qd, OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &instruction::decode_Pq_Qd, OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw", &instruction::decode_Pq_Qq, OP_PACKSSDW, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &instruction::decode_Pd_Eq, OP_MOVQ, FLAG_MMX }, // x86: movq Pd, Ed
	{ "movq", &instruction::decode_Pq_Qq, OP_MOVQ, FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshuflw", &instruction::decode_Vo_Wo_Ib, OP_PSHUFLW, FLAG_SSE2 },
	{ "group13", &instruction::decode_group13,  OP_GROUP,   FLAG_NONE },
	{ "group14", &instruction::decode_group14,  OP_GROUP,   FLAG_NONE },
	{ "group15", &instruction::decode_group15,  OP_GROUP,   FLAG_NONE },
	{ "pcmpeqb", &instruction::decode_Pq_Qq,    OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &instruction::decode_Pq_Qq,    OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &instruction::decode_Pq_Qq,    OP_PCMPEQD, FLAG_MMX },
	{ "emms",    &instruction::decode0,         OP_EMMS,    FLAG_MMX },
	{ "vmread",  &instruction::decode_Eq_Gq,    OP_VMREAD,  FLAG_VMX }, // x86: vmread Ed, Gd
	{ "vmwrite", &instruction::decode_Gq_Eq,    OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "haddps",  &instruction::decode_Vo_Wo,    OP_HADDPS,  FLAG_SSE3 },
	{ "hsubps",  &instruction::decode_Vo_Wo,    OP_HSUBPS,  FLAG_SSE3 },
	{ "movq",    &instruction::decode_Eq_Pd,    OP_MOVD,    FLAG_MMX }, // x86: movq Ed, Pd
	{ "movq",    &instruction::decode_Qq_Pq,    OP_MOVQ,    FLAG_MMX },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &instruction::decode_Eb_Gb, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &instruction::decode_Ev_Gv, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss", &instruction::decode_Gv_Mp, OP_LSS, FLAG_NONE },
	{ "btr", &instruction::decode_Ev_Gv, OP_BTR, FLAG_W_FLAGS },
	{ "lfs", &instruction::decode_Gv_Mp, OP_LFS, FLAG_NONE },
	{ "lgs", &instruction::decode_Gv_Mp, OP_LGS, FLAG_NONE },
	{ "movzx", &instruction::decode_Gv_Eb, OP_MOVZX, FLAG_NONE },
	{ "movzx", &instruction::decode_Gv_Ew, OP_MOVZX, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &instruction::decode_group11, OP_GROUP, FLAG_NONE },
	{ "group8", &instruction::decode_group8, OP_GROUP, FLAG_NONE },
	{ "btc", &instruction::decode_Ev_Gv, OP_BTC, FLAG_W_FLAGS },
	{ "bsf", &instruction::decode_Gv_Ev, OP_BSF, FLAG_W_FLAGS },
	{ "bsr", &instruction::decode_Gv_Ev, OP_BSR, FLAG_W_FLAGS },
	{ "movsx", &instruction::decode_Gv_Eb, OP_MOVSX, FLAG_NONE },
	{ "movsx", &instruction::decode_Gv_Ew, OP_MOVSX, FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmpsd", &instruction::decode_Vo_Wo_Ib, OP_CMPSD, FLAG_SSE2 },
	{ "movnti", &instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &instruction::decode_Gd_Nq_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &instruction::decode_Vo_Wo_Ib, OP_SHUFPS, FLAG_SSE },
	{ "group9", &instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubps", &instruction::decode_Vo_Wo, OP_ADDSUBPS, FLAG_SSE3 },
	{ "psrlw", &instruction::decode_Pq_Qq, OP_PSRLW, FLAG_MMX },
	{ "psrld", &instruction::decode_Pq_Qq, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &instruction::decode_Pq_Qq, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &instruction::decode_Pq_Qq, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &instruction::decode_Pq_Qq, OP_PMULLW, FLAG_MMX },
	{ "movdq2q", &instruction::decode_Pq_Qq, OP_MOVDQ2Q, FLAG_SSE2 },
	{ "pmovmskb", &instruction::decode_Gd_Nq, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &instruction::decode_Pq_Qq, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &instruction::decode_Pq_Qq, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &instruction::decode_Pq_Qq, OP_PMINUB, FLAG_SSE },
    { "pand", &instruction::decode_Pq_Qq, OP_PAND, FLAG_MMX },
    { "paddusb", &instruction::decode_Pq_Qq, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &instruction::decode_Pq_Qq, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &instruction::decode_Pq_Qq, OP_PMAXUB, FLAG_SSE },
    { "pandn", &instruction::decode_Pq_Qq, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &instruction::decode_Pq_Qq, OP_PAVGB, FLAG_SSE },
	{ "psraw", &instruction::decode_Pq_Qq, OP_PSRAW, FLAG_MMX },
	{ "psrad", &instruction::decode_Pq_Qq, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &instruction::decode_Pq_Qq, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &instruction::decode_Pq_Qq, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &instruction::decode_Pq_Qq, OP_PMULHW, FLAG_MMX },
	{ "cvtpd2dq", &instruction::decode_Vo_Wo, OP_CVTPD2DQ, FLAG_SSE2 },
	{ "movntq", &instruction::decode_Mq_Pq, OP_MOVNTQ, FLAG_SSE },
	{ "psubsb", &instruction::decode_Pq_Qq, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &instruction::decode_Pq_Qq, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &instruction::decode_Pq_Qq, OP_PMINSW, FLAG_SSE },
	{ "por", &instruction::decode_Pq_Qq, OP_POR, FLAG_MMX },
	{ "paddsb", &instruction::decode_Pq_Qq, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &instruction::decode_Pq_Qq, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &instruction::decode_Pq_Qq, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &instruction::decode_Pq_Qq, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "lddqu", &instruction::decode_Vo_Mo, OP_LDDQU, FLAG_SSE3 },
	{ "psllw", &instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

// 2 byte opcodes with a f3 prefix
template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_2Byte_F3[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movss",    &instruction::decode_Vo_Wo, OP_MOVSS, FLAG_SSE },
	{ "movss",    &instruction::decode_Wo_Vo, OP_MOVSS, FLAG_SSE },
	{ "movsldup", &instruction::decode_Vq_Wq, OP_MOVSLDUP, FLAG_SSE3 },
	{ "movlps",   &instruction::decode_Mq_Vq, OP_MOVLPS, FLAG_SSE },
	{ "unpcklps", &instruction::decode_Vo_Wq, OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &instruction::decode_Vo_Wq, OP_UNPCKHPS, FLAG_SSE },
	{ "movshdup", &instruction::decode_Vq_Wq, OP_MOVSHDUP, FLAG_SSE3 },
	{ "movhps",   &instruction::decode_Mq_Vq, OP_MOVHPS, FLAG_SSE },
	{ "group17",  &instruction::decode_group17, OP_GROUP, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop",      &instruction::decode_Ev, OP_NOP, FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &instruction::decode_Rd_Cd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Rd_Dd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Cd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &instruction::decode_Dd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movaps", &instruction::decode_Vo_Wo, OP_MOVAPS, FLAG_SSE },
	{ "movaps", &instruction::decode_Wo_Vo, OP_MOVAPS, FLAG_SSE },
	{ "cvtsi2ss", &instruction::decode_Vo_Eq, OP_CVTSI2SS, FLAG_SSE }, // x86: cvtsi2ss Vo, Ed
	{ "movntps",  &instruction::decode_Mo_Vo, OP_MOVNTPS, FLAG_SSE },
	{ "cvttss2si",  &instruction::decode_Gq_Wo, OP_CVTTSS2SI, FLAG_SSE }, // x86: cvttss2si Gd, Wo
	{ "cvtss2si",  &instruction::decode_Gq_Wo, OP_CVTSS2SI, FLAG_SSE }, // x86: cvtss2si Gd, Wo
	{ "ucomiss",  &instruction::decode_Vo_Wo, OP_UCOMISS, FLAG_SSE },
	{ "comiss",  &instruction::decode_Vo_Wo, OP_COMISS, FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtss", &instruction::decode_Vo_Wo, OP_SQRTSS, FLAG_SSE },
	{ "rsqrtss", &instruction::decode_Vo_Wo, OP_RSQRTSS, FLAG_SSE },
	{ "rcpss", &instruction::decode_Vo_Wo, OP_RCPSS, FLAG_SSE },
	{ "andps", &instruction::decode_Vo_Wo, OP_ANDPS, FLAG_SSE },
	{ "andnps", &instruction::decode_Vo_Wo, OP_ANDNPS, FLAG_SSE },
	{ "orps", &instruction::decode_Vo_Wo, OP_ORPS, FLAG_SSE },
	{ "xorps", &instruction::decode_Vo_Wo, OP_XORPS, FLAG_SSE },
	{ "addss", &instruction::decode_Vo_Wo, OP_ADDSS, FLAG_SSE },
	{ "mulss", &instruction::decode_Vo_Wo, OP_MULSS, FLAG_SSE },
	{ "cvtss2sd", &instruction::decode_Vo_Wo, OP_CVTSS2SD, FLAG_SSE2 },
	{ "cvttps2dq", &instruction::decode_Vo_Wo, OP_CVTTPS2DQ, FLAG_SSE2 },
	{ "subss", &instruction::decode_Vo_Wo, OP_SUBSS, FLAG_SSE },
	{ "minss", &instruction::decode_Vo_Wo, OP_MINSS, FLAG_SSE },
	{ "divss", &instruction::decode_Vo_Wo, OP_DIVSS, FLAG_SSE },
	{ "maxss", &instruction::decode_Vo_Wo, OP_MAXSS, FLAG_SSE },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &instruction::decode_Pq_Qd, OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &instruction::decode_Pq_Qd, OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &instruction::decode_Pq_Qd, OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb", &instruction::decode_Pq_Qq, OP_PACKSSWB, FLAG_MMX },
	{ "pcmpgtb", &instruction::decode_Pq_Qq, OP_PCMPGTB, FLAG_MMX },
	{ "pcmpgtw", &instruction::decode_Pq_Qq, OP_PCMPGTW, FLAG_MMX },
	{ "pcmpgtd", &instruction::decode_Pq_Qq, OP_PCMPGTD, FLAG_MMX },
	{ "packuswb", &instruction::decode_Pq_Qq, OP_PACKUSWB, FLAG_MMX },
	{ "punpckhbw", &instruction::decode_Pq_Qd, OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &instruction::decode_Pq_Qd, OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &instruction::decode_Pq_Qd, OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw", &instruction::decode_Pq_Qq, OP_PACKSSDW, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &instruction::decode_Pd_Eq, OP_MOVQ, FLAG_MMX }, // x86: movq Pd, Ed
	{ "movdqu", &instruction::decode_Vo_Wo, OP_MOVDQU, FLAG_SSE2 },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufhw", &instruction::decode_Vo_Wo_Ib, OP_PSHUFHW, FLAG_SSE2 },
	{ "group13", &instruction::decode_group13, OP_GROUP, FLAG_NONE },
	{ "group14", &instruction::decode_group14, OP_GROUP, FLAG_NONE },
	{ "group15", &instruction::decode_group15, OP_GROUP, FLAG_NONE },
	{ "pcmpeqb", &instruction::decode_Pq_Qq, OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &instruction::decode_Pq_Qq, OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &instruction::decode_Pq_Qq, OP_PCMPEQD, FLAG_MMX },
	{ "emms", &instruction::decode0, OP_EMMS, FLAG_MMX },
	{ "vmread", &instruction::decode_Eq_Gq, OP_VMREAD, FLAG_VMX },   // x86: vmread Ed, Gd
	{ "vmwrite", &instruction::decode_Gq_Eq, OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &instruction::decode_Vq_Wq, OP_MOVQ, FLAG_MMX },
	{ "movdqu", &instruction::decode_Wo_Vo, OP_MOVDQU, FLAG_SSE2 },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &instruction::decode_Eb_Gb, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &instruction::decode_Ev_Gv, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss", &instruction::decode_Gv_Mp, OP_LSS, FLAG_NONE },
	{ "btr", &instruction::decode_Ev_Gv, OP_BTR, FLAG_W_FLAGS },
	{ "lfs", &instruction::decode_Gv_Mp, OP_LFS, FLAG_NONE },
	{ "lgs", &instruction::decode_Gv_Mp, OP_LGS, FLAG_NONE },
	{ "movzx", &instruction::decode_Gv_Eb, OP_MOVZX, FLAG_NONE },
	{ "movzx", &instruction::decode_Gv_Ew, OP_MOVZX, FLAG_NONE },
	{ "popcnt", &instruction::decode_Gv_Ev, OP_POPCNT, FLAG_SSE4a },
	{ "group11", &instruction::decode_group11, OP_GROUP, FLAG_NONE },
	{ "group8", &instruction::decode_group8, OP_GROUP, FLAG_NONE },
	{ "btc", &instruction::decode_Ev_Gv, OP_BTC, FLAG_W_FLAGS },
	{ "bsf", &instruction::decode_Gv_Ev, OP_BSF, FLAG_W_FLAGS },
	{ "bsr", &instruction::decode_Gv_Ev, OP_BSR, FLAG_W_FLAGS },
	{ "movsx", &instruction::decode_Gv_Eb, OP_MOVSX, FLAG_NONE },
	{ "movsx", &instruction::decode_Gv_Ew, OP_MOVSX, FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmpss", &instruction::decode_Vo_Wo_Ib, OP_CMPSS, FLAG_SSE },
	{ "movnti", &instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &instruction::decode_Gd_Nq_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &instruction::decode_Vo_Wo_Ib, OP_SHUFPS, FLAG_SSE },
	{ "group9", &instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psrlw", &instruction::decode_Pq_Qq, OP_PSRLW, FLAG_MMX },
	{ "psrld", &instruction::decode_Pq_Qq, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &instruction::decode_Pq_Qq, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &instruction::decode_Pq_Qq, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &instruction::decode_Pq_Qq, OP_PMULLW, FLAG_MMX },
	{ "movq2dq", &instruction::decode_Vo_Nq, OP_MOVQ2DQ, FLAG_SSE2 },
	{ "pmovmskb", &instruction::decode_Gd_Nq, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &instruction::decode_Pq_Qq, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &instruction::decode_Pq_Qq, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &instruction::decode_Pq_Qq, OP_PMINUB, FLAG_SSE },
    { "pand", &instruction::decode_Pq_Qq, OP_PAND, FLAG_MMX },
    { "paddusb", &instruction::decode_Pq_Qq, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &instruction::decode_Pq_Qq, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &instruction::decode_Pq_Qq, OP_PMAXUB, FLAG_SSE },
    { "pandn", &instruction::decode_Pq_Qq, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &instruction::decode_Pq_Qq, OP_PAVGB, FLAG_SSE },
	{ "psraw", &instruction::decode_Pq_Qq, OP_PSRAW, FLAG_MMX },
	{ "psrad", &instruction::decode_Pq_Qq, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &instruction::decode_Pq_Qq, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &instruction::decode_Pq_Qq, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &instruction::decode_Pq_Qq, OP_PMULHW, FLAG_MMX },
	{ "cvtdq2pd", &instruction::decode_Vo_Wo, OP_CVTDQ2PD, FLAG_SSE2 },
	{ "movntq", &instruction::decode_Mq_Pq, OP_MOVNTQ, FLAG_SSE },
	{ "psubsb", &instruction::decode_Pq_Qq, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &instruction::decode_Pq_Qq, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &instruction::decode_Pq_Qq, OP_PMINSW, FLAG_SSE },
	{ "por", &instruction::decode_Pq_Qq, OP_POR, FLAG_MMX },
	{ "paddsb", &instruction::decode_Pq_Qq, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &instruction::decode_Pq_Qq, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &instruction::decode_Pq_Qq, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &instruction::decode_Pq_Qq, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};


template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_3Byte_38_66[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &instruction::decode_Vo_Wo, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &instruction::decode_Vo_Wo, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &instruction::decode_Vo_Wo, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &instruction::decode_Vo_Wo, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &instruction::decode_Vo_Wo, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &instruction::decode_Vo_Wo, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &instruction::decode_Vo_Wo, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &instruction::decode_Vo_Wo, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &instruction::decode_Vo_Wo, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &instruction::decode_Vo_Wo, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &instruction::decode_Vo_Wo, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &instruction::decode_Vo_Wo, OP_PMULHRSW, FLAG_SSSE3 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &instruction::decode_Vo_Wo,   OP_PBLENDVB, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "blendvps", &instruction::decode_Vo_Wo,   OP_BLENDVPS, FLAG_SSE4_1 },
	{ "blendvpd", &instruction::decode_Vo_Wo,   OP_BLENDVPD, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "ptest",    &instruction::decode_Vo_Wo,   OP_PTEST,    FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pabsb",    &instruction::decode_Vo_Wo,   OP_PABSB,    FLAG_SSSE3 },
	{ "pabsw",    &instruction::decode_Vo_Wo,   OP_PABSW,    FLAG_SSSE3 },
	{ "pabsd",    &instruction::decode_Vo_Wo,   OP_PABSD,    FLAG_SSSE3 },
	{ "invalid",  &instruction::decode_invalid, OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW, FLAG_SSE4_1 },
	{ "pmovsxbd", &instruction::decode_Vo_Uo_Md, OP_PMOVSXBD, FLAG_SSE4_1 },
	{ "pmovsxbq", &instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ, FLAG_SSE4_1 },
	{ "pmovsxwd", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD, FLAG_SSE4_1 },
	{ "pmovsxwq", &instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ, FLAG_SSE4_1 },
	{ "pmovsxdq", &instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "pmuldq",   &instruction::decode_Vo_Wo,    OP_PMULDQ,   FLAG_SSE4_1 },
	{ "pcmpeqq",  &instruction::decode_Vo_Wo,    OP_PCMPEQQ,  FLAG_SSE4_1 },
	{ "movntdqa", &instruction::decode_Vo_Mo,    OP_MOVNTDQA, FLAG_SSE4_1 },
	{ "packusdw", &instruction::decode_Vo_Wo,    OP_PACKUSDW, FLAG_SSE4_1 },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW, FLAG_SSE4_1 },
	{ "pmovzxbd", &instruction::decode_Vo_Uo_Md, OP_PMOVZXBD, FLAG_SSE4_1 },
	{ "pmovzxbq", &instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ, FLAG_SSE4_1 },
	{ "pmovzxwd", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD, FLAG_SSE4_1 },
	{ "pmovzxwq", &instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ, FLAG_SSE4_1 },
	{ "pmovzxdq", &instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pcmpgtq", &instruction::decode_Vo_Wo, OP_PCMPGTQ, FLAG_SSE4_2 },
	{ "pminsb", &instruction::decode_Vo_Wo, OP_PMINSB, FLAG_SSE4_1 },
	{ "pminsd", &instruction::decode_Vo_Wo, OP_PMINSD, FLAG_SSE4_1 },
	{ "pminuw", &instruction::decode_Vo_Wo, OP_PMINUW, FLAG_SSE4_1 },
	{ "pminud", &instruction::decode_Vo_Wo, OP_PMINUD, FLAG_SSE4_1 },
	{ "pmaxsb", &instruction::decode_Vo_Wo, OP_PMAXSB, FLAG_SSE4_1 },
	{ "pmaxsd", &instruction::decode_Vo_Wo, OP_PMAXSD, FLAG_SSE4_1 },
	{ "pmaxuw", &instruction::decode_Vo_Wo, OP_PMAXUW, FLAG_SSE4_1 },
	{ "pmaxud", &instruction::decode_Vo_Wo, OP_PMAXUD, FLAG_SSE4_1 },

	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &instruction::decode_Vo_Wo, OP_PMULLD, FLAG_SSE4_1 },
	{ "phminposuw", &instruction::decode_Vo_Wo, OP_PHMINPOSUW, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	{ "nvept",   &instruction::decode_Gq_Mo,   OP_NVEPT,   FLAG_NONE }, // x86: nvept Gd, Mo
	{ "nvvpid",  &instruction::decode_Gq_Mo,   OP_NVVPID,  FLAG_NONE }, // x86: nvvpid Gd, Mo
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x90 - 0x0f 0x38 0x9f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xa0 - 0x0f 0x38 0xaf */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xb0 - 0x0f 0x38 0xbf */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xc0 - 0x0f 0x38 0xcf */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xd0 - 0x0f 0x38 0xdf */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xe0 - 0x0f 0x38 0xef */
	INVALID_BLOCK,

	/* 0x0f 0x38 0xf0 - 0x0f 0x38 0xff */
	{ "movbe",   &instruction::decode_Gv_Mv,   OP_MOVBE,   FLAG_NONE },
	{ "movbe",   &instruction::decode_Mv_Gv,   OP_MOVBE,   FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <>
const instruction<x86_64>::opcode_entry instruction<x86_64>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "roundps", &instruction::decode_Vo_Wo_Ib, OP_ROUNDPS, FLAG_SSE4_1 },
	{ "roundpd", &instruction::decode_Vo_Wo_Ib, OP_ROUNDPD, FLAG_SSE4_1 },
	{ "roundss", &instruction::decode_Vo_Wo_Ib, OP_ROUNDSS, FLAG_SSE4_1 },
	{ "roundsd", &instruction::decode_Vo_Wo_Ib, OP_ROUNDSD, FLAG_SSE4_1 },
	{ "blendps", &instruction::decode_Vo_Wo_Ib, OP_BLENDPS, FLAG_SSE4_1 },
	{ "blendpd", &instruction::decode_Vo_Wo_Ib, OP_BLENDPD, FLAG_SSE4_1 },
	{ "pblendw", &instruction::decode_Vo_Wo_Ib, OP_PBLENDW, FLAG_SSE4_1 },
	{ "palignr", &instruction::decode_Vo_Wo_Ib, OP_PALIGNR, FLAG_SSSE3 },

	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "pextrb",    &instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB,    FLAG_SSE4_1 },
	{ "pextrw",    &instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW,    FLAG_SSE | FLAG_SSE4_1 },
	{ "pextrq",    &instruction::decode_Eq_Vo_Ib,    OP_PEXTRQ,    FLAG_NONE }, // x86: pextrq Eq, Vo, Ib
	{ "extractps", &instruction::decode_Ed_Vo_Ib,    OP_EXTRACTPS, FLAG_SSE4_1 }, // x86: extractps Ed, Vo, Ib // TODO: figure out if this should allow RAX or not?
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },

	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb",   &instruction::decode_Vo_Mb_Ib, OP_PINSRB,   FLAG_SSE4_1 },
	{ "insertps", &instruction::decode_Vo_Md_Ib, OP_INSERTPS, FLAG_SSE4_1 },
	{ "pinsrq",   &instruction::decode_Vo_Eq_Ib, OP_PINSRQ,   FLAG_NONE }, // x86: pinsrq Vo, Eq, Ib
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps",    &instruction::decode_Vo_Wo_Ib, OP_DPPS,    FLAG_SSE4_1 },
	{ "dppd",    &instruction::decode_Vo_Wo_Ib, OP_DPPD,    FLAG_SSE4_1 },
	{ "mpsadbw", &instruction::decode_Vo_Wo_Ib, OP_MPSADBW, FLAG_SSE4_1 },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid,  OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpestri", &instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistrm", &instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistri", &instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },

	/* 0x0f 0x3a 0x70 - 0x0f 0x3a 0x7f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x80 - 0x0f 0x3a 0x8f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x90 - 0x0f 0x3a 0x9f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xa0 - 0x0f 0x3a 0xaf */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xb0 - 0x0f 0x3a 0xbf */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xc0 - 0x0f 0x3a 0xcf */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xd0 - 0x0f 0x3a 0xdf */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xe0 - 0x0f 0x3a 0xef */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0xf0 - 0x0f 0x3a 0xff */
	INVALID_BLOCK
};

}

#endif
