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

#ifndef OPTABLE_GROUP2_20080314_TCC_
#define OPTABLE_GROUP2_20080314_TCC_

#include "Operand.h"

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group2[16] = {
	{ "rol", &Instruction::decode_Eb_Ib, OP_ROL },
	{ "ror", &Instruction::decode_Eb_Ib, OP_ROR },
	{ "rcl", &Instruction::decode_Eb_Ib, OP_RCL },
	{ "rcr", &Instruction::decode_Eb_Ib, OP_RCR },
	{ "shl", &Instruction::decode_Eb_Ib, OP_SHL },
	{ "shr", &Instruction::decode_Eb_Ib, OP_SHR },
	{ "sal", &Instruction::decode_Eb_Ib, OP_SAL },
	{ "sar", &Instruction::decode_Eb_Ib, OP_SAR },
	
	{ "rol", &Instruction::decode_Ev_Ib, OP_ROL },
	{ "ror", &Instruction::decode_Ev_Ib, OP_ROR },
	{ "rcl", &Instruction::decode_Ev_Ib, OP_RCL },
	{ "rcr", &Instruction::decode_Ev_Ib, OP_RCR },
	{ "shl", &Instruction::decode_Ev_Ib, OP_SHL },
	{ "shr", &Instruction::decode_Ev_Ib, OP_SHR },
	{ "sal", &Instruction::decode_Ev_Ib, OP_SAL },
	{ "sar", &Instruction::decode_Ev_Ib, OP_SAR },
};

template <class Model>
const typename Instruction<Model>::OpcodeEntry Instruction<Model>::Opcodes_Group2D[32] = {
	{ "rol", &Instruction::decode_Eb_1, OP_ROL },
	{ "ror", &Instruction::decode_Eb_1, OP_ROR },
	{ "rcl", &Instruction::decode_Eb_1, OP_RCL },
	{ "rcr", &Instruction::decode_Eb_1, OP_RCR },
	{ "shl", &Instruction::decode_Eb_1, OP_SHL },
	{ "shr", &Instruction::decode_Eb_1, OP_SHR },
	{ "sal", &Instruction::decode_Eb_1, OP_SAL },
	{ "sar", &Instruction::decode_Eb_1, OP_SAR },
	
	{ "rol", &Instruction::decode_Ev_1, OP_ROL },
	{ "ror", &Instruction::decode_Ev_1, OP_ROR },
	{ "rcl", &Instruction::decode_Ev_1, OP_RCL },
	{ "rcr", &Instruction::decode_Ev_1, OP_RCR },
	{ "shl", &Instruction::decode_Ev_1, OP_SHL },
	{ "shr", &Instruction::decode_Ev_1, OP_SHR },
	{ "sal", &Instruction::decode_Ev_1, OP_SAL },
	{ "sar", &Instruction::decode_Ev_1, OP_SAR },
	
	{ "rol", &Instruction::decode_Eb_CL, OP_ROL },
	{ "ror", &Instruction::decode_Eb_CL, OP_ROR },
	{ "rcl", &Instruction::decode_Eb_CL, OP_RCL },
	{ "rcr", &Instruction::decode_Eb_CL, OP_RCR },
	{ "shl", &Instruction::decode_Eb_CL, OP_SHL },
	{ "shr", &Instruction::decode_Eb_CL, OP_SHR },
	{ "sal", &Instruction::decode_Eb_CL, OP_SAL },
	{ "sar", &Instruction::decode_Eb_CL, OP_SAR },
	
	{ "rol", &Instruction::decode_Ev_CL, OP_ROL },
	{ "ror", &Instruction::decode_Ev_CL, OP_ROR },
	{ "rcl", &Instruction::decode_Ev_CL, OP_RCL },
	{ "rcr", &Instruction::decode_Ev_CL, OP_RCR },
	{ "shl", &Instruction::decode_Ev_CL, OP_SHL },
	{ "shr", &Instruction::decode_Ev_CL, OP_SHR },
	{ "sal", &Instruction::decode_Ev_CL, OP_SAL },	
	{ "sar", &Instruction::decode_Ev_CL, OP_SAR },	
};

#endif

