/*
Copyright (C) 2006 - 2011 Evan Teran
                   eteran@alum.rit.edu

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef OPTABLE_GROUP7_20080314_TCC_
#define OPTABLE_GROUP7_20080314_TCC_

#include "Operand.h"

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_Group7[8] = {
	{ "sgdt", &Instruction::decode_Ms, OP_SGDT, FLAG_NONE },
	{ "sidt", &Instruction::decode_Ms, OP_SIDT, FLAG_NONE },
	{ "lgdt", &Instruction::decode_Ms, OP_LGDT, FLAG_NONE },
	{ "lidt", &Instruction::decode_Ms, OP_LIDT, FLAG_NONE },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW, FLAG_NONE },
	{ "invlpg", &Instruction::decode_Mb, OP_INVLPG, FLAG_NONE },
};

template <class M>
const typename Instruction<M>::OpcodeEntry Instruction<M>::Opcodes_Group7A[64] = {
	{ "vmcall", &Instruction::decode0, OP_VMCALL, FLAG_NONE },
	{ "vmlaunch", &Instruction::decode0, OP_VMLAUNCH, FLAG_NONE },
	{ "vmresume", &Instruction::decode0, OP_VMRESUME, FLAG_NONE },
	{ "vmxoff", &Instruction::decode0, OP_VMXOFF, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	{ "monitor", &Instruction::decode0, OP_MONITOR, FLAG_NONE },
	{ "mwait", &Instruction::decode0, OP_MWAIT, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	
	{ "xgetbv", &Instruction::decode0, OP_XGETBV, FLAG_NONE },
	{ "xsetbv", &Instruction::decode0, OP_XSETBV, FLAG_NONE },
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
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },	// x86-64: swapgs
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }
};


#endif
