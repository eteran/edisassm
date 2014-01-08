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

#include "Instruction.h"

#ifndef INSTRUCTION64_20070427_TCC_
#define INSTRUCTION64_20070427_TCC_

namespace edisassm {

template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_cmpsw_cmpsd_cmpsq[3] = {
	{ "cmpsw",  &Instruction::decode0, OP_CMPS, FLAG_RW_FLAGS },
	{ "cmpsd",  &Instruction::decode0, OP_CMPS, FLAG_RW_FLAGS },
	{ "cmpsq",  &Instruction::decode0, OP_CMPS, FLAG_RW_FLAGS | FLAG_64BIT_ONLY }, // x86: invalid
};

template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_Group7A[64] = {
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "vmcall",   &Instruction::decode0,        OP_VMCALL,   FLAG_VMX },
	{ "vmlaunch", &Instruction::decode0,        OP_VMLAUNCH, FLAG_VMX },
	{ "vmresume", &Instruction::decode0,        OP_VMRESUME, FLAG_VMX },
	{ "vmxoff",   &Instruction::decode0,        OP_VMXOFF,   FLAG_VMX },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	
	{ "monitor", &Instruction::decode0,        OP_MONITOR, FLAG_SSE3 },
	{ "mwait",   &Instruction::decode0,        OP_MWAIT,   FLAG_SSE3 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "xgetbv", &Instruction::decode0,         OP_XGETBV,  FLAG_NONE },
	{ "xsetbv", &Instruction::decode0,         OP_XSETBV,  FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "vmrun",   &Instruction::decode0, OP_VMRUN,   FLAG_AMD },
	{ "vmmcall", &Instruction::decode0, OP_VMMCALL, FLAG_AMD },
	{ "vmload",  &Instruction::decode0, OP_VMLOAD,  FLAG_AMD },
	{ "vmsave",  &Instruction::decode0, OP_VMSAVE,  FLAG_AMD },
	{ "stgi",    &Instruction::decode0, OP_STGI,    FLAG_AMD },
	{ "clgi",    &Instruction::decode0, OP_CLGI,    FLAG_AMD },
	{ "skinit",  &Instruction::decode0, OP_SKINIT,  FLAG_AMD },
	{ "invlpga", &Instruction::decode0, OP_INVLPGA, FLAG_AMD },

	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },

	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },

	{ "swapgs",  &Instruction::decode0,        OP_SWAPGS,  FLAG_NONE }, // x86: invalid
	{ "rdtscp",  &Instruction::decode0,        OP_RDTSCP,  FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes[0x100] = {

	/* 0x00 - 0x0f */
	{ "add",     &Instruction::decode_Eb_Gb,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &Instruction::decode_Ev_Gv,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &Instruction::decode_Gb_Eb,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &Instruction::decode_Gv_Ev,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &Instruction::decode_AL_Ib,   OP_ADD,     FLAG_W_FLAGS },
	{ "add",     &Instruction::decode_rAX_Iz,  OP_ADD,     FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "or",      &Instruction::decode_Eb_Gb,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &Instruction::decode_Ev_Gv,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &Instruction::decode_Gb_Eb,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &Instruction::decode_Gv_Ev,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &Instruction::decode_AL_Ib,   OP_OR,      FLAG_W_FLAGS },
	{ "or",      &Instruction::decode_rAX_Iz,  OP_OR,      FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "2byte",   &Instruction::decode_2byte,   OP_2BYTE,   FLAG_NONE },

	/* 0x10 - 0x1f */
	{ "adc", &Instruction::decode_Eb_Gb, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &Instruction::decode_Ev_Gv, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &Instruction::decode_Gb_Eb, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &Instruction::decode_Gv_Ev, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &Instruction::decode_AL_Ib, OP_ADC, FLAG_RW_FLAGS },
	{ "adc", &Instruction::decode_rAX_Iz, OP_ADC, FLAG_RW_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "sbb", &Instruction::decode_Eb_Gb, OP_SBB, FLAG_NONE },
	{ "sbb", &Instruction::decode_Ev_Gv, OP_SBB, FLAG_NONE },
	{ "sbb", &Instruction::decode_Gb_Eb, OP_SBB, FLAG_NONE },
	{ "sbb", &Instruction::decode_Gv_Ev, OP_SBB, FLAG_NONE },
	{ "sbb", &Instruction::decode_AL_Ib, OP_SBB, FLAG_NONE },
	{ "sbb", &Instruction::decode_rAX_Iz, OP_SBB, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x20 - 0x2f */
	{ "and", &Instruction::decode_Eb_Gb, OP_AND, FLAG_W_FLAGS },
	{ "and", &Instruction::decode_Ev_Gv, OP_AND, FLAG_W_FLAGS },
	{ "and", &Instruction::decode_Gb_Eb, OP_AND, FLAG_W_FLAGS },
	{ "and", &Instruction::decode_Gv_Ev, OP_AND, FLAG_W_FLAGS },
	{ "and", &Instruction::decode_AL_Ib, OP_AND, FLAG_W_FLAGS },
	{ "and", &Instruction::decode_rAX_Iz, OP_AND, FLAG_W_FLAGS },
	{ "prefix es", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "sub", &Instruction::decode_Eb_Gb, OP_SUB, FLAG_NONE },
	{ "sub", &Instruction::decode_Ev_Gv, OP_SUB, FLAG_NONE },
	{ "sub", &Instruction::decode_Gb_Eb, OP_SUB, FLAG_NONE },
	{ "sub", &Instruction::decode_Gv_Ev, OP_SUB, FLAG_NONE },
	{ "sub", &Instruction::decode_AL_Ib, OP_SUB, FLAG_NONE },
	{ "sub", &Instruction::decode_rAX_Iz, OP_SUB, FLAG_NONE },
	{ "prefix cs", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x30 - 0x3f */
	{ "xor", &Instruction::decode_Eb_Gb, OP_XOR, FLAG_NONE },
	{ "xor", &Instruction::decode_Ev_Gv, OP_XOR, FLAG_NONE },
	{ "xor", &Instruction::decode_Gb_Eb, OP_XOR, FLAG_NONE },
	{ "xor", &Instruction::decode_Gv_Ev, OP_XOR, FLAG_NONE },
	{ "xor", &Instruction::decode_AL_Ib, OP_XOR, FLAG_NONE },
	{ "xor", &Instruction::decode_rAX_Iz, OP_XOR, FLAG_NONE },
	{ "prefix ss", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "cmp", &Instruction::decode_Eb_Gb, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &Instruction::decode_Ev_Gv, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &Instruction::decode_Gb_Eb, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &Instruction::decode_Gv_Ev, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &Instruction::decode_AL_Ib, OP_CMP, FLAG_W_FLAGS },
	{ "cmp", &Instruction::decode_rAX_Iz, OP_CMP, FLAG_W_FLAGS },
	{ "prefix ds", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only

	/* 0x40 - 0x4f */
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)
	{ "prefix rex", &Instruction::decode_invalid, OP_PREFIX, FLAG_NONE }, // ia-32 only (REX byte)

	/* 0x50 - 0x5f */
	{ "push", &Instruction::decode_rAX, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rCX, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rDX, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rBX, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rSP, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rBP, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rSI, OP_PUSH, FLAG_STACK },
	{ "push", &Instruction::decode_rDI, OP_PUSH, FLAG_STACK },
	{ "pop",  &Instruction::decode_rAX, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rCX, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rDX, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rBX, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rSP, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rBP, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rSI, OP_POP,  FLAG_STACK },
	{ "pop",  &Instruction::decode_rDI, OP_POP,  FLAG_STACK },

	/* 0x60 - 0x6f */
	{ "invalid",       &Instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",       &Instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",       &Instruction::decode_invalid,             OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "movsxd",        &Instruction::decode_Gv_Ev,               OP_MOVSXD,  FLAG_NONE }, // x86: arpl Ew,Gw
	{ "prefix fs",     &Instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix gs",     &Instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix data16", &Instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "prefix addr16", &Instruction::decode_invalid,             OP_PREFIX,  FLAG_NONE },
	{ "push",          &Instruction::decode_Iz,                  OP_PUSH,    FLAG_STACK },
	{ "imul",          &Instruction::decode_Gv_Ev_Iz,            OP_IMUL,    FLAG_W_FLAGS },
	{ "push",          &Instruction::decode_Ib,                  OP_PUSH,    FLAG_STACK },
	{ "imul",          &Instruction::decode_Gv_Ev_Ib,            OP_IMUL,    FLAG_W_FLAGS },
	{ "insb",          &Instruction::decode0,                    OP_INS,     FLAG_NONE },
	{ "insw/insd",     &Instruction::decode_insw_insd_invalid,   OP_GROUP,   FLAG_NONE },
	{ "outsb",         &Instruction::decode0,                    OP_OUTS,    FLAG_NONE },
	{ "outsw/outsd",   &Instruction::decode_outsw_outsd_invalid, OP_GROUP,   FLAG_NONE },

	/* 0x70 - 0x7f */
	{ "jo",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &Instruction::decode_Jb, OP_JCC, FLAG_R_FLAGS },

	/* 0x80 - 0x8f */
	{ "group1",  &Instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "group1",  &Instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "group1",  &Instruction::decode_group1,  OP_GROUP,   FLAG_NONE },
	{ "test",    &Instruction::decode_Eb_Gb,   OP_TEST,    FLAG_NONE },
	{ "test",    &Instruction::decode_Ev_Gv,   OP_TEST,    FLAG_NONE },
	{ "xchg",    &Instruction::decode_Gb_Eb,   OP_XCHG,    FLAG_NONE },
	{ "xchg",    &Instruction::decode_Gv_Ev,   OP_XCHG,    FLAG_NONE },
	{ "mov",     &Instruction::decode_Eb_Gb,   OP_MOV,     FLAG_NONE },
	{ "mov",     &Instruction::decode_Ev_Gv,   OP_MOV,     FLAG_NONE },
	{ "mov",     &Instruction::decode_Gb_Eb,   OP_MOV,     FLAG_NONE },
	{ "mov",     &Instruction::decode_Gv_Ev,   OP_MOV,     FLAG_NONE },
	{ "mov",     &Instruction::decode_Ev_Sw,   OP_MOV,     FLAG_NONE },
	{ "lea",     &Instruction::decode_Gv_M,    OP_LEA,     FLAG_NONE },
	{ "mov",     &Instruction::decode_Sw_Ew,   OP_MOV,     FLAG_NONE },
	{ "group10", &Instruction::decode_group10, OP_GROUP,   FLAG_NONE },

	/* 0x90 - 0x9f */
	{ "xchg",                 &Instruction::decode_rAX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rCX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rDX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rBX_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rSP_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rBP_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rSI_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "xchg",                 &Instruction::decode_rDI_rAX_NOREX,        OP_XCHG,    FLAG_NONE },
	{ "cbw/cwde/cdqe",        &Instruction::decode_cbw_cwde_cdqe,        OP_GROUP,   FLAG_NONE },
	{ "cwd/cdq/cqo",          &Instruction::decode_cwd_cdq_cqo,          OP_GROUP,   FLAG_NONE },
	{ "invalid",              &Instruction::decode_invalid,              OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "wait",                 &Instruction::decode0,                     OP_WAIT,    FLAG_NONE },
	{ "pushfw/pushfd/pushfq", &Instruction::decode_pushfw_pushfd_pushfq, OP_GROUP,   FLAG_NONE },
	{ "popfw/popfd/popfq",    &Instruction::decode_popfw_popfd_popfq,    OP_GROUP,   FLAG_NONE },
	{ "sahf",                 &Instruction::decode0,                     OP_SAHF,    FLAG_NONE },
	{ "lahf",                 &Instruction::decode0,                     OP_LAHF,    FLAG_R_FLAGS },

	/* 0xa0 - 0xaf */
	{ "mov",               &Instruction::decode_AL_Ob,             OP_MOV,   FLAG_NONE },
	{ "mov",               &Instruction::decode_rAX_Ov,            OP_MOV,   FLAG_NONE },
	{ "mov",               &Instruction::decode_Ob_AL,             OP_MOV,   FLAG_NONE },
	{ "mov",               &Instruction::decode_Ov_rAX,            OP_MOV,   FLAG_NONE },
	{ "movsb",             &Instruction::decode0,                  OP_MOVS,  FLAG_R_FLAGS },
	{ "movsw/movsd/movsq", &Instruction::decode_movsw_movsd_movsq, OP_GROUP, FLAG_NONE },
	{ "cmpsb",             &Instruction::decode0,                  OP_CMPS,  FLAG_RW_FLAGS },
	{ "cmpsw/cmpsd/cmpsq", &Instruction::decode_cmpsw_cmpsd_cmpsq, OP_GROUP, FLAG_NONE },
	{ "test",              &Instruction::decode_AL_Ib,             OP_TEST,  FLAG_NONE },
	{ "test",              &Instruction::decode_rAX_Iz,            OP_TEST,  FLAG_NONE },
	{ "stosb",             &Instruction::decode0,                  OP_STOS,  FLAG_NONE },
	{ "stosw/stosd/stosq", &Instruction::decode_stosw_stosd_stosq, OP_GROUP, FLAG_NONE },
	{ "lodsb",             &Instruction::decode0,                  OP_LODS,  FLAG_R_FLAGS },
	{ "lodsw/lodsd/lodsq", &Instruction::decode_lodsw_lodsd_lodsq, OP_GROUP, FLAG_NONE },
	{ "scasb",             &Instruction::decode0,                  OP_SCAS,  FLAG_NONE },
	{ "scasw/scasd/scasq", &Instruction::decode_scasw_scasd_scasq, OP_GROUP, FLAG_NONE },

	/* 0xb0 - 0xbf */
	{ "mov", &Instruction::decode_AL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_CL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_DL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_BL_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_AH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_CH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_DH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_BH_Ib,  OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rAX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rCX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rDX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rBX_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rSP_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rBP_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rSI_Iv, OP_MOV, FLAG_NONE },
	{ "mov", &Instruction::decode_rDI_Iv, OP_MOV, FLAG_NONE },

	/* 0xc0 - 0xcf */
	{ "group2",           &Instruction::decode_group2,           OP_GROUP,   FLAG_NONE },
	{ "group2",           &Instruction::decode_group2,           OP_GROUP,   FLAG_NONE },
	{ "ret",              &Instruction::decode_Iw,               OP_RET,     FLAG_NONE },
	{ "ret",              &Instruction::decode0,                 OP_RET,     FLAG_NONE },
	{ "invalid",          &Instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "invalid",          &Instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "group12",          &Instruction::decode_group12,          OP_GROUP,   FLAG_NONE },
	{ "group12",          &Instruction::decode_group12,          OP_GROUP,   FLAG_NONE },
	{ "enter",            &Instruction::decode_Iw_Ib,            OP_ENTER,   FLAG_STACK },
	{ "leave",            &Instruction::decode0,                 OP_LEAVE,   FLAG_STACK },
	{ "retf",             &Instruction::decode_Iw,               OP_RETF,    FLAG_NONE },
	{ "retf",             &Instruction::decode0,                 OP_RETF,    FLAG_NONE },
	{ "int3",             &Instruction::decode0,                 OP_INT3,    FLAG_W_FLAGS },
	{ "int",              &Instruction::decode_Ib,               OP_INT,     FLAG_W_FLAGS },
	{ "invalid",          &Instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "iretw/iret/iretq", &Instruction::decode_iretw_iret_iretq, OP_GROUP,   FLAG_NONE },

	/* 0xd0 - 0xdf */
	{ "group2",  &Instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &Instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &Instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "group2",  &Instruction::decode_group2D, OP_GROUP,    FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE }, // ia-32 only
	{ "invalid", &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "xlat",    &Instruction::decode0,        OP_XLAT,     FLAG_NONE },
	{ "esc0",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc1",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc2",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc3",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc4",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc5",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc6",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },
	{ "esc7",    &Instruction::decode_x87,     OP_FPU,      FLAG_NONE },

	/* 0xe0 - 0xef */
	{ "loopne",           &Instruction::decode_Jb,               OP_LOOPNE,  FLAG_R_FLAGS },
	{ "loope",            &Instruction::decode_Jb,               OP_LOOPE,   FLAG_R_FLAGS },
	{ "loop",             &Instruction::decode_Jb,               OP_LOOP,    FLAG_R_FLAGS },
	{ "jcxz/jecxz/jrcxz", &Instruction::decode_jcxz_jecxz_jrcxz, OP_GROUP,   FLAG_NONE },
	{ "in",               &Instruction::decode_AL_Ib,            OP_IN,      FLAG_NONE },
	{ "in",               &Instruction::decode_eAX_Ib,           OP_IN,      FLAG_NONE },
	{ "out",              &Instruction::decode_Ib_AL,            OP_OUT,     FLAG_NONE },
	{ "out",              &Instruction::decode_Ib_eAX,           OP_OUT,     FLAG_NONE },
	{ "call",             &Instruction::decode_Jz,               OP_CALL,    FLAG_STACK },
	{ "jmp",              &Instruction::decode_Jz,               OP_JMP,     FLAG_NONE },
	{ "invalid",          &Instruction::decode_invalid,          OP_INVALID, FLAG_NONE }, // ia-32 only
	{ "jmp",              &Instruction::decode_Jb,               OP_JMP,     FLAG_NONE },
	{ "in",               &Instruction::decode_AL_DX,            OP_IN,      FLAG_NONE },
	{ "in",               &Instruction::decode_eAX_DX,           OP_IN,      FLAG_NONE },
	{ "out",              &Instruction::decode_DX_AL,            OP_OUT,     FLAG_NONE },
	{ "out",              &Instruction::decode_DX_eAX,           OP_OUT,     FLAG_NONE },

	/* 0xf0 - 0xff */
	{ "prefix lock",  &Instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "invalid",      &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "prefix repne", &Instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "prefix rep",   &Instruction::decode_invalid, OP_PREFIX,  FLAG_NONE },
	{ "hlt",          &Instruction::decode0,        OP_HLT,     FLAG_NONE },
	{ "cmc",          &Instruction::decode0,        OP_CMC,     FLAG_RW_FLAGS },
	{ "group3",       &Instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "group3",       &Instruction::decode_group3,  OP_GROUP,   FLAG_NONE },
	{ "clc",          &Instruction::decode0,        OP_CLC,     FLAG_W_FLAGS },
	{ "stc",          &Instruction::decode0,        OP_STC,     FLAG_NONE },
	{ "cli",          &Instruction::decode0,        OP_CLI,     FLAG_W_FLAGS },
	{ "sti",          &Instruction::decode0,        OP_STI,     FLAG_NONE },
	{ "cld",          &Instruction::decode0,        OP_CLD,     FLAG_W_FLAGS },
	{ "std",          &Instruction::decode0,        OP_STD,     FLAG_NONE },
	{ "group4",       &Instruction::decode_group4,  OP_GROUP,   FLAG_NONE },
	{ "group5",       &Instruction::decode_group5,  OP_GROUP,   FLAG_NONE },
};


template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_2Byte_NA[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &Instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &Instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &Instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &Instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &Instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &Instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &Instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movups",   &Instruction::decode_Vo_Wo,   OP_MOVUPS,   FLAG_SSE },
	{ "movups",   &Instruction::decode_Wo_Vo,   OP_MOVUPS,   FLAG_SSE },
	{ "movlps",   &Instruction::decode_Vq_Mq,   OP_MOVLPS,   FLAG_SSE }, // TODO: movhlps here too
	{ "movlps",   &Instruction::decode_Mq_Vq,   OP_MOVLPS,   FLAG_SSE },
	{ "unpcklps", &Instruction::decode_Vo_Wq,   OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &Instruction::decode_Vo_Wq,   OP_UNPCKHPS, FLAG_SSE },
	{ "movhps",   &Instruction::decode_Vq_Mq,   OP_MOVHPS,   FLAG_SSE },  // TODO: movlhps here too
	{ "movhps",   &Instruction::decode_Mq_Vq,   OP_MOVHPS,   FLAG_SSE },
	{ "group17",  &Instruction::decode_group17, OP_GROUP,    FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "nop",      &Instruction::decode_Ev,      OP_NOP,      FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov",        &Instruction::decode_Rd_Cd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Rd_Dd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Cd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Dd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movaps",     &Instruction::decode_Vo_Wo,   OP_MOVAPS,    FLAG_SSE },
	{ "movaps",     &Instruction::decode_Wo_Vo,   OP_MOVAPS,    FLAG_SSE },
	{ "cvtpi2ps",   &Instruction::decode_Vo_Qq,   OP_CVTPI2PS,  FLAG_SSE },
	{ "movntps",    &Instruction::decode_Mo_Vo,   OP_MOVNTPS,   FLAG_SSE },
	{ "cvttps2pi",  &Instruction::decode_Pq_Wo,   OP_CVTTPS2PI, FLAG_SSE },
	{ "cvtps2pi",   &Instruction::decode_Pq_Wo,   OP_CVTPS2PI,  FLAG_SSE },
	{ "ucomiss",    &Instruction::decode_Vo_Wo,   OP_UCOMISS,   FLAG_SSE | FLAG_W_FLAGS },
	{ "comiss",     &Instruction::decode_Vo_Wo,   OP_COMISS,    FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr",    &Instruction::decode0,         OP_WRMSR,    FLAG_NONE },
	{ "rdtsc",    &Instruction::decode0,         OP_RDTSC,    FLAG_NONE },
	{ "rdmsr",    &Instruction::decode0,         OP_RDMSR,    FLAG_NONE },
	{ "rdpmc",    &Instruction::decode0,         OP_RDPMC,    FLAG_NONE },
	{ "sysenter", &Instruction::decode0,         OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit",  &Instruction::decode0,         OP_SYSEXIT,  FLAG_PENTIUM_PRO },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "getsec",   &Instruction::decode0,         OP_GETSEC,   FLAG_NONE },
	{ "3byte",    &Instruction::decode_3byte_38, OP_3BYTE,    FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "3byte",    &Instruction::decode_3byte_3A, OP_3BYTE,    FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtps",   &Instruction::decode_Vo_Wo, OP_SQRTPS,   FLAG_SSE },
	{ "rsqrtps",  &Instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &Instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andps",    &Instruction::decode_Vo_Wo, OP_ANDPS,    FLAG_SSE },
	{ "andnps",   &Instruction::decode_Vo_Wo, OP_ANDNPS,   FLAG_SSE },
	{ "orps",     &Instruction::decode_Vo_Wo, OP_ORPS,     FLAG_SSE },
	{ "xorps",    &Instruction::decode_Vo_Wo, OP_XORPS,    FLAG_SSE },
	{ "addps",    &Instruction::decode_Vo_Wo, OP_ADDPS,    FLAG_SSE },
	{ "mulps",    &Instruction::decode_Vo_Wo, OP_MULPS,    FLAG_SSE },
	{ "cvtps2pd", &Instruction::decode_Vo_Wo, OP_CVTPS2PD, FLAG_SSE2 },
	{ "cvtdq2ps", &Instruction::decode_Vo_Wo, OP_CVTDQ2PS, FLAG_SSE2 },
	{ "subps",    &Instruction::decode_Vo_Wo, OP_SUBPS,    FLAG_SSE },
	{ "minps",    &Instruction::decode_Vo_Wo, OP_MINPS,    FLAG_SSE },
	{ "divps",    &Instruction::decode_Vo_Wo, OP_DIVPS,    FLAG_SSE },
	{ "maxps",    &Instruction::decode_Vo_Wo, OP_MAXPS,    FLAG_SSE },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd,   OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &Instruction::decode_Pq_Qd,   OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &Instruction::decode_Pq_Qd,   OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb",  &Instruction::decode_Pq_Qq,   OP_PACKSSWB,  FLAG_MMX },
	{ "pcmpgtb",   &Instruction::decode_Pq_Qq,   OP_PCMPGTB,   FLAG_MMX },
	{ "pcmpgtw",   &Instruction::decode_Pq_Qq,   OP_PCMPGTW,   FLAG_MMX },
	{ "pcmpgtd",   &Instruction::decode_Pq_Qq,   OP_PCMPGTD,   FLAG_MMX },
	{ "packuswb",  &Instruction::decode_Pq_Qq,   OP_PACKUSWB,  FLAG_MMX },
	{ "punpckhbw", &Instruction::decode_Pq_Qd,   OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &Instruction::decode_Pq_Qd,   OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &Instruction::decode_Pq_Qd,   OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw",  &Instruction::decode_Pq_Qq,   OP_PACKSSDW,  FLAG_MMX },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movq",      &Instruction::decode_Pd_Eq,   OP_MOVQ,      FLAG_MMX }, // x86: movd Pd, Ed
	{ "movq",      &Instruction::decode_Pq_Qq,   OP_MOVQ,      FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufw", &Instruction::decode_Pq_Qq_Ib, OP_PSHUFW, FLAG_SSE },
	{ "group13", &Instruction::decode_group13, OP_GROUP, FLAG_NONE },
	{ "group14", &Instruction::decode_group14, OP_GROUP, FLAG_NONE },
	{ "group15", &Instruction::decode_group15, OP_GROUP, FLAG_NONE },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq, OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq, OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq, OP_PCMPEQD, FLAG_MMX },
	{ "emms", &Instruction::decode0, OP_EMMS, FLAG_MMX },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD, FLAG_VMX },   // x86: vmread Ed, Gq
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &Instruction::decode_Eq_Pd, OP_MOVQ, FLAG_MMX },       // x86: movq Ed,Pd
	{ "movq", &Instruction::decode_Qq_Pq, OP_MOVQ, FLAG_MMX },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &Instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &Instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &Instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &Instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &Instruction::decode_Ev_Gv,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss",     &Instruction::decode_Gv_Mp,   OP_LSS,     FLAG_NONE },
	{ "btr",     &Instruction::decode_Ev_Gv,   OP_BTR,     FLAG_W_FLAGS },
	{ "lfs",     &Instruction::decode_Gv_Mp,   OP_LFS,     FLAG_NONE },
	{ "lgs",     &Instruction::decode_Gv_Mp,   OP_LGS,     FLAG_NONE },
	{ "movzx",   &Instruction::decode_Gv_Eb,   OP_MOVZX,   FLAG_NONE },
	{ "movzx",   &Instruction::decode_Gv_Ew,   OP_MOVZX,   FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &Instruction::decode_group11, OP_GROUP,   FLAG_NONE },
	{ "group8",  &Instruction::decode_group8,  OP_GROUP,   FLAG_NONE },
	{ "btc",     &Instruction::decode_Ev_Gv,   OP_BTC,     FLAG_W_FLAGS },
	{ "bsf",     &Instruction::decode_Gv_Ev,   OP_BSF,     FLAG_W_FLAGS },
	{ "bsr",     &Instruction::decode_Gv_Ev,   OP_BSR,     FLAG_W_FLAGS },
	{ "movsx",   &Instruction::decode_Gv_Eb,   OP_MOVSX,   FLAG_NONE },
	{ "movsx",   &Instruction::decode_Gv_Ew,   OP_MOVSX,   FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd",   &Instruction::decode_Eb_Gb,       OP_XADD,   FLAG_NONE },
	{ "xadd",   &Instruction::decode_Ev_Gv,       OP_XADD,   FLAG_NONE },
	{ "cmpps",  &Instruction::decode_Vo_Wo_Ib,    OP_CMPPS,  FLAG_SSE },
	{ "movnti", &Instruction::decode_Nq_Gq,       OP_MOVNTI, FLAG_SSE2 }, // x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib,    OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib,    OP_SHUFPS, FLAG_SSE },
	{ "group9", &Instruction::decode_group9,      OP_GROUP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rAX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rCX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rDX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rBX,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rSP,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rBP,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rSI,         OP_BSWAP,  FLAG_NONE },
	{ "bswap",  &Instruction::decode_rDI,         OP_BSWAP,  FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "psrlw",    &Instruction::decode_Pq_Qq,   OP_PSRLW,    FLAG_MMX },
	{ "psrld",    &Instruction::decode_Pq_Qq,   OP_PSRLD,    FLAG_NONE },
	{ "psrlq",    &Instruction::decode_Pq_Qq,   OP_PSRLQ,    FLAG_MMX },
	{ "paddq",    &Instruction::decode_Pq_Qq,   OP_PADDQ,    FLAG_SSE2 },
	{ "pmullw",   &Instruction::decode_Pq_Qq,   OP_PMULLW,   FLAG_MMX },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pmovmskb", &Instruction::decode_Gd_Nq,   OP_PMOVMSKB, FLAG_SSE },
    { "psubusb",  &Instruction::decode_Pq_Qq,   OP_PSUBUSB,  FLAG_MMX },
    { "psubusw",  &Instruction::decode_Pq_Qq,   OP_PSUBUSW,  FLAG_MMX },
    { "pminub",   &Instruction::decode_Pq_Qq,   OP_PMINUB,   FLAG_SSE },
    { "pand",     &Instruction::decode_Pq_Qq,   OP_PAND,     FLAG_MMX },
    { "paddusb",  &Instruction::decode_Pq_Qq,   OP_PADDUSB,  FLAG_MMX },
    { "paddusw",  &Instruction::decode_Pq_Qq,   OP_PADDUSW,  FLAG_MMX },
    { "pmaxub",   &Instruction::decode_Pq_Qq,   OP_PMAXUB,   FLAG_SSE },
    { "pandn",    &Instruction::decode_Pq_Qq,   OP_PANDN,    FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb",   &Instruction::decode_Pq_Qq,   OP_PAVGB,   FLAG_SSE },
	{ "psraw",   &Instruction::decode_Pq_Qq,   OP_PSRAW,   FLAG_MMX },
	{ "psrad",   &Instruction::decode_Pq_Qq,   OP_PSRAD,   FLAG_MMX },
	{ "pavgw",   &Instruction::decode_Pq_Qq,   OP_PAVGW,   FLAG_SSE },
	{ "pmulhuw", &Instruction::decode_Pq_Qq,   OP_PMULHUW, FLAG_SSE },
	{ "pmulhw",  &Instruction::decode_Pq_Qq,   OP_PMULHW,  FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movntq",  &Instruction::decode_Mq_Pq,   OP_MOVNTQ,  FLAG_SSE },
	{ "psubsb",  &Instruction::decode_Pq_Qq,   OP_PSUBSB,  FLAG_MMX },
	{ "psubsw",  &Instruction::decode_Pq_Qq,   OP_PSUBSW,  FLAG_MMX },
	{ "pminsw",  &Instruction::decode_Pq_Qq,   OP_PMINSW,  FLAG_SSE },
	{ "por",     &Instruction::decode_Pq_Qq,   OP_POR,     FLAG_MMX },
	{ "paddsb",  &Instruction::decode_Pq_Qq,   OP_PADDSB,  FLAG_MMX },
	{ "paddsw",  &Instruction::decode_Pq_Qq,   OP_PADDSW,  FLAG_MMX },
	{ "pmaxsw",  &Instruction::decode_Pq_Qq,   OP_PMAXSW,  FLAG_SSE },
	{ "pxor",    &Instruction::decode_Pq_Qq,   OP_PXOR,    FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};


// 2 byte opcodes with a 66 prefix
template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_2Byte_66[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &Instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &Instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &Instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &Instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &Instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &Instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &Instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movupd",   &Instruction::decode_Vo_Wo,   OP_MOVUPD,   FLAG_SSE2 },
	{ "movupd",   &Instruction::decode_Wo_Vo,   OP_MOVUPD,   FLAG_SSE2 },
	{ "movlpd",   &Instruction::decode_Vq_Mq,   OP_MOVLPD,   FLAG_SSE2 },
	{ "movlpd",   &Instruction::decode_Mq_Vq,   OP_MOVLPD,   FLAG_SSE2 },
	{ "unpcklpd", &Instruction::decode_Vo_Wq,   OP_UNPCKLPD, FLAG_SSE2 },
	{ "unpckhpd", &Instruction::decode_Vo_Wq,   OP_UNPCKHPD, FLAG_SSE2 },
	{ "movhpd",   &Instruction::decode_Vq_Mq,   OP_MOVHPD,   FLAG_SSE2 },
	{ "movhpd",   &Instruction::decode_Mq_Vq,   OP_MOVHPD,   FLAG_SSE2 },
	{ "group17",  &Instruction::decode_group17, OP_GROUP,    FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "nop",      &Instruction::decode_Ev,      OP_NOP,      FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov",        &Instruction::decode_Rd_Cd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Rd_Dd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Cd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "mov",        &Instruction::decode_Dd_Rd,   OP_MOV,       FLAG_R_FLAGS },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",    &Instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "movapd",     &Instruction::decode_Vo_Wo,   OP_MOVAPD,    FLAG_SSE2 },
	{ "movapd",     &Instruction::decode_Wo_Vo,   OP_MOVAPD,    FLAG_SSE2 },
	{ "cvtpi2pd",   &Instruction::decode_Vo_Qq,   OP_CVTPI2PD,  FLAG_SSE2 },
	{ "movntpd",    &Instruction::decode_Mo_Vo,   OP_MOVNTPD,   FLAG_SSE2 },
	{ "cvttpd2pi",  &Instruction::decode_Pq_Wo,   OP_CVTTPD2PI, FLAG_SSE2 },
	{ "cvtpd2pi",   &Instruction::decode_Qq_Wo,   OP_CVTPD2PI,  FLAG_SSE2 },
	{ "ucomisd",    &Instruction::decode_Vo_Wo,   OP_UCOMISD,   FLAG_SSE2 },
	{ "comisd",     &Instruction::decode_Vo_Wo,   OP_COMISD,    FLAG_SSE2 | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &Instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskpd", &Instruction::decode_Gq_Uo, OP_MOVMSKPD, FLAG_SSE2 }, // x86: movmskpd Gd, Uo
	{ "sqrtpd",   &Instruction::decode_Vo_Wo, OP_SQRTPD,   FLAG_SSE2 },
	{ "rsqrtps",  &Instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &Instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andpd",    &Instruction::decode_Vo_Wo, OP_ANDPD,    FLAG_SSE2 },
	{ "andnpd",   &Instruction::decode_Vo_Wo, OP_ANDNPD,   FLAG_SSE2 },
	{ "orpd",     &Instruction::decode_Vo_Wo, OP_ORPD,     FLAG_SSE2 },
	{ "xorpd",    &Instruction::decode_Vo_Wo, OP_XORPD,    FLAG_SSE2 },
	{ "addpd",    &Instruction::decode_Vo_Wo, OP_ADDPD,    FLAG_SSE2 },
	{ "mulpd",    &Instruction::decode_Vo_Wo, OP_MULPD,    FLAG_SSE2 },
	{ "cvtpd2ps", &Instruction::decode_Vo_Wo, OP_CVTPD2PS, FLAG_SSE2 },
	{ "cvtps2dq", &Instruction::decode_Vo_Wo, OP_CVTPS2DQ, FLAG_SSE2 },
	{ "subpd",    &Instruction::decode_Vo_Wo, OP_SUBPD,    FLAG_SSE2 },
	{ "minpd",    &Instruction::decode_Vo_Wo, OP_MINPD,    FLAG_SSE2 },
	{ "divpd",    &Instruction::decode_Vo_Wo, OP_DIVPD,    FLAG_SSE2 },
	{ "maxpd",    &Instruction::decode_Vo_Wo, OP_MAXPD,    FLAG_SSE2 },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw",  &Instruction::decode_Vo_Wo, OP_PUNPCKLBW,  FLAG_MMX },
	{ "punpcklwd",  &Instruction::decode_Vo_Wo, OP_PUNPCKLWD,  FLAG_MMX },
	{ "punpckldq",  &Instruction::decode_Vo_Wo, OP_PUNPCKLDQ,  FLAG_MMX },
	{ "packsswb",   &Instruction::decode_Vo_Wo, OP_PACKSSWB,   FLAG_MMX },
	{ "pcmpgtb",    &Instruction::decode_Vo_Wo, OP_PCMPGTB,    FLAG_MMX },
	{ "pcmpgtw",    &Instruction::decode_Vo_Wo, OP_PCMPGTW,    FLAG_MMX },
	{ "pcmpgtd",    &Instruction::decode_Vo_Wo, OP_PCMPGTD,    FLAG_MMX },
	{ "packuswb",   &Instruction::decode_Vo_Wo, OP_PACKUSWB,   FLAG_MMX },
	{ "punpckhbw",  &Instruction::decode_Vo_Wo, OP_PUNPCKHBW,  FLAG_MMX },
	{ "punpckhwd",  &Instruction::decode_Vo_Wo, OP_PUNPCKHWD,  FLAG_MMX },
	{ "punpckhdq",  &Instruction::decode_Vo_Wo, OP_PUNPCKHDQ,  FLAG_MMX },
	{ "packssdw",   &Instruction::decode_Vo_Wo, OP_PACKSSDW,   FLAG_MMX },
	{ "punpcklqdq", &Instruction::decode_Vo_Wo, OP_PUNPCKLQDQ, FLAG_SSE2 },
	{ "punpckhqdq", &Instruction::decode_Vo_Wo, OP_PUNPCKHQDQ, FLAG_SSE2 },
	{ "movq",       &Instruction::decode_Vo_Eq, OP_MOVQ,       FLAG_MMX }, // x86: movd Vo, Ed
	{ "movq",       &Instruction::decode_Vo_Qq, OP_MOVQ,       FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufd",  &Instruction::decode_Vo_Wo_Ib, OP_PSHUFD,  FLAG_SSE2 },
	{ "group13", &Instruction::decode_group13,  OP_GROUP,   FLAG_NONE },
	{ "group14", &Instruction::decode_group14,  OP_GROUP,   FLAG_NONE },
	{ "group15", &Instruction::decode_group15,  OP_GROUP,   FLAG_NONE },
	{ "pcmpeqb", &Instruction::decode_Vo_Wo,    OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &Instruction::decode_Vo_Wo,    OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &Instruction::decode_Vo_Wo,    OP_PCMPEQD, FLAG_MMX },
	{ "emms",    &Instruction::decode0,         OP_EMMS,    FLAG_MMX },
	{ "vmread",  &Instruction::decode_Eq_Gq,    OP_VMREAD,  FLAG_VMX }, // x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq,    OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "haddpd",  &Instruction::decode_Vo_Wo,    OP_HADDPD,  FLAG_SSE3 },
	{ "hsubpd",  &Instruction::decode_Vo_Wo,    OP_HSUBPD,  FLAG_SSE3 },
	{ "movq",    &Instruction::decode_Eq_Vo,    OP_MOVD,    FLAG_MMX }, // x86: movd Ed, Vo
	{ "movdqa",  &Instruction::decode_Wo_Vo,    OP_MOVDQA,  FLAG_SSE2 },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &Instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &Instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &Instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &Instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &Instruction::decode_Ev_Gv,   OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss",     &Instruction::decode_Gv_Mp,   OP_LSS,     FLAG_NONE },
	{ "btr",     &Instruction::decode_Ev_Gv,   OP_BTR,     FLAG_W_FLAGS },
	{ "lfs",     &Instruction::decode_Gv_Mp,   OP_LFS,     FLAG_NONE },
	{ "lgs",     &Instruction::decode_Gv_Mp,   OP_LGS,     FLAG_NONE },
	{ "movzx",   &Instruction::decode_Gv_Eb,   OP_MOVZX,   FLAG_NONE },
	{ "movzx",   &Instruction::decode_Gv_Ew,   OP_MOVZX,   FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &Instruction::decode_group11, OP_GROUP,   FLAG_NONE },
	{ "group8",  &Instruction::decode_group8,  OP_GROUP,   FLAG_NONE },
	{ "btc",     &Instruction::decode_Ev_Gv,   OP_BTC,     FLAG_W_FLAGS },
	{ "bsf",     &Instruction::decode_Gv_Ev,   OP_BSF,     FLAG_W_FLAGS },
	{ "bsr",     &Instruction::decode_Gv_Ev,   OP_BSR,     FLAG_W_FLAGS },
	{ "movsx",   &Instruction::decode_Gv_Eb,   OP_MOVSX,   FLAG_NONE },
	{ "movsx",   &Instruction::decode_Gv_Ew,   OP_MOVSX,   FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmppd", &Instruction::decode_Vo_Wo_Ib, OP_CMPPD, FLAG_SSE2 },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Vo_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Vo, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Uo_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufpd", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPD, FLAG_SSE2 },
	{ "group9", &Instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubpd", &Instruction::decode_Vo_Wo, OP_ADDSUBPD, FLAG_SSE3 },
	{ "psrlw", &Instruction::decode_Vo_Wo, OP_PSRLW, FLAG_MMX },
	{ "psrld", &Instruction::decode_Vo_Wo, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &Instruction::decode_Vo_Wo, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &Instruction::decode_Vo_Wo, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &Instruction::decode_Vo_Wo, OP_PMULLW, FLAG_MMX },
	{ "movq", &Instruction::decode_Vo_Wo, OP_MOVQ, FLAG_MMX },
	{ "pmovmskb", &Instruction::decode_Gd_Uo, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &Instruction::decode_Vo_Wo, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &Instruction::decode_Vo_Wo, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &Instruction::decode_Vo_Wo, OP_PMINUB, FLAG_SSE },
    { "pand", &Instruction::decode_Vo_Wo, OP_PAND, FLAG_MMX },
    { "paddusb", &Instruction::decode_Vo_Wo, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &Instruction::decode_Vo_Wo, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &Instruction::decode_Vo_Wo, OP_PMAXUB, FLAG_SSE },
    { "pandn", &Instruction::decode_Vo_Wo, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Vo_Wo, OP_PAVGB, FLAG_SSE },
	{ "psraw", &Instruction::decode_Vo_Wo, OP_PSRAW, FLAG_MMX },
	{ "psrad", &Instruction::decode_Vo_Wo, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &Instruction::decode_Vo_Wo, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &Instruction::decode_Vo_Wo, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &Instruction::decode_Vo_Wo, OP_PMULHW, FLAG_MMX },
	{ "cvttpd2dq", &Instruction::decode_Vo_Wo, OP_CVTTPD2DQ, FLAG_SSE2 },
	{ "movntdq", &Instruction::decode_Mo_Vo, OP_MOVNTDQ, FLAG_SSE2 },
	{ "psubsb", &Instruction::decode_Vo_Wo, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &Instruction::decode_Vo_Wo, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &Instruction::decode_Vo_Wo, OP_PMINSW, FLAG_SSE },
	{ "por", &Instruction::decode_Vo_Wo, OP_POR, FLAG_MMX },
	{ "paddsb", &Instruction::decode_Vo_Wo, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &Instruction::decode_Vo_Wo, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &Instruction::decode_Vo_Wo, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &Instruction::decode_Vo_Wo, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &Instruction::decode_Vo_Wo, OP_PSLLW, FLAG_MMX },
	{ "pslld", &Instruction::decode_Vo_Wo, OP_PSLLD, FLAG_MMX },
	{ "psllq", &Instruction::decode_Vo_Wo, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &Instruction::decode_Vo_Wo, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &Instruction::decode_Vo_Wo, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &Instruction::decode_Vo_Wo, OP_PSADBW, FLAG_SSE },
	{ "maskmovdqu", &Instruction::decode_Vo_Uo, OP_MASKMOVDQU, FLAG_SSE2 },
	{ "psubb", &Instruction::decode_Vo_Wo, OP_PSUBB, FLAG_MMX },
	{ "psubw", &Instruction::decode_Vo_Wo, OP_PSUBW, FLAG_MMX },
	{ "psubd", &Instruction::decode_Vo_Wo, OP_PSUBD, FLAG_MMX },
	{ "psubq", &Instruction::decode_Vo_Wo, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &Instruction::decode_Vo_Wo, OP_PADDB, FLAG_MMX },
	{ "paddw", &Instruction::decode_Vo_Wo, OP_PADDW, FLAG_MMX },
	{ "paddd", &Instruction::decode_Vo_Wo, OP_PADDD, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

// 2 byte opcodes with a f2 prefix
template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_2Byte_F2[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &Instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &Instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &Instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &Instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &Instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &Instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &Instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movsd", &Instruction::decode_Vo_Wo, OP_MOVSD, FLAG_SSE2 },
	{ "movsd", &Instruction::decode_Wo_Vo, OP_MOVSD, FLAG_SSE2 },
	{ "movddup", &Instruction::decode_Vq_Mq, OP_MOVDDUP, FLAG_SSE3 },
	{ "movlps", &Instruction::decode_Mq_Vq, OP_MOVLPS, FLAG_SSE },
	{ "unpcklps", &Instruction::decode_Vo_Wq, OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &Instruction::decode_Vo_Wq, OP_UNPCKHPS, FLAG_SSE },
	{ "movhps", &Instruction::decode_Vq_Mq, OP_MOVHPS, FLAG_SSE },
	{ "movhps", &Instruction::decode_Mq_Vq, OP_MOVHPS, FLAG_SSE },
	{ "group17", &Instruction::decode_group17, OP_GROUP, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &Instruction::decode_Ev, OP_NOP, FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movaps", &Instruction::decode_Vo_Wo, OP_MOVAPS, FLAG_SSE },
	{ "movaps", &Instruction::decode_Wo_Vo, OP_MOVAPS, FLAG_SSE },
	{ "cvtsi2sd", &Instruction::decode_Vo_Eq, OP_CVTSI2SD, FLAG_SSE2 },    // x86: cvtsi2sd Vo, Ed
	{ "movntps",  &Instruction::decode_Mo_Vo, OP_MOVNTPS, FLAG_SSE },
	{ "cvttsd2si",  &Instruction::decode_Gq_Wo, OP_CVTTSD2SI, FLAG_SSE2 }, // x86: cvttsd2si Gd, Wo
	{ "cvtsd2si",  &Instruction::decode_Gq_Wo, OP_CVTSD2SI, FLAG_SSE2 },   // x86: cvtsd2si Gd, Wo
	{ "ucomiss",  &Instruction::decode_Vo_Wo, OP_UCOMISS, FLAG_SSE },
	{ "comiss",  &Instruction::decode_Vo_Wo, OP_COMISS, FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &Instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtsd",   &Instruction::decode_Vo_Wo, OP_SQRTSD,   FLAG_SSE2 },
	{ "rsqrtps",  &Instruction::decode_Vo_Wo, OP_RSQRTPS,  FLAG_SSE },
	{ "rcpps",    &Instruction::decode_Vo_Wo, OP_RCPPS,    FLAG_SSE },
	{ "andps",    &Instruction::decode_Vo_Wo, OP_ANDPS,    FLAG_SSE },
	{ "andnps",   &Instruction::decode_Vo_Wo, OP_ANDNPS,   FLAG_SSE },
	{ "orps",     &Instruction::decode_Vo_Wo, OP_ORPS,     FLAG_SSE },
	{ "xorps",    &Instruction::decode_Vo_Wo, OP_XORPS,    FLAG_SSE },
	{ "addsd",    &Instruction::decode_Vo_Wo, OP_ADDSD,    FLAG_SSE2 },
	{ "mulsd",    &Instruction::decode_Vo_Wo, OP_MULSD,    FLAG_SSE2 },
	{ "cvtsd2ss", &Instruction::decode_Vo_Wo, OP_CVTSD2SS, FLAG_SSE2 },
	{ "cvtdq2ps", &Instruction::decode_Vo_Wo, OP_CVTDQ2PS, FLAG_SSE2 },
	{ "subsd",    &Instruction::decode_Vo_Wo, OP_SUBSD,    FLAG_SSE2 },
	{ "minsd",    &Instruction::decode_Vo_Wo, OP_MINSD,    FLAG_SSE2 },
	{ "divsd",    &Instruction::decode_Vo_Wo, OP_DIVSD,    FLAG_SSE2 },
	{ "maxsd",    &Instruction::decode_Vo_Wo, OP_MAXSD,    FLAG_SSE2 },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd, OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &Instruction::decode_Pq_Qd, OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &Instruction::decode_Pq_Qd, OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb", &Instruction::decode_Pq_Qq, OP_PACKSSWB, FLAG_MMX },
	{ "pcmpgtb", &Instruction::decode_Pq_Qq, OP_PCMPGTB, FLAG_MMX },
	{ "pcmpgtw", &Instruction::decode_Pq_Qq, OP_PCMPGTW, FLAG_MMX },
	{ "pcmpgtd", &Instruction::decode_Pq_Qq, OP_PCMPGTD, FLAG_MMX },
	{ "packuswb", &Instruction::decode_Pq_Qq, OP_PACKUSWB, FLAG_MMX },
	{ "punpckhbw", &Instruction::decode_Pq_Qd, OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &Instruction::decode_Pq_Qd, OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &Instruction::decode_Pq_Qd, OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw", &Instruction::decode_Pq_Qq, OP_PACKSSDW, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &Instruction::decode_Pd_Eq, OP_MOVQ, FLAG_MMX }, // x86: movq Pd, Ed
	{ "movq", &Instruction::decode_Pq_Qq, OP_MOVQ, FLAG_MMX },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshuflw", &Instruction::decode_Vo_Wo_Ib, OP_PSHUFLW, FLAG_SSE2 },
	{ "group13", &Instruction::decode_group13,  OP_GROUP,   FLAG_NONE },
	{ "group14", &Instruction::decode_group14,  OP_GROUP,   FLAG_NONE },
	{ "group15", &Instruction::decode_group15,  OP_GROUP,   FLAG_NONE },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq,    OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq,    OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq,    OP_PCMPEQD, FLAG_MMX },
	{ "emms",    &Instruction::decode0,         OP_EMMS,    FLAG_MMX },
	{ "vmread",  &Instruction::decode_Eq_Gq,    OP_VMREAD,  FLAG_VMX }, // x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq,    OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "haddps",  &Instruction::decode_Vo_Wo,    OP_HADDPS,  FLAG_SSE3 },
	{ "hsubps",  &Instruction::decode_Vo_Wo,    OP_HSUBPS,  FLAG_SSE3 },
	{ "movq",    &Instruction::decode_Eq_Pd,    OP_MOVD,    FLAG_MMX }, // x86: movq Ed, Pd
	{ "movq",    &Instruction::decode_Qq_Pq,    OP_MOVQ,    FLAG_MMX },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &Instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &Instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &Instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &Instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS, FLAG_NONE },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR, FLAG_W_FLAGS },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS, FLAG_NONE },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS, FLAG_NONE },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX, FLAG_NONE },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "group11", &Instruction::decode_group11, OP_GROUP, FLAG_NONE },
	{ "group8", &Instruction::decode_group8, OP_GROUP, FLAG_NONE },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC, FLAG_W_FLAGS },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF, FLAG_W_FLAGS },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR, FLAG_W_FLAGS },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX, FLAG_NONE },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX, FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmpsd", &Instruction::decode_Vo_Wo_Ib, OP_CMPSD, FLAG_SSE2 },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPS, FLAG_SSE },
	{ "group9", &Instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "addsubps", &Instruction::decode_Vo_Wo, OP_ADDSUBPS, FLAG_SSE3 },
	{ "psrlw", &Instruction::decode_Pq_Qq, OP_PSRLW, FLAG_MMX },
	{ "psrld", &Instruction::decode_Pq_Qq, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &Instruction::decode_Pq_Qq, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &Instruction::decode_Pq_Qq, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &Instruction::decode_Pq_Qq, OP_PMULLW, FLAG_MMX },
	{ "movdq2q", &Instruction::decode_Pq_Qq, OP_MOVDQ2Q, FLAG_SSE2 },
	{ "pmovmskb", &Instruction::decode_Gd_Nq, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &Instruction::decode_Pq_Qq, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &Instruction::decode_Pq_Qq, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &Instruction::decode_Pq_Qq, OP_PMINUB, FLAG_SSE },
    { "pand", &Instruction::decode_Pq_Qq, OP_PAND, FLAG_MMX },
    { "paddusb", &Instruction::decode_Pq_Qq, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &Instruction::decode_Pq_Qq, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &Instruction::decode_Pq_Qq, OP_PMAXUB, FLAG_SSE },
    { "pandn", &Instruction::decode_Pq_Qq, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Pq_Qq, OP_PAVGB, FLAG_SSE },
	{ "psraw", &Instruction::decode_Pq_Qq, OP_PSRAW, FLAG_MMX },
	{ "psrad", &Instruction::decode_Pq_Qq, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &Instruction::decode_Pq_Qq, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &Instruction::decode_Pq_Qq, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &Instruction::decode_Pq_Qq, OP_PMULHW, FLAG_MMX },
	{ "cvtpd2dq", &Instruction::decode_Vo_Wo, OP_CVTPD2DQ, FLAG_SSE2 },
	{ "movntq", &Instruction::decode_Mq_Pq, OP_MOVNTQ, FLAG_SSE },
	{ "psubsb", &Instruction::decode_Pq_Qq, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &Instruction::decode_Pq_Qq, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &Instruction::decode_Pq_Qq, OP_PMINSW, FLAG_SSE },
	{ "por", &Instruction::decode_Pq_Qq, OP_POR, FLAG_MMX },
	{ "paddsb", &Instruction::decode_Pq_Qq, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &Instruction::decode_Pq_Qq, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &Instruction::decode_Pq_Qq, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &Instruction::decode_Pq_Qq, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "lddqu", &Instruction::decode_Vo_Mo, OP_LDDQU, FLAG_SSE3 },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

// 2 byte opcodes with a f3 prefix
template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_2Byte_F3[0x100] = {

	/* 0x0f 0x00 - 0x0f 0x0f */
	{ "group6", &Instruction::decode_group6, OP_GROUP, FLAG_NONE },
	{ "group7", &Instruction::decode_group7, OP_GROUP, FLAG_NONE },
	{ "lar", &Instruction::decode_Gv_Ew, OP_LAR, FLAG_W_FLAGS },
	{ "lsl", &Instruction::decode_Gv_Ew, OP_LSL, FLAG_W_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "syscall", &Instruction::decode0, OP_SYSCALL, FLAG_64BIT_ONLY },
	{ "clts", &Instruction::decode0, OP_CLTS, FLAG_W_FLAGS },
	{ "sysret", &Instruction::decode0, OP_SYSRET, FLAG_64BIT_ONLY },
	{ "invd", &Instruction::decode0, OP_INVD, FLAG_NONE },
	{ "wbinvd", &Instruction::decode0, OP_WBINVD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "ud2", &Instruction::decode0, OP_UD2, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop", &Instruction::decode_Ev, OP_NOP, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x10 - 0x0f 0x1f */
	{ "movss",    &Instruction::decode_Vo_Wo, OP_MOVSS, FLAG_SSE },
	{ "movss",    &Instruction::decode_Wo_Vo, OP_MOVSS, FLAG_SSE },
	{ "movsldup", &Instruction::decode_Vq_Wq, OP_MOVSLDUP, FLAG_SSE3 },
	{ "movlps",   &Instruction::decode_Mq_Vq, OP_MOVLPS, FLAG_SSE },
	{ "unpcklps", &Instruction::decode_Vo_Wq, OP_UNPCKLPS, FLAG_SSE },
	{ "unpckhps", &Instruction::decode_Vo_Wq, OP_UNPCKHPS, FLAG_SSE },
	{ "movshdup", &Instruction::decode_Vq_Wq, OP_MOVSHDUP, FLAG_SSE3 },
	{ "movhps",   &Instruction::decode_Mq_Vq, OP_MOVHPS, FLAG_SSE },
	{ "group17",  &Instruction::decode_group17, OP_GROUP, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "nop",      &Instruction::decode_Ev, OP_NOP, FLAG_NONE },

	/* 0x0f 0x20 - 0x0f 0x2f */
	{ "mov", &Instruction::decode_Rd_Cd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Rd_Dd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Cd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "mov", &Instruction::decode_Dd_Rd, OP_MOV, FLAG_R_FLAGS },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movaps", &Instruction::decode_Vo_Wo, OP_MOVAPS, FLAG_SSE },
	{ "movaps", &Instruction::decode_Wo_Vo, OP_MOVAPS, FLAG_SSE },
	{ "cvtsi2ss", &Instruction::decode_Vo_Eq, OP_CVTSI2SS, FLAG_SSE }, // x86: cvtsi2ss Vo, Ed
	{ "movntps",  &Instruction::decode_Mo_Vo, OP_MOVNTPS, FLAG_SSE },
	{ "cvttss2si",  &Instruction::decode_Gq_Wo, OP_CVTTSS2SI, FLAG_SSE }, // x86: cvttss2si Gd, Wo
	{ "cvtss2si",  &Instruction::decode_Gq_Wo, OP_CVTSS2SI, FLAG_SSE }, // x86: cvtss2si Gd, Wo
	{ "ucomiss",  &Instruction::decode_Vo_Wo, OP_UCOMISS, FLAG_SSE },
	{ "comiss",  &Instruction::decode_Vo_Wo, OP_COMISS, FLAG_SSE | FLAG_W_FLAGS },

	/* 0x0f 0x30 - 0x0f 0x3f */
	{ "wrmsr", &Instruction::decode0, OP_WRMSR, FLAG_NONE },
	{ "rdtsc", &Instruction::decode0, OP_RDTSC, FLAG_NONE },
	{ "rdmsr", &Instruction::decode0, OP_RDMSR, FLAG_NONE },
	{ "rdpmc", &Instruction::decode0, OP_RDPMC, FLAG_NONE },
	{ "sysenter", &Instruction::decode0, OP_SYSENTER, FLAG_PENTIUM_PRO },
	{ "sysexit", &Instruction::decode0, OP_SYSEXIT, FLAG_PENTIUM_PRO },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "getsec", &Instruction::decode0, OP_GETSEC, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_38, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "3byte", &Instruction::decode_3byte_3A, OP_3BYTE, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x40 - 0x0f 0x4f */
	{ "cmovo",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovno",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnb",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovz",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnz",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovb",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnbe", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovs",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovns",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovp",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnp",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovl",   &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnl",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovle",  &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },
	{ "cmovnle", &Instruction::decode_Gv_Ev, OP_CMOVCC, FLAG_R_FLAGS | FLAG_PENTIUM_PRO },

	/* 0x0f 0x50 - 0x0f 0x5f */
	{ "movmskps", &Instruction::decode_Gq_Uo, OP_MOVMSKPS, FLAG_SSE }, // x86: movmskps Gd, Uo
	{ "sqrtss", &Instruction::decode_Vo_Wo, OP_SQRTSS, FLAG_SSE },
	{ "rsqrtss", &Instruction::decode_Vo_Wo, OP_RSQRTSS, FLAG_SSE },
	{ "rcpss", &Instruction::decode_Vo_Wo, OP_RCPSS, FLAG_SSE },
	{ "andps", &Instruction::decode_Vo_Wo, OP_ANDPS, FLAG_SSE },
	{ "andnps", &Instruction::decode_Vo_Wo, OP_ANDNPS, FLAG_SSE },
	{ "orps", &Instruction::decode_Vo_Wo, OP_ORPS, FLAG_SSE },
	{ "xorps", &Instruction::decode_Vo_Wo, OP_XORPS, FLAG_SSE },
	{ "addss", &Instruction::decode_Vo_Wo, OP_ADDSS, FLAG_SSE },
	{ "mulss", &Instruction::decode_Vo_Wo, OP_MULSS, FLAG_SSE },
	{ "cvtss2sd", &Instruction::decode_Vo_Wo, OP_CVTSS2SD, FLAG_SSE2 },
	{ "cvttps2dq", &Instruction::decode_Vo_Wo, OP_CVTTPS2DQ, FLAG_SSE2 },
	{ "subss", &Instruction::decode_Vo_Wo, OP_SUBSS, FLAG_SSE },
	{ "minss", &Instruction::decode_Vo_Wo, OP_MINSS, FLAG_SSE },
	{ "divss", &Instruction::decode_Vo_Wo, OP_DIVSS, FLAG_SSE },
	{ "maxss", &Instruction::decode_Vo_Wo, OP_MAXSS, FLAG_SSE },

	/* 0x0f 0x60 - 0x0f 0x6f */
	{ "punpcklbw", &Instruction::decode_Pq_Qd, OP_PUNPCKLBW, FLAG_MMX },
	{ "punpcklwd", &Instruction::decode_Pq_Qd, OP_PUNPCKLWD, FLAG_MMX },
	{ "punpckldq", &Instruction::decode_Pq_Qd, OP_PUNPCKLDQ, FLAG_MMX },
	{ "packsswb", &Instruction::decode_Pq_Qq, OP_PACKSSWB, FLAG_MMX },
	{ "pcmpgtb", &Instruction::decode_Pq_Qq, OP_PCMPGTB, FLAG_MMX },
	{ "pcmpgtw", &Instruction::decode_Pq_Qq, OP_PCMPGTW, FLAG_MMX },
	{ "pcmpgtd", &Instruction::decode_Pq_Qq, OP_PCMPGTD, FLAG_MMX },
	{ "packuswb", &Instruction::decode_Pq_Qq, OP_PACKUSWB, FLAG_MMX },
	{ "punpckhbw", &Instruction::decode_Pq_Qd, OP_PUNPCKHBW, FLAG_MMX },
	{ "punpckhwd", &Instruction::decode_Pq_Qd, OP_PUNPCKHWD, FLAG_MMX },
	{ "punpckhdq", &Instruction::decode_Pq_Qd, OP_PUNPCKHDQ, FLAG_MMX },
	{ "packssdw", &Instruction::decode_Pq_Qq, OP_PACKSSDW, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &Instruction::decode_Pd_Eq, OP_MOVQ, FLAG_MMX }, // x86: movq Pd, Ed
	{ "movdqu", &Instruction::decode_Vo_Wo, OP_MOVDQU, FLAG_SSE2 },

	/* 0x0f 0x70 - 0x0f 0x7f */
	{ "pshufhw", &Instruction::decode_Vo_Wo_Ib, OP_PSHUFHW, FLAG_SSE2 },
	{ "group13", &Instruction::decode_group13, OP_GROUP, FLAG_NONE },
	{ "group14", &Instruction::decode_group14, OP_GROUP, FLAG_NONE },
	{ "group15", &Instruction::decode_group15, OP_GROUP, FLAG_NONE },
	{ "pcmpeqb", &Instruction::decode_Pq_Qq, OP_PCMPEQB, FLAG_MMX },
	{ "pcmpeqw", &Instruction::decode_Pq_Qq, OP_PCMPEQW, FLAG_MMX },
	{ "pcmpeqd", &Instruction::decode_Pq_Qq, OP_PCMPEQD, FLAG_MMX },
	{ "emms", &Instruction::decode0, OP_EMMS, FLAG_MMX },
	{ "vmread", &Instruction::decode_Eq_Gq, OP_VMREAD, FLAG_VMX },   // x86: vmread Ed, Gd
	{ "vmwrite", &Instruction::decode_Gq_Eq, OP_VMWRITE, FLAG_VMX }, // x86: vmwrite Gd, Ed
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "movq", &Instruction::decode_Vq_Wq, OP_MOVQ, FLAG_MMX },
	{ "movdqu", &Instruction::decode_Wo_Vo, OP_MOVDQU, FLAG_SSE2 },

	/* 0x0f 0x80 - 0x0f 0x8f */
	{ "jo",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jno",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jb",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnb",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jz",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnz",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jbe",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnbe", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "js",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jns",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jp",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnp",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jl",   &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnl",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jle",  &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },
	{ "jnle", &Instruction::decode_Jz, OP_JCC, FLAG_R_FLAGS },

	/* 0x0f 0x90 - 0x0f 0x9f */
	{ "seto",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setno",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setb",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnb",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setz",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnz",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setbe",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnbe", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "sets",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setns",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setp",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnp",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setl",   &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnl",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setle",  &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },
	{ "setnle", &Instruction::decode_Eb, OP_SETCC, FLAG_R_FLAGS },

	/* 0x0f 0xa0 - 0x0f 0xaf */
	{ "push", &Instruction::decode_Reg<operand_type::REG_FS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_FS>, OP_POP, FLAG_STACK },
	{ "cpuid", &Instruction::decode0, OP_CPUID, FLAG_NONE },
	{ "bt", &Instruction::decode_Ev_Gv, OP_BT, FLAG_W_FLAGS },
	{ "shld", &Instruction::decode_Ev_Gv_Ib, OP_SHLD, FLAG_NONE },
	{ "shld", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHLD, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "push", &Instruction::decode_Reg<operand_type::REG_GS>, OP_PUSH, FLAG_STACK },
	{ "pop", &Instruction::decode_Reg<operand_type::REG_GS>, OP_POP, FLAG_STACK },
	{ "rsm", &Instruction::decode0, OP_RSM, FLAG_NONE },
	{ "bts", &Instruction::decode_Ev_Gv, OP_BTS, FLAG_W_FLAGS },
	{ "shrd", &Instruction::decode_Ev_Gv_Ib, OP_SHRD, FLAG_NONE },
	{ "shrd", &Instruction::decode_Ev_Gv_Reg<operand_type::REG_CL>, OP_SHRD, FLAG_NONE },
	{ "group16", &Instruction::decode_group16, OP_GROUP, FLAG_NONE },
	{ "imul",  &Instruction::decode_Gv_Ev, OP_IMUL, FLAG_W_FLAGS },

	/* 0x0f 0xb0 - 0x0f 0xbf */
	{ "cmpxchg", &Instruction::decode_Eb_Gb, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "cmpxchg", &Instruction::decode_Ev_Gv, OP_CMPXCHG, FLAG_W_FLAGS },
	{ "lss", &Instruction::decode_Gv_Mp, OP_LSS, FLAG_NONE },
	{ "btr", &Instruction::decode_Ev_Gv, OP_BTR, FLAG_W_FLAGS },
	{ "lfs", &Instruction::decode_Gv_Mp, OP_LFS, FLAG_NONE },
	{ "lgs", &Instruction::decode_Gv_Mp, OP_LGS, FLAG_NONE },
	{ "movzx", &Instruction::decode_Gv_Eb, OP_MOVZX, FLAG_NONE },
	{ "movzx", &Instruction::decode_Gv_Ew, OP_MOVZX, FLAG_NONE },
	{ "popcnt", &Instruction::decode_Gv_Ev, OP_POPCNT, FLAG_SSE4a },
	{ "group11", &Instruction::decode_group11, OP_GROUP, FLAG_NONE },
	{ "group8", &Instruction::decode_group8, OP_GROUP, FLAG_NONE },
	{ "btc", &Instruction::decode_Ev_Gv, OP_BTC, FLAG_W_FLAGS },
	{ "bsf", &Instruction::decode_Gv_Ev, OP_BSF, FLAG_W_FLAGS },
	{ "bsr", &Instruction::decode_Gv_Ev, OP_BSR, FLAG_W_FLAGS },
	{ "movsx", &Instruction::decode_Gv_Eb, OP_MOVSX, FLAG_NONE },
	{ "movsx", &Instruction::decode_Gv_Ew, OP_MOVSX, FLAG_NONE },

	/* 0x0f 0xc0 - 0x0f 0xcf */
	{ "xadd", &Instruction::decode_Eb_Gb, OP_XADD, FLAG_NONE },
	{ "xadd", &Instruction::decode_Ev_Gv, OP_XADD, FLAG_NONE },
	{ "cmpss", &Instruction::decode_Vo_Wo_Ib, OP_CMPSS, FLAG_SSE },
	{ "movnti", &Instruction::decode_Nq_Gq, OP_MOVNTI, FLAG_SSE2 },       // x86: movnti Md, Gd
	{ "pinsrw", &Instruction::decode_Pq_Rq_Mw_Ib, OP_PINSRW, FLAG_SSE }, // x86: pinsrw Pq, Rd/Mw,Ib
	{ "pextrw", &Instruction::decode_Gd_Nq_Ib, OP_PEXTRW, FLAG_SSE | FLAG_SSE4_1 },
	{ "shufps", &Instruction::decode_Vo_Wo_Ib, OP_SHUFPS, FLAG_SSE },
	{ "group9", &Instruction::decode_group9, OP_GROUP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rAX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rCX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBX, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rBP, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rSI, OP_BSWAP, FLAG_NONE },
	{ "bswap", &Instruction::decode_rDI, OP_BSWAP, FLAG_NONE },

	/* 0x0f 0xd0 - 0x0f 0xdf */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psrlw", &Instruction::decode_Pq_Qq, OP_PSRLW, FLAG_MMX },
	{ "psrld", &Instruction::decode_Pq_Qq, OP_PSRLD, FLAG_NONE },
	{ "psrlq", &Instruction::decode_Pq_Qq, OP_PSRLQ, FLAG_MMX },
	{ "paddq", &Instruction::decode_Pq_Qq, OP_PADDQ, FLAG_SSE2 },
	{ "pmullw", &Instruction::decode_Pq_Qq, OP_PMULLW, FLAG_MMX },
	{ "movq2dq", &Instruction::decode_Vo_Nq, OP_MOVQ2DQ, FLAG_SSE2 },
	{ "pmovmskb", &Instruction::decode_Gd_Nq, OP_PMOVMSKB, FLAG_SSE },
    { "psubusb", &Instruction::decode_Pq_Qq, OP_PSUBUSB, FLAG_MMX },
    { "psubusw", &Instruction::decode_Pq_Qq, OP_PSUBUSW, FLAG_MMX },
    { "pminub", &Instruction::decode_Pq_Qq, OP_PMINUB, FLAG_SSE },
    { "pand", &Instruction::decode_Pq_Qq, OP_PAND, FLAG_MMX },
    { "paddusb", &Instruction::decode_Pq_Qq, OP_PADDUSB, FLAG_MMX },
    { "paddusw", &Instruction::decode_Pq_Qq, OP_PADDUSW, FLAG_MMX },
    { "pmaxub", &Instruction::decode_Pq_Qq, OP_PMAXUB, FLAG_SSE },
    { "pandn", &Instruction::decode_Pq_Qq, OP_PANDN, FLAG_MMX },

	/* 0x0f 0xe0 - 0x0f 0xef */
	{ "pavgb", &Instruction::decode_Pq_Qq, OP_PAVGB, FLAG_SSE },
	{ "psraw", &Instruction::decode_Pq_Qq, OP_PSRAW, FLAG_MMX },
	{ "psrad", &Instruction::decode_Pq_Qq, OP_PSRAD, FLAG_MMX },
	{ "pavgw", &Instruction::decode_Pq_Qq, OP_PAVGW, FLAG_SSE },
	{ "pmulhuw", &Instruction::decode_Pq_Qq, OP_PMULHUW, FLAG_SSE },
	{ "pmulhw", &Instruction::decode_Pq_Qq, OP_PMULHW, FLAG_MMX },
	{ "cvtdq2pd", &Instruction::decode_Vo_Wo, OP_CVTDQ2PD, FLAG_SSE2 },
	{ "movntq", &Instruction::decode_Mq_Pq, OP_MOVNTQ, FLAG_SSE },
	{ "psubsb", &Instruction::decode_Pq_Qq, OP_PSUBSB, FLAG_MMX },
	{ "psubsw", &Instruction::decode_Pq_Qq, OP_PSUBSW, FLAG_MMX },
	{ "pminsw", &Instruction::decode_Pq_Qq, OP_PMINSW, FLAG_SSE },
	{ "por", &Instruction::decode_Pq_Qq, OP_POR, FLAG_MMX },
	{ "paddsb", &Instruction::decode_Pq_Qq, OP_PADDSB, FLAG_MMX },
	{ "paddsw", &Instruction::decode_Pq_Qq, OP_PADDSW, FLAG_MMX },
	{ "pmaxsw", &Instruction::decode_Pq_Qq, OP_PMAXSW, FLAG_SSE },
	{ "pxor", &Instruction::decode_Pq_Qq, OP_PXOR, FLAG_MMX },

	/* 0x0f 0xf0 - 0x0f 0xff */
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllw", &Instruction::decode_Pq_Qq, OP_PSLLW, FLAG_MMX },
	{ "pslld", &Instruction::decode_Pq_Qq, OP_PSLLD, FLAG_MMX },
	{ "psllq", &Instruction::decode_Pq_Qq, OP_PSLLQ, FLAG_MMX },
	{ "pmuludq", &Instruction::decode_Pq_Qq, OP_PMULUDQ, FLAG_SSE2 },
	{ "pmaddwd", &Instruction::decode_Pq_Qq, OP_PMADDWD, FLAG_MMX },
	{ "psadbw", &Instruction::decode_Pq_Qq, OP_PSADBW, FLAG_SSE },
	{ "maskmovq", &Instruction::decode_Pq_Nq, OP_MASKMOVQ, FLAG_SSE },
	{ "psubb", &Instruction::decode_Pq_Qq, OP_PSUBB, FLAG_MMX },
	{ "psubw", &Instruction::decode_Pq_Qq, OP_PSUBW, FLAG_MMX },
	{ "psubd", &Instruction::decode_Pq_Qq, OP_PSUBD, FLAG_MMX },
	{ "psubq", &Instruction::decode_Pq_Qq, OP_PSUBQ, FLAG_SSE2 },
	{ "paddb", &Instruction::decode_Pq_Qq, OP_PADDB, FLAG_MMX },
	{ "paddw", &Instruction::decode_Pq_Qq, OP_PADDW, FLAG_MMX },
	{ "paddd", &Instruction::decode_Pq_Qq, OP_PADDD, FLAG_MMX },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};


template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_3Byte_38_66[0x100] = {

	/* 0x0f 0x38 0x00 - 0x0f 0x38 0x0f */
	{ "pshufb", &Instruction::decode_Vo_Wo, OP_PSHUFB, FLAG_SSSE3 },
	{ "phaddw", &Instruction::decode_Vo_Wo, OP_PHADDW, FLAG_SSSE3 },
	{ "phaddd", &Instruction::decode_Vo_Wo, OP_PHADDD, FLAG_SSSE3 },
	{ "phaddsw", &Instruction::decode_Vo_Wo, OP_PHADDSW, FLAG_SSSE3 },
	{ "pmaddubsw", &Instruction::decode_Vo_Wo, OP_PMADDUBSW, FLAG_SSSE3 },
	{ "phsubw", &Instruction::decode_Vo_Wo, OP_PHSUBW, FLAG_SSSE3 },
	{ "phsubd", &Instruction::decode_Vo_Wo, OP_PHSUBD, FLAG_SSSE3 },
	{ "phsubsw", &Instruction::decode_Vo_Wo, OP_PHSUBSW, FLAG_SSSE3 },
	{ "psignb", &Instruction::decode_Vo_Wo, OP_PSIGNB, FLAG_SSSE3 },
	{ "psignw", &Instruction::decode_Vo_Wo, OP_PSIGNW, FLAG_SSSE3 },
	{ "psignd", &Instruction::decode_Vo_Wo, OP_PSIGND, FLAG_SSSE3 },
	{ "pmulhrsw", &Instruction::decode_Vo_Wo, OP_PMULHRSW, FLAG_SSSE3 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x10 - 0x0f 0x38 0x1f */
	{ "pblendvb", &Instruction::decode_Vo_Wo,   OP_PBLENDVB, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "blendvps", &Instruction::decode_Vo_Wo,   OP_BLENDVPS, FLAG_SSE4_1 },
	{ "blendvpd", &Instruction::decode_Vo_Wo,   OP_BLENDVPD, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "ptest",    &Instruction::decode_Vo_Wo,   OP_PTEST,    FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "pabsb",    &Instruction::decode_Vo_Wo,   OP_PABSB,    FLAG_SSSE3 },
	{ "pabsw",    &Instruction::decode_Vo_Wo,   OP_PABSW,    FLAG_SSSE3 },
	{ "pabsd",    &Instruction::decode_Vo_Wo,   OP_PABSD,    FLAG_SSSE3 },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x20 - 0x0f 0x38 0x2f */
	{ "pmovsxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXBW, FLAG_SSE4_1 },
	{ "pmovsxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXBD, FLAG_SSE4_1 },
	{ "pmovsxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVSXBQ, FLAG_SSE4_1 },
	{ "pmovsxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXWD, FLAG_SSE4_1 },
	{ "pmovsxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVSXWQ, FLAG_SSE4_1 },
	{ "pmovsxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVSXDQ, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "pmuldq",   &Instruction::decode_Vo_Wo,    OP_PMULDQ,   FLAG_SSE4_1 },
	{ "pcmpeqq",  &Instruction::decode_Vo_Wo,    OP_PCMPEQQ,  FLAG_SSE4_1 },
	{ "movntdqa", &Instruction::decode_Vo_Mo,    OP_MOVNTDQA, FLAG_SSE4_1 },
	{ "packusdw", &Instruction::decode_Vo_Wo,    OP_PACKUSDW, FLAG_SSE4_1 },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x38 0x30 - 0x0f 0x38 0x3f */
	{ "pmovzxbw", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXBW, FLAG_SSE4_1 },
	{ "pmovzxbd", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXBD, FLAG_SSE4_1 },
	{ "pmovzxbq", &Instruction::decode_Vo_Uo_Mw, OP_PMOVZXBQ, FLAG_SSE4_1 },
	{ "pmovzxwd", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXWD, FLAG_SSE4_1 },
	{ "pmovzxwq", &Instruction::decode_Vo_Uo_Md, OP_PMOVZXWQ, FLAG_SSE4_1 },
	{ "pmovzxdq", &Instruction::decode_Vo_Uo_Mq, OP_PMOVZXDQ, FLAG_SSE4_1 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "pcmpgtq", &Instruction::decode_Vo_Wo, OP_PCMPGTQ, FLAG_SSE4_2 },
	{ "pminsb", &Instruction::decode_Vo_Wo, OP_PMINSB, FLAG_SSE4_1 },
	{ "pminsd", &Instruction::decode_Vo_Wo, OP_PMINSD, FLAG_SSE4_1 },
	{ "pminuw", &Instruction::decode_Vo_Wo, OP_PMINUW, FLAG_SSE4_1 },
	{ "pminud", &Instruction::decode_Vo_Wo, OP_PMINUD, FLAG_SSE4_1 },
	{ "pmaxsb", &Instruction::decode_Vo_Wo, OP_PMAXSB, FLAG_SSE4_1 },
	{ "pmaxsd", &Instruction::decode_Vo_Wo, OP_PMAXSD, FLAG_SSE4_1 },
	{ "pmaxuw", &Instruction::decode_Vo_Wo, OP_PMAXUW, FLAG_SSE4_1 },
	{ "pmaxud", &Instruction::decode_Vo_Wo, OP_PMAXUD, FLAG_SSE4_1 },

	/* 0x0f 0x38 0x40 - 0x0f 0x38 0x4f */
	{ "pmulld", &Instruction::decode_Vo_Wo, OP_PMULLD, FLAG_SSE4_1 },
	{ "phminposuw", &Instruction::decode_Vo_Wo, OP_PHMINPOSUW, FLAG_SSE4_1 },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

	/* 0x0f 0x38 0x50 - 0x0f 0x38 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x60 - 0x0f 0x38 0x6f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x70 - 0x0f 0x38 0x7f */
	INVALID_BLOCK,

	/* 0x0f 0x38 0x80 - 0x0f 0x38 0x8f */
	{ "nvept",   &Instruction::decode_Gq_Mo,   OP_NVEPT,   FLAG_NONE }, // x86: nvept Gd, Mo
	{ "nvvpid",  &Instruction::decode_Gq_Mo,   OP_NVVPID,  FLAG_NONE }, // x86: nvvpid Gd, Mo
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },

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
	{ "movbe",   &Instruction::decode_Gv_Mv,   OP_MOVBE,   FLAG_NONE },
	{ "movbe",   &Instruction::decode_Mv_Gv,   OP_MOVBE,   FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

template <>
const Instruction<x86_64>::opcode_entry Instruction<x86_64>::Opcodes_3Byte_3A_66[0x100] = {
	/* 0x0f 0x3a 0x00 - 0x0f 0x3a 0x0f */
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "roundps", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPS, FLAG_SSE4_1 },
	{ "roundpd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDPD, FLAG_SSE4_1 },
	{ "roundss", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSS, FLAG_SSE4_1 },
	{ "roundsd", &Instruction::decode_Vo_Wo_Ib, OP_ROUNDSD, FLAG_SSE4_1 },
	{ "blendps", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPS, FLAG_SSE4_1 },
	{ "blendpd", &Instruction::decode_Vo_Wo_Ib, OP_BLENDPD, FLAG_SSE4_1 },
	{ "pblendw", &Instruction::decode_Vo_Wo_Ib, OP_PBLENDW, FLAG_SSE4_1 },
	{ "palignr", &Instruction::decode_Vo_Wo_Ib, OP_PALIGNR, FLAG_SSSE3 },

	/* 0x0f 0x3a 0x10 - 0x0f 0x3a 0x1f */
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "pextrb",    &Instruction::decode_Rd_Mb_Vo_Ib, OP_PEXTRB,    FLAG_SSE4_1 },
	{ "pextrw",    &Instruction::decode_Rd_Mw_Vo_Ib, OP_PEXTRW,    FLAG_SSE | FLAG_SSE4_1 },
	{ "pextrq",    &Instruction::decode_Eq_Vo_Ib,    OP_PEXTRQ,    FLAG_NONE }, // x86: pextrq Eq, Vo, Ib
	{ "extractps", &Instruction::decode_Ed_Vo_Ib,    OP_EXTRACTPS, FLAG_SSE4_1 }, // x86: extractps Ed, Vo, Ib // TODO: figure out if this should allow RAX or not?
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,     OP_INVALID,   FLAG_NONE },

	/* 0x0f 0x3a 0x20 - 0x0f 0x3a 0x2f */
	{ "pinsrb",   &Instruction::decode_Vo_Mb_Ib, OP_PINSRB,   FLAG_SSE4_1 },
	{ "insertps", &Instruction::decode_Vo_Md_Ib, OP_INSERTPS, FLAG_SSE4_1 },
	{ "pinsrq",   &Instruction::decode_Vo_Eq_Ib, OP_PINSRQ,   FLAG_NONE }, // x86: pinsrq Vo, Eq, Ib
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid,  OP_INVALID,  FLAG_NONE },

	/* 0x0f 0x3a 0x30 - 0x0f 0x3a 0x3f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x40 - 0x0f 0x3a 0x4f */
	{ "dpps",    &Instruction::decode_Vo_Wo_Ib, OP_DPPS,    FLAG_SSE4_1 },
	{ "dppd",    &Instruction::decode_Vo_Wo_Ib, OP_DPPD,    FLAG_SSE4_1 },
	{ "mpsadbw", &Instruction::decode_Vo_Wo_Ib, OP_MPSADBW, FLAG_SSE4_1 },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid,  OP_INVALID, FLAG_NONE },

	/* 0x0f 0x3a 0x50 - 0x0f 0x3a 0x5f */
	INVALID_BLOCK,

	/* 0x0f 0x3a 0x60 - 0x0f 0x3a 0x6f */
	{ "pcmpestrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpestri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPESTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistrm", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRM, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "pcmpistri", &Instruction::decode_Vo_Wo_Ib, OP_PCMPISTRI, FLAG_SSE4_2 | FLAG_W_FLAGS },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },
	{ "invalid",   &Instruction::decode_invalid,  OP_INVALID,   FLAG_NONE },

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
