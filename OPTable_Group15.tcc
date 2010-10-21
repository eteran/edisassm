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

#ifndef OPTABLE_GROUP15_20080314_TCC_
#define OPTABLE_GROUP15_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group15[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psrlq", &Instruction::decode_Nq_Ib, OP_PSRLQ, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllq", &Instruction::decode_Nq_Ib, OP_PSLLQ, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group15_66[8] = {
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psrlq", &Instruction::decode_Uo_Ib, OP_PSRLQ, FLAG_NONE },
	{ "psrldq", &Instruction::decode_Uo_Ib, OP_PSRLDQ, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "psllq", &Instruction::decode_Uo_Ib, OP_PSLLQ, FLAG_NONE },
	{ "pslldq", &Instruction::decode_Uo_Ib, OP_PSLLDQ, FLAG_NONE }
};


#endif

