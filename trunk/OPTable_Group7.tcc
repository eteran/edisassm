/*
Copyright (C) 2006 - 2009 Evan Teran
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

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group7[8] = {
	{ "sgdt", &Instruction::decode_Ms, OP_SGDT },
	{ "sidt", &Instruction::decode_Ms, OP_SIDT },
	{ "lgdt", &Instruction::decode_Ms, OP_LGDT },
	{ "lidt", &Instruction::decode_Ms, OP_LIDT },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "invlpg", &Instruction::decode_Mb, OP_INVLPG },
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group7A[64] = {
	{ "vmcall", &Instruction::decode0, OP_VMCALL },
	{ "vmlaunch", &Instruction::decode0, OP_VMLAUNCH },
	{ "vmresume", &Instruction::decode0, OP_VMRESUME },
	{ "vmxoff", &Instruction::decode0, OP_VMXOFF },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "monitor", &Instruction::decode0, OP_MONITOR },
	{ "mwait", &Instruction::decode0, OP_MWAIT },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "xgetbv", &Instruction::decode0, OP_XGETBV },
	{ "xsetbv", &Instruction::decode0, OP_XSETBV },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	{ "smsw", &Instruction::decode_Rv_Mw, OP_SMSW },
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	{ "lmsw", &Instruction::decode_Ew, OP_LMSW },
	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	// x86-64: swapgs
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID }
};


#endif
