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

#ifndef OPTABLE_GROUP9_20080314_TCC_
#define OPTABLE_GROUP9_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group9[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b, OP_CMPXCHG, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "vmptrld", &Instruction::decode_Mq, OP_VMPTRLD, FLAG_NONE },
	{ "vmptrst", &Instruction::decode_Mq, OP_VMPTRST, FLAG_NONE }
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group9_66[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b, OP_CMPXCHG, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "vmclear", &Instruction::decode_Mq, OP_VMCLEAR, FLAG_NONE },
	{ "vmptrst", &Instruction::decode_Mq, OP_VMPTRST, FLAG_NONE }
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group9_F3[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "cmpxchg8b/cmpxchg16b", &Instruction::decode_invalid_cmpxchg8b_cmpxchg16b, OP_CMPXCHG, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "vmxon", &Instruction::decode_Mq, OP_VMXON, FLAG_NONE },
	{ "vmptrst", &Instruction::decode_Mq, OP_VMPTRST, FLAG_NONE }
};

#endif

