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

#ifndef INSTRUCTION_20080314_TCC_
#define INSTRUCTION_20080314_TCC_

#include <sstream>
#include <string>
#include <locale>
#include <iostream>
#include <cassert>

#include "OPTable_FPU.tcc"
#include "OPTable_1byte.tcc"
#include "OPTable_2byte.tcc"
#include "OPTable_3byte.tcc"
#include "OPTable_Group1.tcc"
#include "OPTable_Group2.tcc"
#include "OPTable_Group3.tcc"
#include "OPTable_Group4.tcc"
#include "OPTable_Group5.tcc"
#include "OPTable_Group6.tcc"
#include "OPTable_Group7.tcc"
#include "OPTable_Group8.tcc"
#include "OPTable_Group9.tcc"
#include "OPTable_Group10.tcc"
#include "OPTable_Group11.tcc"
#include "OPTable_Group12.tcc"
#include "OPTable_Group13.tcc"
#include "OPTable_Group14.tcc"
#include "OPTable_Group15.tcc"
#include "OPTable_Group16.tcc"
#include "OPTable_Group17.tcc"
#include "ModRM.h"
#include "SIB.h"
#include "REX.h"
#include "Operand.h"

//------------------------------------------------------------------------------
// Name: decode_Gx(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_Gx(const uint8_t *buf) {

	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}

	const ModRM rm(buf[opcode_size_]);
	modrm_size_ = 1;

	int regindex = rm.reg();
	if(Model::BITS == 64 && rex_byte_.is_rex()) {
		regindex |= (rex_byte_.r() << 3);
		
		if(REG_DECODE == &indexToReg8) {
			if(regindex > 3 && regindex < 8) {
				regindex += 12;
			}
		}
	}

	operand_t &operand	= next_operand();
	operand.reg			= (*REG_DECODE)(regindex);
	operand.type_		= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_STi(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <int index>
void Instruction<Model>::decode_STi(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand	= next_operand();
	operand.reg			= indexToRegFPU(index);
	operand.type_		= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_0_16(const uint8_t *buf, const ModRM &rm, operand_t &operand)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_0_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {

	operand.type_							= TYPE;
	operand.expression.scale				= 1;
	operand.expression.displacement_type	= operand_t::DISP_NONE;
	
	switch(rm.rm()) {
	case 0x00:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x01:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x02:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x03:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x04:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x05:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x06:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_NULL;
		operand.expression.s_disp16			= get_displacement<int16_t>(buf);
		operand.expression.displacement_type= operand_t::DISP_S16;
		break;
	case 0x07:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_1_16(const uint8_t *buf, const ModRM &rm, operand_t &operand)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_1_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {

	operand.type_							= TYPE;
	operand.expression.scale				= 1;
	operand.expression.s_disp8				= get_displacement<int8_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S8;
	
	switch(rm.rm()) {
	case 0x00:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x01:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x02:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x03:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x04:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x05:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x06:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x07:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_2_16(const uint8_t *buf, const ModRM &rm, operand_t &operand)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_2_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {
	
	operand.type_							= TYPE;
	operand.expression.scale				= 1;
	operand.expression.s_disp16				= get_displacement<int16_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S16;
	
	switch(rm.rm()) {
	case 0x00:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x01:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BX;
		break;
	case 0x02:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x03:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x04:
		operand.expression.index			= operand_t::REG_SI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x05:
		operand.expression.index			= operand_t::REG_DI;
		operand.expression.base				= operand_t::REG_NULL;
		break;
	case 0x06:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_BP;
		break;
	case 0x07:
		operand.expression.index			= operand_t::REG_NULL;
		operand.expression.base				= operand_t::REG_BX;
		break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Reg(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Register REG>
void Instruction<Model>::decode_Reg(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand = next_operand();

	operand.reg 	= REG;
	operand.type_	= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_const_Iq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <int64_t IMM>
void Instruction<Model>::decode_const_Iq(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand = next_operand();

	operand.sqword	= IMM;
	operand.type_	= operand_t::TYPE_IMMEDIATE64;
	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_	+= sizeof(int64_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Id(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <int32_t IMM>
void Instruction<Model>::decode_const_Id(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand = next_operand();

	operand.sdword	= IMM;
	operand.type_	= operand_t::TYPE_IMMEDIATE32;
	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_	+= sizeof(int32_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Iw(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <int16_t IMM>
void Instruction<Model>::decode_const_Iw(const uint8_t *buf) {
	UNUSED(buf);
	UNUSED(size);

	operand_t &operand = next_operand();

	operand.sword	= IMM;
	operand.type_	= operand_t::TYPE_IMMEDIATE16;
	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_	+= sizeof(int16_t);
}

//------------------------------------------------------------------------------
// Name: decode_const_Ib(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <int8_t IMM>
void Instruction<Model>::decode_const_Ib(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand = next_operand();

	operand.sbyte	= IMM;
	operand.type_	= operand_t::TYPE_IMMEDIATE8;
	// NOTE: so far this is only used for implicit constants, other
	// ones may need a size!
	//immediate_size_	+= sizeof(int8_t);
}

//------------------------------------------------------------------------------
// Name: get_immediate(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <class T>
T Instruction<Model>::get_immediate(const uint8_t *buf) {
	BOUNDS_CHECK(Instruction::size() + sizeof(T), buffer_size_);

	const T ret = *reinterpret_cast<const T *>(&buf[opcode_size_ + modrm_size_ + sib_size_ + disp_size_ + immediate_size_]);
	immediate_size_ += sizeof(T);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_displacement(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <class T>
T Instruction<Model>::get_displacement(const uint8_t *buf) {		
	
	BOUNDS_CHECK(Instruction::size() + sizeof(T), buffer_size_);
	
	// there should only every be one displacement value!
	if(disp_size_ != 0) {
		throw multiple_displacements(Instruction::size());
	}

	const T ret = *reinterpret_cast<const T *>(&buf[opcode_size_ + modrm_size_ + sib_size_ + disp_size_]);
	disp_size_ = sizeof(T);
	return ret;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_0_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_0_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {

	UNUSED(enable_64_bit);

	operand.type_ = TYPE;

	if(rm.rm() == 0x04) {
		// we got enough room for the SIB byte?
		if(sib_size_ == 0) {
			BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
		}

		sib_size_ = 1;
		const SIB sib(buf[opcode_size_ + modrm_size_]);


		int sibindex = sib.index();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {

			if(Model::BITS == 64 && enable_64_bit) {
				operand.expression.index	= indexToReg64(sibindex);
			} else {
				operand.expression.index	= indexToReg32(sibindex);
			}
			
			
			operand.expression.scale	= 1 << sib.scale();
		} else {
			operand.expression.index	= operand_t::REG_NULL;
			operand.expression.scale	= 1;
		}
			
		if(sib.base() == 0x05) {
		
			// we could only get here if modrm.mod == 0x00
			// so it is always sdword
			operand.expression.base					= operand_t::REG_NULL;
			operand.expression.s_disp32				= get_displacement<int32_t>(buf);
			operand.expression.displacement_type	= operand_t::DISP_S32;

		} else {
		
			int sibbase = sib.base();

			if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
				sibbase |= (rex_byte_.b() << 3);
			}
			
			if(Model::BITS == 64 && enable_64_bit) {
				operand.expression.base				= indexToReg64(sibbase);
			} else {
				operand.expression.base				= indexToReg32(sibbase);
			}
			operand.expression.displacement_type	= operand_t::DISP_NONE;
		}
	} else if(rm.rm() == 0x05) {
		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.index				= operand_t::REG_NULL;
			operand.expression.scale				= 1;
			operand.expression.base					= operand_t::REG_RIP;
			operand.expression.s_disp32				= get_displacement<int32_t>(buf);
			operand.expression.displacement_type	= operand_t::DISP_S32;
		} else {
			operand.expression.index				= operand_t::REG_NULL;
			operand.expression.scale				= 1;
			operand.expression.base					= operand_t::REG_NULL;
			operand.expression.s_disp32				= get_displacement<int32_t>(buf);
			operand.expression.displacement_type	= operand_t::DISP_S32;
		}
	} else {
		operand.expression.index				= operand_t::REG_NULL;
		operand.expression.scale				= 1;
		
		int rmbase = rm.rm();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}
		
		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.base					= indexToReg64(rmbase);
		} else {
			operand.expression.base					= indexToReg32(rmbase);
		}
		operand.expression.s_disp8				= 0;
		operand.expression.displacement_type	= operand_t::DISP_NONE;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_1_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_1_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {

	UNUSED(enable_64_bit);

	if(rm.rm() == 0x04) {
		
		// we got enough room for the SIB byte?
		if(sib_size_ == 0) {
			BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
		}

		sib_size_ = 1;
		const SIB sib(buf[opcode_size_ + modrm_size_]);

		int sibbase = sib.base();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibbase |= (rex_byte_.b() << 3);
		}

		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.base	= indexToReg64(sibbase);
		} else {
			operand.expression.base	= indexToReg32(sibbase);
		}
		operand.expression.scale = 1 << sib.scale();

		int sibindex = sib.index();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {			
			if(Model::BITS == 64 && enable_64_bit) {			
				operand.expression.index = indexToReg64(sibindex);
			} else {
				operand.expression.index = indexToReg32(sibindex);
			}
		} else {
			operand.expression.index = operand_t::REG_NULL;		
		}
	} else {
		operand.expression.index = operand_t::REG_NULL;
		operand.expression.scale = 1;

		int rmbase = rm.rm();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}

		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.base = indexToReg64(rmbase);
		} else {
			operand.expression.base = indexToReg32(rmbase);
		}
		
	}
	
	operand.type_							= TYPE;
	operand.expression.s_disp8				= get_displacement<int8_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S8;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_2_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_2_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {
	
	UNUSED(enable_64_bit);

	if(rm.rm() == 0x04) {
		// we got enough room for the SIB byte?
		if(sib_size_ == 0) {
			BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
		}

		sib_size_ = 1;
		const SIB sib(buf[opcode_size_ + modrm_size_]);
	
		int sibbase = sib.base();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibbase |= (rex_byte_.b() << 3);
		}

		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.base = indexToReg64(sibbase);
		} else {
			operand.expression.base = indexToReg32(sibbase);
		}
		
		operand.expression.scale	= 1 << sib.scale();

		int sibindex = sib.index();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {
			if(Model::BITS == 64 && enable_64_bit) {
				operand.expression.index = indexToReg64(sibindex);
			} else {
				operand.expression.index = indexToReg32(sibindex);
			}
			
		} else {
			operand.expression.index = operand_t::REG_NULL;
		}
	} else {
		operand.expression.index = operand_t::REG_NULL;
		operand.expression.scale = 1;
	
		int rmbase = rm.rm();

		if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}
		
		if(Model::BITS == 64 && enable_64_bit) {
			operand.expression.base = indexToReg64(rmbase);
		} else {
			operand.expression.base = indexToReg32(rmbase);
		}
		
	}
	
	operand.type_							= TYPE;
	operand.expression.s_disp32				= get_displacement<int32_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S32;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_3_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_3_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {
	UNUSED(buf);
	UNUSED(enable_64_bit);

	int rmbase	= rm.rm();
	
	if(Model::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
		rmbase |= (rex_byte_.b() << 3);
		if(REG_DECODE == &indexToReg8) {
			if(rmbase > 3 && rmbase < 8) {
				rmbase += 12;
			}
		}
	}
	
	operand.reg			= (*REG_DECODE)(rmbase);
	operand.type_		= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_Invalid(const uint8_t *buf, const ModRM &rm, operand_t &operand)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_ModRM_Invalid(const uint8_t *buf, const ModRM &rm, operand_t &operand) {
	UNUSED(rm);
	UNUSED(operand);
	UNUSED(buf);
	throw invalid_operand(Instruction::size());
}

//------------------------------------------------------------------------------
// Name: decode_Ex(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <typename Operand<Model>::Type TYPE, typename Operand<Model>::Register (*REG_DECODE)(uint8_t)>
void Instruction<Model>::decode_Ex(const uint8_t *buf) {

	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM rm(buf[opcode_size_]);
	modrm_size_ = 1;

	operand_t &operand = next_operand();

	if(prefix_ & PREFIX_ADDRESS) {	
		if(Model::BITS == 64) {
			switch(rm.mod()) {
			case 0x00:
				decode_ModRM_0_32<operand_t::TYPE_EXPRESSION32, REG_DECODE>(buf, rm, operand, false);
				break;
			case 0x01:
				decode_ModRM_1_32<operand_t::TYPE_EXPRESSION32, REG_DECODE>(buf, rm, operand, false);
				break;
			case 0x02:
				decode_ModRM_2_32<operand_t::TYPE_EXPRESSION32, REG_DECODE>(buf, rm, operand, false);
				break;
			case 0x03:
				decode_ModRM_3_32<operand_t::TYPE_EXPRESSION32, REG_DECODE>(buf, rm, operand, false);
				break;
			}
		} else {
			switch(rm.mod()) {
			case 0x00:
				decode_ModRM_0_16<TYPE, REG_DECODE>(buf, rm, operand);
				break;
			case 0x01:
				decode_ModRM_1_16<TYPE, REG_DECODE>(buf, rm, operand);
				break;
			case 0x02:
				decode_ModRM_2_16<TYPE, REG_DECODE>(buf, rm, operand);
				break;
			case 0x03:
				// same as in 32-bit mode!
				decode_ModRM_3_32<TYPE, REG_DECODE>(buf, rm, operand);
				break;
			}
		}
	} else {
		switch(rm.mod()) {
		case 0x00:
			decode_ModRM_0_32<TYPE, REG_DECODE>(buf, rm, operand);
			break;
		case 0x01:
			decode_ModRM_1_32<TYPE, REG_DECODE>(buf, rm, operand);
			break;
		case 0x02:
			decode_ModRM_2_32<TYPE, REG_DECODE>(buf, rm, operand);
			break;
		case 0x03:
			decode_ModRM_3_32<TYPE, REG_DECODE>(buf, rm, operand);
			break;
		}
	}
}

//------------------------------------------------------------------------------
// Name: decode3(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <void (Instruction<Model>::*F1)(const uint8_t *), void (Instruction<Model>::*F2)(const uint8_t *), void (Instruction<Model>::*F3)(const uint8_t *)>
void Instruction<Model>::decode3(const uint8_t *buf) {
	(this->*F1)(buf);
	(this->*F2)(buf);
	(this->*F3)(buf);
}

//------------------------------------------------------------------------------
// Name: decode2(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <void (Instruction<Model>::*F1)(const uint8_t *), void (Instruction<Model>::*F2)(const uint8_t *)>
void Instruction<Model>::decode2(const uint8_t *buf) {
	(this->*F1)(buf);
	(this->*F2)(buf);
}

//------------------------------------------------------------------------------
// Name: decode1(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
template <void (Instruction<Model>::*F1)(const uint8_t *)>
void Instruction<Model>::decode1(const uint8_t *buf) {
	(this->*F1)(buf);
}

//------------------------------------------------------------------------------
// Name: Instruction(const uint8_t *buf, std::size_t size, address_t rva, const std::nothrow_t&) throw()
//------------------------------------------------------------------------------
template <class Model>
Instruction<Model>::Instruction(const uint8_t *buf, std::size_t size, address_t rva, const std::nothrow_t&) throw()
		: rva_(rva), buffer_(buf), buffer_size_(size), opcode_(0), type_(OP_INVALID),
		prefix_(0), mandatory_prefix_(0), operand_count_(0), modrm_size_(0), 
		sib_size_(0), disp_size_(0), prefix_size_(0), immediate_size_(0),
		opcode_size_(0), rex_byte_(0), rex_size_(0), private_buffer_(false) {
		
	try {
		initialize(buf, size);
	} catch(const instruction_too_big &) {
		//throw;
	} catch(const invalid_operand &) {
		//throw;
	} catch(const invalid_instruction &) {
		//throw;
	}
}

//------------------------------------------------------------------------------
// Name: Instruction(const uint8_t *buf, std::size_t size, address_t rva)
//------------------------------------------------------------------------------
template <class Model>
Instruction<Model>::Instruction(const uint8_t *buf, std::size_t size, address_t rva) 
		: rva_(rva), buffer_(buf), buffer_size_(size), opcode_(0), type_(OP_INVALID), 
		prefix_(0), mandatory_prefix_(0), operand_count_(0), modrm_size_(0), 
		sib_size_(0), disp_size_(0), prefix_size_(0), immediate_size_(0),
		opcode_size_(0), rex_byte_(0), rex_size_(0), private_buffer_(false) {
		
	initialize(buf, size);
}

//------------------------------------------------------------------------------
// Name: ~Instruction()
//------------------------------------------------------------------------------
template <class Model>
Instruction<Model>::~Instruction() {
	if(private_buffer_) {
		delete [] buffer_;
	}
}

//------------------------------------------------------------------------------
// Name: initialize(const uint8_t *buf, std::size_t size)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::initialize(const uint8_t *buf, std::size_t size) {
	
	for(int i = 0; i < Model::MAX_OPERANDS; ++i) {
		operands_[i].invalidate();
	}
	
	process_prefixes(buf, size);
	
	// is there any space left for the opcode/operands?
	BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	
	// find the entry in the table
	opcode_ = &Opcodes[*buf];	
	opcode_size_ = 1;

	// decode it
	(this->*(opcode_->decoder))(buf);

	// these will not be set until we are sure which opcode we are looking 
	// at, this way any exceptions will default the instruction to invalid
	type_		= opcode_->type;
	mnemonic_	= opcode_->mnemonic;
}

//------------------------------------------------------------------------------
// Name: Instruction(const Instruction &other)
//------------------------------------------------------------------------------
template <class Model>
Instruction<Model>::Instruction(const Instruction &other) :
		rva_(other.rva_),
		opcode_(other.opcode_),
		mnemonic_(other.mnemonic_),
		type_(other.type_),
		prefix_(other.prefix_),
		mandatory_prefix_(other.mandatory_prefix_),
		operand_count_(other.operand_count_),
		modrm_size_(other.modrm_size_),
		sib_size_(other.sib_size_),
		disp_size_(other.disp_size_),
		prefix_size_(other.prefix_size_),
		immediate_size_(other.immediate_size_),
		opcode_size_(other.opcode_size_),
		rex_byte_(other.rex_byte_),
		rex_size_(other.rex_size_) {

	for(int i = 0; i < Model::MAX_OPERANDS; ++i) {
		operands_[i] = other.operands_[i];
		operands_[i].set_owner(this);
	}
	
	buffer_size_ = other.size();
	uint8_t *const buffer = new uint8_t[buffer_size_];
	std::memcpy(buffer, other.buffer_, buffer_size_);
	buffer_ = buffer;

}

//------------------------------------------------------------------------------
// Name: operator=(const Instruction &rhs)
//------------------------------------------------------------------------------
template <class Model>
Instruction<Model> &Instruction<Model>::operator=(const Instruction &rhs) {
	if(this != &rhs) {
		Instruction(rhs).swap(*this);
	}
	return *this;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::swap(Instruction &other) {
	for(int i = 0; i < Model::MAX_OPERANDS; ++i) {
		operands_[i].swap(other.operands_[i]);
	}
	
	std::swap(rva_, other.rva_);
	std::swap(buffer_, other.buffer_);
	std::swap(buffer_size_, other.buffer_size_);	
	std::swap(opcode_, other.opcode_);
	std::swap(mnemonic_, other.mnemonic_);
	std::swap(type_, other.type_);
	std::swap(prefix_, other.prefix_);
	std::swap(mandatory_prefix_, other.mandatory_prefix_);
	std::swap(operand_count_, other.operand_count_);
	std::swap(modrm_size_, other.modrm_size_);
	std::swap(sib_size_, other.sib_size_);
	std::swap(disp_size_, other.disp_size_);
	std::swap(prefix_size_, other.prefix_size_);
	std::swap(immediate_size_, other.immediate_size_);
	std::swap(opcode_size_, other.opcode_size_);
	std::swap(rex_byte_, other.rex_byte_);
	std::swap(rex_size_, other.rex_size_);
	std::swap(private_buffer_, other.private_buffer_);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
template <class T, int Elements>
void Instruction<Model>::find_opcode(const std::string &opcode, T (&table)[Elements], int opcode_count) {
	(void)opcode_count;
	
	for(size_t i = 0; i < Elements; ++i) {
		if(table[i].decoder != &Instruction::decode_invalid) {
			if(opcode == table[i].mnemonic) {
				// possible match
				std::cout << table << " -> " << std::hex << i << std::endl;
			}
		}
	}

}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::assemble(std::string instruction) {

	std::istringstream ss(instruction);
	std::string token;
	std::string prefix;
	std::string opcode;
	std::string operands[3];
	int operand_index = 0;
	
	while(ss >> token) {
		token = edisassm::util::tolower(edisassm::util::trim(token));
		if(token == "lock" || token == "repe" || token == "repne" || token == "rep") {
			prefix += token;
			prefix += " ";
			token = "";
		} else {
			break;
		}
	}
	
	opcode = token;
	
	while(std::getline(ss, token, ',')) {
		if(!(operand_index < 3)) {
			throw too_many_operands(operand_index + 1);
		}
		operands[operand_index++] = edisassm::util::tolower(edisassm::util::trim(token));
	}
	
	std::cout << "PREFIX  : " << prefix << std::endl;
	std::cout << "OPCODE  : " << opcode << std::endl;
	for(int i = 0; i < operand_index; ++i) {
		std::cout << "OPERAND : " << operands[i] << std::endl;
	}
	
	find_opcode(opcode, Opcodes, operand_index);
	find_opcode(opcode, Opcodes_2Byte_NA, operand_index);
	find_opcode(opcode, Opcodes_2Byte_66, operand_index);
	find_opcode(opcode, Opcodes_2Byte_F2, operand_index);
	find_opcode(opcode, Opcodes_2Byte_F3, operand_index);
	
	find_opcode(opcode, Opcodes_3Byte_38_NA, operand_index);
	find_opcode(opcode, Opcodes_3Byte_38_66, operand_index);
	find_opcode(opcode, Opcodes_3Byte_38_F2, operand_index);

	find_opcode(opcode, Opcodes_3Byte_3A_NA, operand_index);
	find_opcode(opcode, Opcodes_3Byte_3A_66, operand_index);
	
	find_opcode(opcode, Opcodes_x87_Lo, operand_index);
	find_opcode(opcode, Opcodes_x87_Hi, operand_index);
}

//------------------------------------------------------------------------------
// Name: process_prefixes(const uint8_t *&buf, std::size_t size)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::process_prefixes(const uint8_t *&buf, std::size_t size) {

	bool done = false;
	
	// we only allow one prefix from each group to be set,
	// currently, the last one from a given group in the stream
	// will take precidence
	do {
		if(size == 0) {
			break;
		}
		
		switch(*buf) {
		// group1
		case 0xf0:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_LOCK;
			break;
		case 0xf2:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_REPNE;
			break;
		case 0xf3:
			prefix_ = (prefix_ & 0xffffff00) | PREFIX_REP;
			break;
		// group2
		case 0x2e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_CS;
			break;
		case 0x36:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_SS;
			break;
		case 0x3e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_DS;
			break;
		case 0x26:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_ES;
			break;
		case 0x64:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_FS;
			break;
		case 0x65:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_GS;
			break;
		#if 0
		case 0x2e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_BRANCH_NOT_TAKEN;
			break;
		case 0x3e:
			prefix_ = (prefix_ & 0xffff00ff) | PREFIX_BRANCH_TAKEN;
			break;	
		#endif
		// group3
		case 0x66:
			prefix_ = (prefix_ & 0xff00ffff) | PREFIX_OPERAND;
			break;
		// group4
		case 0x67:
			prefix_ = (prefix_ & 0x00ffffff) | PREFIX_ADDRESS;
			break;
		default:
			done = true;
			break;
		}

		// this if will get merged with the while's condition if the optimiser
		// is smart
		if(!done) {
			++buf;
			++prefix_size_;
			--size;
		}
	} while(!done);
	
	if(Model::BITS == 64) {
		if(size != 0) {
			rex_byte_ = *buf;
			if(rex_byte_.is_rex()) {
				++buf;
				++rex_size_;
				--size;
			}
		}
	}
}

//------------------------------------------------------------------------------
// Name: next_operand()
//------------------------------------------------------------------------------
template <class Model>
typename Instruction<Model>::operand_t &Instruction<Model>::next_operand() {

	if(operand_count_ >= Model::MAX_OPERANDS) {
		throw too_many_operands(size());
	}
	
	operand_t &ret = operands_[operand_count_++];
	ret.set_owner(this);
	return ret;
}

//------------------------------------------------------------------------------
// Name: decode_invalid(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_invalid(const uint8_t *buf) {
	UNUSED(buf);
	throw invalid_instruction(Instruction<Model>::size());
}

#define EMIT_ALT_NAME_HANDLER_GENERIC(name1, name2, name3, decoder_func1, decoder_func2, decoder_func3, OP1, OP2, OP3) \
template <class Model>																		\
void Instruction<Model>::decode_ ## name1 ## _ ## name2 ## _ ## name3(const uint8_t *buf) {	\
	static const OpcodeEntry opcodes[] = {		\
		{ #name1, (decoder_func1), (OP1), FLAG_NONE },		\
		{ #name2, (decoder_func2), (OP2), FLAG_NONE },		\
		{ #name3, (decoder_func3), (OP3), FLAG_NONE }		\
	};											\
												\
	switch(operand_size()) {					\
	case 16: opcode_ = &opcodes[0]; break;		\
	case 32: opcode_ = &opcodes[1]; break;		\
	case 64: opcode_ = &opcodes[2]; break;		\
	}											\
	(this->*(opcode_->decoder))(buf);			\
}


#define EMIT_ALT_NAME_HANDLER(name1, name2, decoder_func, OP1, OP2)	\
	EMIT_ALT_NAME_HANDLER_GENERIC( \
		name1, name2, invalid, \
		decoder_func, decoder_func, &Instruction::decode_invalid, \
		OP1, OP2, OP_INVALID)


#define EMIT_ALT_NAME_HANDLER2(name1, name2, name3, decoder_func, OP1, OP2, OP3)		\
	EMIT_ALT_NAME_HANDLER_GENERIC( \
		name1, name2, name3, \
		decoder_func, decoder_func, decoder_func, \
		OP1, OP2, OP3)

EMIT_ALT_NAME_HANDLER2(cbw, cwde, cdqe, &Instruction::decode0, OP_CBW, OP_CWDE, OP_CDQE)
EMIT_ALT_NAME_HANDLER2(cwd, cdq, cqo, &Instruction::decode0, OP_CWD, OP_CDQ, OP_CQO)
EMIT_ALT_NAME_HANDLER2(stosw, stosd, stosq, &Instruction::decode0, OP_STOS, OP_STOS, OP_STOS)
EMIT_ALT_NAME_HANDLER2(lodsw, lodsd, lodsq, &Instruction::decode0, OP_LODS, OP_LODS, OP_LODS)
EMIT_ALT_NAME_HANDLER2(scasw, scasd, scasq, &Instruction::decode0, OP_SCAS, OP_SCAS, OP_SCAS)
EMIT_ALT_NAME_HANDLER2(iretw, iret, iretq, &Instruction::decode0, OP_IRET, OP_IRET, OP_IRET)
EMIT_ALT_NAME_HANDLER2(movsw, movsd, movsq, &Instruction::decode0, OP_MOVS, OP_MOVS, OP_MOVS)
EMIT_ALT_NAME_HANDLER2(popfw, popfd, popfq, &Instruction::decode0, OP_POPF, OP_POPF, OP_POPF)
EMIT_ALT_NAME_HANDLER2(pushfw, pushfd, pushfq, &Instruction::decode0, OP_PUSHF, OP_PUSHF, OP_PUSHF)

EMIT_ALT_NAME_HANDLER_GENERIC(invalid, cmpxchg8b, cmpxchg16b, &Instruction::decode_invalid, &Instruction::decode_Mo, &Instruction::decode_Mo, OP_INVALID, OP_CMPXCHG8B, OP_CMPXCHG16B)


EMIT_ALT_NAME_HANDLER(insw, insd, &Instruction::decode0, OP_INS, OP_INS)
EMIT_ALT_NAME_HANDLER(outsw, outsd, &Instruction::decode0, OP_OUTS, OP_OUTS)
EMIT_ALT_NAME_HANDLER(cmpsw, cmpsd, &Instruction::decode0, OP_CMPS, OP_CMPS)
EMIT_ALT_NAME_HANDLER(pushaw, pushad, &Instruction::decode0, OP_PUSHA, OP_PUSHA)
EMIT_ALT_NAME_HANDLER(popaw, popad, &Instruction::decode0, OP_POPA, OP_POPA)


#undef EMIT_ALT_NAME_HANDLER_GENERIC
#undef EMIT_ALT_NAME_HANDLER
#undef EMIT_ALT_NAME_HANDLER2

//------------------------------------------------------------------------------
// Name: decode_x87(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_x87(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
		
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t escNum = (buf[0] - 0xd8);
	const uint8_t byte2 = buf[opcode_size_];
	
	if((byte2 & 0xc0) != 0xc0) {
		opcode_ = &Opcodes_x87_Lo[modrm.reg() + escNum * 8];
	} else {
		opcode_ = &Opcodes_x87_Hi[(byte2 & 0x3f) + escNum * 64];
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_2byte(const uint8_t *buf) {
	
	// we got enough room for next byte?
	BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	
	opcode_size_ = 2;
	
	const uint8_t index = buf[opcode_size_ - 1];

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_2Byte_66[index];
	} else if(prefix_ & PREFIX_REPNE) {
		// 0xf2
		mandatory_prefix_ |= PREFIX_REPNE;
		opcode_ = &Opcodes_2Byte_F2[index];
	} else if(prefix_ & PREFIX_REP) {
		// 0xf3
		mandatory_prefix_ |= PREFIX_REP;
		opcode_ = &Opcodes_2Byte_F3[index];
	} else {
		// N/A
		opcode_ = &Opcodes_2Byte_NA[index];	
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_3byte_38(const uint8_t *buf) {
	
	// we got enough room for next byte?
	BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	
	opcode_size_ = 3;
	
	const uint8_t index = buf[opcode_size_ - 1];
	
	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_3Byte_38_66[index];
	} else if(prefix_ & PREFIX_REPNE) {
		// 0xf2
		mandatory_prefix_ |= PREFIX_REPNE;
		opcode_ = &Opcodes_3Byte_38_F2[index];
	} else {
		// N/A
		opcode_ = &Opcodes_3Byte_38_NA[index];
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_3byte_3A(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_3byte_3A(const uint8_t *buf) {
	
	// we got enough room for next byte?
	BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	
	opcode_size_ = 3;
	
	const uint8_t index = buf[opcode_size_ - 1];
		
	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_3Byte_3A_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_3Byte_3A_NA[index];
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group1(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group1(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group1[modrm.reg() + 8 * (buf[0] & 3)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group2(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group2(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;

	opcode_ = &Opcodes_Group2[modrm.reg() + 8 * (buf[0] & 1)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group2D(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group2D(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
		
	opcode_ = &Opcodes_Group2D[modrm.reg() + 8 * (buf[0] & 3)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group3(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group3(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
		
	opcode_ = &Opcodes_Group3[modrm.reg() + 8 * ((buf[0] - 6) & 1)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group4(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group4(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group4[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group5(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group5(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group5[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group6(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group6(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group6[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group7(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group7(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();
	
	if(modrm.mod() == 0x03) {
		opcode_ = &Opcodes_Group7A[(index << 3) | modrm.rm()];
	} else {
		opcode_ = &Opcodes_Group7[index];
	}
	(this->*(opcode_->decoder))(buf);	
}

//------------------------------------------------------------------------------
// Name: decode_group8(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group8(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group8[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group9(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group9(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();

	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		mandatory_prefix_ |= PREFIX_OPERAND;
		opcode_ = &Opcodes_Group9_66[index];
	} else if(prefix_ & PREFIX_REP) {
		// 0xf3
		mandatory_prefix_ |= PREFIX_REP;
		opcode_ = &Opcodes_Group9_F3[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group9[index];	
	}
	
	(this->*(opcode_->decoder))(buf);
}


//------------------------------------------------------------------------------
// Name: decode_group10(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group10(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group10[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}


//------------------------------------------------------------------------------
// Name: decode_group11(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group11(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group11[modrm.reg()];
	(this->*(opcode_->decoder))(buf);
}


//------------------------------------------------------------------------------
// Name: decode_group12(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group12(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group12[modrm.reg() + 8 * ((buf[0] - 6) & 1)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group13(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group13(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();
	
	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group13_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group13[index];	
	}
	
	(this->*(opcode_->decoder))(buf);
}


//------------------------------------------------------------------------------
// Name: decode_group14(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group14(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();
	
	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group14_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group14[index];	
	}
	
	(this->*(opcode_->decoder))(buf);
}


//------------------------------------------------------------------------------
// Name: decode_group15(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group15(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();
	
	if(prefix_ & PREFIX_OPERAND) {
		// 0x66
		opcode_ = &Opcodes_Group15_66[index];
	} else {
		// N/A
		opcode_ = &Opcodes_Group15[index];	
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group16(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group16(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t index = modrm.reg();
	
	if(modrm.mod() == 0x03) {
		opcode_ = &Opcodes_Group16_Reg[index];
	} else {
		opcode_ = &Opcodes_Group16_Mem[index];
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_group17(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_group17(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	opcode_ = &Opcodes_Group17[modrm.reg() + 8 * (buf[1] - 0x18)];
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: decode_Ap(const uint8_t *buf)
// Desc: absolute pointer (32 or 48 bit)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ap(const uint8_t *buf) {
	
	operand_t &operand		= next_operand();
	
	operand.type_			= operand_t::TYPE_ABSOLUTE;
	
	if(prefix_ & PREFIX_OPERAND) {
		operand.absolute.offset	= get_immediate<uint16_t>(buf);
	} else {
		operand.absolute.offset	= get_immediate<uint32_t>(buf);
	}
	
	operand.absolute.seg	= get_immediate<uint16_t>(buf);	
}

//------------------------------------------------------------------------------
// Name: decode_Ib(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ib(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sbyte	= get_immediate<int8_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE8;
}

//------------------------------------------------------------------------------
// Name: decode_Iw(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Iw(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sword	= get_immediate<int16_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE16;
}

//------------------------------------------------------------------------------
// Name: decode_Id(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Id(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sdword	= get_immediate<int32_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE32;
}

//------------------------------------------------------------------------------
// Name: decode_Iq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Iq(const uint8_t *buf) {
	operand_t &operand = next_operand();
	
	operand.sqword	= get_immediate<int64_t>(buf);	
	operand.type_	= operand_t::TYPE_IMMEDIATE64;
}

//------------------------------------------------------------------------------
// Name: decode_Jb(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Jb(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sbyte	= get_immediate<int8_t>(buf);
	operand.type_	= operand_t::TYPE_REL8;
}

//------------------------------------------------------------------------------
// Name: decode_Jw(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Jw(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sword	= get_immediate<int16_t>(buf);
	operand.type_	= operand_t::TYPE_REL16;
}

//------------------------------------------------------------------------------
// Name: decode_Jd(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Jd(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sdword	= get_immediate<int32_t>(buf);
	operand.type_	= operand_t::TYPE_REL32;
}

//------------------------------------------------------------------------------
// Name: decode_Jq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Jq(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sqword	= get_immediate<int64_t>(buf);
	operand.type_	= operand_t::TYPE_REL64;
}

//------------------------------------------------------------------------------
// Name: decode_Ev(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ev(const uint8_t *buf) {

	switch(operand_size()) {
	case 16: decode_Ex<operand_t::TYPE_EXPRESSION16, &Instruction::indexToReg16>(buf); break;
	case 32: decode_Ex<operand_t::TYPE_EXPRESSION32, &Instruction::indexToReg32>(buf); break;
	case 64: decode_Ex<operand_t::TYPE_EXPRESSION64, &Instruction::indexToReg64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Rv(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Rv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Ex<operand_t::TYPE_INVALID, &Instruction::indexToReg16>(buf); break;
	case 32: decode_Ex<operand_t::TYPE_INVALID, &Instruction::indexToReg32>(buf); break;
	case 64: decode_Ex<operand_t::TYPE_INVALID, &Instruction::indexToReg64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Gv(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Gv(const uint8_t *buf) {

	switch(operand_size()) {
	case 16: decode_Gx<&Instruction::indexToReg16>(buf); break;
	case 32: decode_Gx<&Instruction::indexToReg32>(buf); break;
	case 64: decode_Gx<&Instruction::indexToReg64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Iv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Iw(buf); break;
	case 32: decode_Id(buf); break;
	case 64: decode_Iq(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ob(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.type_							= operand_t::TYPE_EXPRESSION8;
	operand.expression.displacement_type	= operand_t::DISP_S32;
	operand.expression.index				= operand_t::REG_NULL;
	operand.expression.base					= operand_t::REG_NULL;
	operand.expression.scale				= 1;
	operand.expression.s_disp32				= get_displacement<int32_t>(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ow(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.type_							= operand_t::TYPE_EXPRESSION16;
	operand.expression.displacement_type	= operand_t::DISP_S32;
	operand.expression.index				= operand_t::REG_NULL;
	operand.expression.base					= operand_t::REG_NULL;
	operand.expression.scale				= 1;
	operand.expression.s_disp32				= get_displacement<int32_t>(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Od(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.type_							= operand_t::TYPE_EXPRESSION32;
	operand.expression.displacement_type	= operand_t::DISP_S32;
	operand.expression.index				= operand_t::REG_NULL;
	operand.expression.base					= operand_t::REG_NULL;
	operand.expression.scale				= 1;
	operand.expression.s_disp32				= get_displacement<int32_t>(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Ov(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Ow(buf); break;
	case 32: decode_Od(buf); break;
	case 64: throw invalid_instruction(Instruction::size()); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_Mv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Mw(buf); break;
	case 32: decode_Md(buf); break;
	case 64: decode_Mq(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_AL(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R8B>(buf); 
	} else {
		decode_Reg<operand_t::REG_AL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_CL(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R9B>(buf); 
	} else {
		decode_Reg<operand_t::REG_CL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_DL(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R10B>(buf); 
	} else {
		decode_Reg<operand_t::REG_DL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_BL(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R11B>(buf); 
	} else {
		decode_Reg<operand_t::REG_BL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_AH(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R12B>(buf); 
	} else {
		decode_Reg<operand_t::REG_AH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_CH(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R13B>(buf); 
	} else {
		decode_Reg<operand_t::REG_CH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_DH(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R14B>(buf); 
	} else {
		decode_Reg<operand_t::REG_DH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_BH(const uint8_t *buf) {
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R15B>(buf); 
	} else {
		decode_Reg<operand_t::REG_BH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rAX_NOREX(const uint8_t *buf) { 
	switch(operand_size()) {;
	case 16: decode_Reg<operand_t::REG_AX>(buf); break;
	case 32: decode_Reg<operand_t::REG_EAX>(buf); break;
	case 64: decode_Reg<operand_t::REG_RAX>(buf);  break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_eAX(const uint8_t *buf) {
	// TODO: is this correct, it seems to be the same
	// because eAX is only used for ops where REX is illegal
	decode_rAX_NOREX(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rAX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R8W>(buf); 
		} else {
			decode_Reg<operand_t::REG_AX>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R8D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EAX>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R8>(buf); 
		} else {
			decode_Reg<operand_t::REG_RAX>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rCX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R9W>(buf); 
		} else {
			decode_Reg<operand_t::REG_CX>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R9D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ECX>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R9>(buf); 
		} else {
			decode_Reg<operand_t::REG_RCX>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rDX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R10W>(buf); 
		} else {
			decode_Reg<operand_t::REG_DX>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R10D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EDX>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R10>(buf); 
		} else {
			decode_Reg<operand_t::REG_RDX>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rBX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R11W>(buf); 
		} else {
			decode_Reg<operand_t::REG_BX>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R11D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EBX>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R11>(buf); 
		} else {
			decode_Reg<operand_t::REG_RBX>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rSP(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R12W>(buf); 
		} else {
			decode_Reg<operand_t::REG_SP>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R12D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ESP>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R12>(buf); 
		} else {
			decode_Reg<operand_t::REG_RSP>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rBP(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R13W>(buf); 
		} else {
			decode_Reg<operand_t::REG_BP>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R13D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EBP>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R13>(buf); 
		} else {
			decode_Reg<operand_t::REG_RBP>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rSI(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R14W>(buf); 
		} else {
			decode_Reg<operand_t::REG_SI>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R14D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ESI>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R14>(buf); 
		} else {
			decode_Reg<operand_t::REG_RSI>(buf); 
		}
		break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rDI(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R15W>(buf); 
		} else {
			decode_Reg<operand_t::REG_DI>(buf); 
		}
		break;
	case 32:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R15D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EDI>(buf); 
		}
		break;
	case 64:
		if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R15>(buf); 
		} else {
			decode_Reg<operand_t::REG_RDI>(buf); 
		}
		break;
	}
}


//EMIT_ALT_NAME_HANDLER(nop, pause, PREFIX_REP, &Instruction::decode, OP_NOP, OP_PAUSE)
//------------------------------------------------------------------------------
// Name: decode_rAX_rAX_NOREX(const uint8_t *buf
// NOTE: special case because this represents 3 possible ops!
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode_rAX_rAX_NOREX(const uint8_t *buf) {
	static const OpcodeEntry opcodes[] = {
		{ "nop",	&Instruction::decode0, OP_NOP, FLAG_NONE },
		{ "pause",	&Instruction::decode0, OP_PAUSE, FLAG_NONE },
		{ "xchg", 	&Instruction::template decode2<&instruction_t::decode_rAX, &instruction_t::decode_rAX_NOREX>, OP_XCHG, FLAG_NONE }
	};
	
	// TODO: does F3 or xchg r8, rAX take precidence
	if(Model::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		opcode_ = &opcodes[2];
	} else if(prefix_ & PREFIX_REP) {
		mandatory_prefix_ |= PREFIX_REP;
		opcode_ = &opcodes[1];	/* with 0xf3 */
	} else {
		opcode_ = &opcodes[0];	/* without 0xf3 */
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: operand_size() const
//------------------------------------------------------------------------------
template <class Model>
int Instruction<Model>::operand_size() const {
	int ret = 32;
		
	// we check if 16-bit mode is enabled
	if(prefix_ & PREFIX_OPERAND) {
		ret = 16;
	}
	
	// we check if 64-bit mode is enabled
	if(Model::BITS == 64) {
		if(rex_byte_.is_rex() && rex_byte_.w()) {
			ret = 64;
		} else {
			const Type type = opcode_->type;
			// push/pop/jmp/call defaults to 64-bit even without prefix
			if(type == OP_PUSH || type == OP_POP || type == OP_PUSHF || type == OP_POPF || type == OP_CALL || type == OP_JMP || type == OP_JCC) {
				ret = 64;
			}
		}
	}
	
	return ret;
}

//------------------------------------------------------------------------------
// Name: decode0(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class Model>
void Instruction<Model>::decode0(const uint8_t *buf) {
	UNUSED(buf);
	// does nothing
}

//------------------------------------------------------------------------------
// Name: format_prefix() const
//------------------------------------------------------------------------------
template <class Model>
std::string Instruction<Model>::format_prefix() const {
	std::string ret;
	
	if((prefix_ & PREFIX_LOCK) && !(mandatory_prefix_ & PREFIX_LOCK)) {
		// TODO: this is only legal for the memory dest versions of:
		// ADD, ADC, AND, BTC, BTR, BTS, CMPXCHG, CMPXCH8B, (CMPXCH16B?)
		// DEC, INC, NEG, NOT, OR, SBB, SUB, XOR, XADD, XCHG
		ret = "lock ";
		
	} else if((prefix_ & PREFIX_REP) && !(mandatory_prefix_ & PREFIX_REP)) {
		if(type() == OP_CMPS || type() == OP_SCAS) {
			ret = "repe ";
		} else {
			// TODO: this is only legal for:
			// INS, OUTS, MOVS, LODS and STOS
			ret = "rep ";
		}
	} else if((prefix_ & PREFIX_REPNE) && !(mandatory_prefix_ & PREFIX_REPNE)) {
		// TODO: this is only legal for:
		// CMPS and SCAS
		ret = "repne ";
	}
	
	return ret;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class Model>
template <void (Instruction<Model>::*F1)(const uint8_t *), void (Instruction<Model>::*F2)(const uint8_t *)>
void Instruction<Model>::decode_Reg_Mem(const uint8_t *buf) {
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}

	const ModRM rm(buf[opcode_size_]);
	modrm_size_ = 1;

	if(rm.mod() == 0x03) {
		(this->*F1)(buf);
	} else {
		(this->*F2)(buf);
	}
}

#endif

