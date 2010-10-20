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

#ifndef OPTABLE_GROUP16_20080314_TCC_
#define OPTABLE_GROUP16_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group16_Mem[8] = {
	{ "fxsave", &Instruction::decode_M512, OP_FXSAVE },
	{ "fxrstor", &Instruction::decode_M512, OP_FXRSTOR },	
	{ "ldmxcsr", &Instruction::decode_Md, OP_LDMXCSR },
	{ "stmxcsr", &Instruction::decode_Md, OP_STMXCSR },
	{ "xsave", &Instruction::decode_M, OP_XSAVE },
	{ "xrstor", &Instruction::decode_M, OP_XRSTOR },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "clflush", &Instruction::decode_M, OP_CLFLUSH },
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group16_Reg[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },	
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID },
	{ "lfence", &Instruction::decode0, OP_LFENCE },
	{ "mfence", &Instruction::decode0, OP_MFENCE },
	{ "sfence", &Instruction::decode0, OP_SFENCE },
};

#endif

