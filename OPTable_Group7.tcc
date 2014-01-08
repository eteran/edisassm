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

#ifndef OPTABLE_GROUP7_20080314_TCC_
#define OPTABLE_GROUP7_20080314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group7[8] = {
	{ "sgdt",    &Instruction::decode_Ms,      OP_SGDT,    FLAG_NONE },
	{ "sidt",    &Instruction::decode_Ms,      OP_SIDT,    FLAG_NONE },
	{ "lgdt",    &Instruction::decode_Ms,      OP_LGDT,    FLAG_NONE },
	{ "lidt",    &Instruction::decode_Ms,      OP_LIDT,    FLAG_NONE },
	{ "smsw",    &Instruction::decode_Rv_Mw,   OP_SMSW,    FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "lmsw",    &Instruction::decode_Ew,      OP_LMSW,    FLAG_NONE },
	{ "invlpg",  &Instruction::decode_Mb,      OP_INVLPG,  FLAG_NONE },
};

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group7A[64] = {
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "vmcall",   &Instruction::decode0,        OP_VMCALL,   FLAG_VMX | FLAG_W_FLAGS },
	{ "vmlaunch", &Instruction::decode0,        OP_VMLAUNCH, FLAG_VMX | FLAG_W_FLAGS },
	{ "vmresume", &Instruction::decode0,        OP_VMRESUME, FLAG_VMX | FLAG_W_FLAGS },
	{ "vmxoff",   &Instruction::decode0,        OP_VMXOFF,   FLAG_VMX | FLAG_W_FLAGS },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },
	{ "invalid",  &Instruction::decode_invalid, OP_INVALID,  FLAG_NONE },

	{ "monitor", &Instruction::decode0,        OP_MONITOR, FLAG_SSE3 },
	{ "mwait", &Instruction::decode0,          OP_MWAIT,   FLAG_SSE3 },
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

	{ "vmrun", &Instruction::decode0,   OP_VMRUN,   FLAG_AMD },
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

	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, // x86-64: swapgs
	{ "rdtscp",  &Instruction::decode0,        OP_RDTSCP,  FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

}

#endif
