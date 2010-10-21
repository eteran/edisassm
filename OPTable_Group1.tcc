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

#ifndef OPTABLE_GROUP1_20080314_TCC_
#define OPTABLE_GROUP1_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group1[32] = {
	{ "add", &Instruction::decode_Eb_Ib, OP_ADD, FLAG_NONE },
	{ "or", &Instruction::decode_Eb_Ib, OP_OR, FLAG_NONE },
	{ "adc", &Instruction::decode_Eb_Ib, OP_ADC, FLAG_NONE },
	{ "sbb", &Instruction::decode_Eb_Ib, OP_SBB, FLAG_NONE },
	{ "and", &Instruction::decode_Eb_Ib, OP_AND, FLAG_NONE },
	{ "sub", &Instruction::decode_Eb_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &Instruction::decode_Eb_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &Instruction::decode_Eb_Ib, OP_CMP, FLAG_NONE },
	
	{ "add", &Instruction::decode_Ev_Iz, OP_ADD, FLAG_NONE },
	{ "or", &Instruction::decode_Ev_Iz, OP_OR, FLAG_NONE },
	{ "adc", &Instruction::decode_Ev_Iz, OP_ADC, FLAG_NONE },
	{ "sbb", &Instruction::decode_Ev_Iz, OP_SBB, FLAG_NONE },
	{ "and", &Instruction::decode_Ev_Iz, OP_AND, FLAG_NONE },
	{ "sub", &Instruction::decode_Ev_Iz, OP_SUB, FLAG_NONE },
	{ "xor", &Instruction::decode_Ev_Iz, OP_XOR, FLAG_NONE },
	{ "cmp", &Instruction::decode_Ev_Iz, OP_CMP, FLAG_NONE },
	
	{ "add", &Instruction::decode_Eb_Ib, OP_ADD, FLAG_NONE },
	{ "or", &Instruction::decode_Eb_Ib, OP_OR, FLAG_NONE },
	{ "adc", &Instruction::decode_Eb_Ib, OP_ADC, FLAG_NONE },
	{ "sbb", &Instruction::decode_Eb_Ib, OP_SBB, FLAG_NONE },
	{ "and", &Instruction::decode_Eb_Ib, OP_AND, FLAG_NONE },
	{ "sub", &Instruction::decode_Eb_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &Instruction::decode_Eb_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &Instruction::decode_Eb_Ib, OP_CMP, FLAG_NONE },
	
	{ "add", &Instruction::decode_Ev_Ib, OP_ADD, FLAG_NONE },
	{ "or", &Instruction::decode_Ev_Ib, OP_OR, FLAG_NONE },
	{ "adc", &Instruction::decode_Ev_Ib, OP_ADC, FLAG_NONE },
	{ "sbb", &Instruction::decode_Ev_Ib, OP_SBB, FLAG_NONE },
	{ "and", &Instruction::decode_Ev_Ib, OP_AND, FLAG_NONE },
	{ "sub", &Instruction::decode_Ev_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &Instruction::decode_Ev_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &Instruction::decode_Ev_Ib, OP_CMP }
};

#endif

