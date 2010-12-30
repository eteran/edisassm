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
template <class M>
template <typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_Gx(const uint8_t *buf) {

	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}

	const ModRM rm(buf[opcode_size_]);
	modrm_size_ = 1;

	int regindex = rm.reg();
	if(M::BITS == 64 && rex_byte_.is_rex()) {
		regindex |= (rex_byte_.r() << 3);
		
		if(REG_DECODE == &index_to_reg_8) {
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
template <class M>
template <int index>
void Instruction<M>::decode_STi(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand	= next_operand();
	operand.reg			= index_to_reg_fpu(index);
	operand.type_		= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_0_16(const uint8_t *buf, const ModRM &rm, operand_t &operand)
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_0_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {

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
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_1_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {

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
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_2_16(const uint8_t *buf, const ModRM &rm, operand_t &operand) {
	
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
template <class M>
template <typename Operand<M>::Register REG>
void Instruction<M>::decode_Reg(const uint8_t *buf) {
	UNUSED(buf);

	operand_t &operand = next_operand();

	operand.reg 	= REG;
	operand.type_	= operand_t::TYPE_REGISTER;
}

//------------------------------------------------------------------------------
// Name: decode_const_Iq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
template <int64_t IMM>
void Instruction<M>::decode_const_Iq(const uint8_t *buf) {
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
template <class M>
template <int32_t IMM>
void Instruction<M>::decode_const_Id(const uint8_t *buf) {
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
template <class M>
template <int16_t IMM>
void Instruction<M>::decode_const_Iw(const uint8_t *buf) {
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
template <class M>
template <int8_t IMM>
void Instruction<M>::decode_const_Ib(const uint8_t *buf) {
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
template <class M>
template <class T>
T Instruction<M>::get_immediate(const uint8_t *buf) {
	BOUNDS_CHECK(Instruction::size() + sizeof(T), buffer_size_);

	const T ret = *reinterpret_cast<const T *>(&buf[opcode_size_ + modrm_size_ + sib_size_ + disp_size_ + immediate_size_]);
	immediate_size_ += sizeof(T);
	return ret;
}

//------------------------------------------------------------------------------
// Name: get_displacement(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
template <class T>
T Instruction<M>::get_displacement(const uint8_t *buf) {		
	
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
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_0_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {

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

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {

			if(M::BITS == 64 && enable_64_bit) {
				operand.expression.index	= index_to_reg_64(sibindex);
			} else {
				operand.expression.index	= index_to_reg_32(sibindex);
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

			if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
				sibbase |= (rex_byte_.b() << 3);
			}
			
			if(M::BITS == 64 && enable_64_bit) {
				operand.expression.base				= index_to_reg_64(sibbase);
			} else {
				operand.expression.base				= index_to_reg_32(sibbase);
			}
			operand.expression.displacement_type	= operand_t::DISP_NONE;
		}
	} else if(rm.rm() == 0x05) {
		if(M::BITS == 64 && enable_64_bit) {
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

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}
		
		if(M::BITS == 64 && enable_64_bit) {
			operand.expression.base					= index_to_reg_64(rmbase);
		} else {
			operand.expression.base					= index_to_reg_32(rmbase);
		}
		operand.expression.s_disp8				= 0;
		operand.expression.displacement_type	= operand_t::DISP_NONE;
	}
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_1_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_1_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {

	UNUSED(enable_64_bit);

	if(rm.rm() == 0x04) {
		
		// we got enough room for the SIB byte?
		if(sib_size_ == 0) {
			BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
		}

		sib_size_ = 1;
		const SIB sib(buf[opcode_size_ + modrm_size_]);

		int sibbase = sib.base();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibbase |= (rex_byte_.b() << 3);
		}

		if(M::BITS == 64 && enable_64_bit) {
			operand.expression.base	= index_to_reg_64(sibbase);
		} else {
			operand.expression.base	= index_to_reg_32(sibbase);
		}
		operand.expression.scale = 1 << sib.scale();

		int sibindex = sib.index();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {			
			if(M::BITS == 64 && enable_64_bit) {			
				operand.expression.index = index_to_reg_64(sibindex);
			} else {
				operand.expression.index = index_to_reg_32(sibindex);
			}
		} else {
			operand.expression.index = operand_t::REG_NULL;		
		}
	} else {
		operand.expression.index = operand_t::REG_NULL;
		operand.expression.scale = 1;

		int rmbase = rm.rm();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}

		if(M::BITS == 64 && enable_64_bit) {
			operand.expression.base = index_to_reg_64(rmbase);
		} else {
			operand.expression.base = index_to_reg_32(rmbase);
		}
		
	}
	
	operand.type_							= TYPE;
	operand.expression.s_disp8				= get_displacement<int8_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S8;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_2_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_2_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {
	
	UNUSED(enable_64_bit);

	if(rm.rm() == 0x04) {
		// we got enough room for the SIB byte?
		if(sib_size_ == 0) {
			BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
		}

		sib_size_ = 1;
		const SIB sib(buf[opcode_size_ + modrm_size_]);
	
		int sibbase = sib.base();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibbase |= (rex_byte_.b() << 3);
		}

		if(M::BITS == 64 && enable_64_bit) {
			operand.expression.base = index_to_reg_64(sibbase);
		} else {
			operand.expression.base = index_to_reg_32(sibbase);
		}
		
		operand.expression.scale	= 1 << sib.scale();

		int sibindex = sib.index();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			sibindex |= (rex_byte_.x() << 3);
		}

		if(sibindex != 0x04) {
			if(M::BITS == 64 && enable_64_bit) {
				operand.expression.index = index_to_reg_64(sibindex);
			} else {
				operand.expression.index = index_to_reg_32(sibindex);
			}
			
		} else {
			operand.expression.index = operand_t::REG_NULL;
		}
	} else {
		operand.expression.index = operand_t::REG_NULL;
		operand.expression.scale = 1;
	
		int rmbase = rm.rm();

		if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
			rmbase |= (rex_byte_.b() << 3);
		}
		
		if(M::BITS == 64 && enable_64_bit) {
			operand.expression.base = index_to_reg_64(rmbase);
		} else {
			operand.expression.base = index_to_reg_32(rmbase);
		}
		
	}
	
	operand.type_							= TYPE;
	operand.expression.s_disp32				= get_displacement<int32_t>(buf);
	operand.expression.displacement_type	= operand_t::DISP_S32;
}

//------------------------------------------------------------------------------
// Name: decode_ModRM_3_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit)
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_3_32(const uint8_t *buf, const ModRM &rm, operand_t &operand, bool enable_64_bit) {
	UNUSED(buf);
	UNUSED(enable_64_bit);

	int rmbase	= rm.rm();
	
	if(M::BITS == 64 && rex_byte_.is_rex() && enable_64_bit) {
		rmbase |= (rex_byte_.b() << 3);
		if(REG_DECODE == &index_to_reg_8) {
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
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_ModRM_Invalid(const uint8_t *buf, const ModRM &rm, operand_t &operand) {
	UNUSED(rm);
	UNUSED(operand);
	UNUSED(buf);
	throw invalid_operand(Instruction::size());
}

//------------------------------------------------------------------------------
// Name: decode_Ex(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
template <typename Operand<M>::Type TYPE, typename Operand<M>::Register (*REG_DECODE)(uint8_t)>
void Instruction<M>::decode_Ex(const uint8_t *buf) {

	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
	
	const ModRM rm(buf[opcode_size_]);
	modrm_size_ = 1;

	operand_t &operand = next_operand();

	if(prefix_ & PREFIX_ADDRESS) {	
		if(M::BITS == 64) {
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
template <class M>
template <void (Instruction<M>::*F1)(const uint8_t *), void (Instruction<M>::*F2)(const uint8_t *), void (Instruction<M>::*F3)(const uint8_t *)>
void Instruction<M>::decode3(const uint8_t *buf) {
	(this->*F1)(buf);
	(this->*F2)(buf);
	(this->*F3)(buf);
}

//------------------------------------------------------------------------------
// Name: decode2(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
template <void (Instruction<M>::*F1)(const uint8_t *), void (Instruction<M>::*F2)(const uint8_t *)>
void Instruction<M>::decode2(const uint8_t *buf) {
	(this->*F1)(buf);
	(this->*F2)(buf);
}

//------------------------------------------------------------------------------
// Name: decode1(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
template <void (Instruction<M>::*F1)(const uint8_t *)>
void Instruction<M>::decode1(const uint8_t *buf) {
	(this->*F1)(buf);
}

//------------------------------------------------------------------------------
// Name: Instruction(const uint8_t *buf, std::size_t size, address_t rva, const std::nothrow_t&) throw()
//------------------------------------------------------------------------------
template <class M>
Instruction<M>::Instruction(const uint8_t *buf, std::size_t size, address_t rva, const std::nothrow_t&) throw()
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
template <class M>
Instruction<M>::Instruction(const uint8_t *buf, std::size_t size, address_t rva) 
		: rva_(rva), buffer_(buf), buffer_size_(size), opcode_(0), type_(OP_INVALID), 
		prefix_(0), mandatory_prefix_(0), operand_count_(0), modrm_size_(0), 
		sib_size_(0), disp_size_(0), prefix_size_(0), immediate_size_(0),
		opcode_size_(0), rex_byte_(0), rex_size_(0), private_buffer_(false) {
		
	initialize(buf, size);
}

//------------------------------------------------------------------------------
// Name: ~Instruction()
//------------------------------------------------------------------------------
template <class M>
Instruction<M>::~Instruction() {
	if(private_buffer_) {
		delete [] buffer_;
	}
}

//------------------------------------------------------------------------------
// Name: initialize(const uint8_t *buf, std::size_t size)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::initialize(const uint8_t *buf, std::size_t size) {
	
	for(int i = 0; i < M::MAX_OPERANDS; ++i) {
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
template <class M>
Instruction<M>::Instruction(const Instruction &other) :
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

	for(int i = 0; i < M::MAX_OPERANDS; ++i) {
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
template <class M>
Instruction<M> &Instruction<M>::operator=(const Instruction &rhs) {
	if(this != &rhs) {
		Instruction(rhs).swap(*this);
	}
	return *this;
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::swap(Instruction &other) {
	for(int i = 0; i < M::MAX_OPERANDS; ++i) {
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
template <class M>
template <class T, int N>
void Instruction<M>::find_opcode(const std::string &opcode, T (&table)[N], int opcode_count) {
	(void)opcode_count;
	
	for(size_t i = 0; i < N; ++i) {
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
template <class M>
void Instruction<M>::assemble(std::string instruction) {

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
template <class M>
void Instruction<M>::process_prefixes(const uint8_t *&buf, std::size_t size) {

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
	
	if(M::BITS == 64) {
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
template <class M>
typename Instruction<M>::operand_t &Instruction<M>::next_operand() {

	if(operand_count_ >= M::MAX_OPERANDS) {
		throw too_many_operands(size());
	}
	
	operand_t &ret = operands_[operand_count_++];
	ret.set_owner(this);
	return ret;
}

//------------------------------------------------------------------------------
// Name: decode_invalid(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_invalid(const uint8_t *buf) {
	UNUSED(buf);
	throw invalid_instruction(Instruction<M>::size());
}

template <class M> void Instruction<M>::decode_cbw_cwde_cdqe(const uint8_t *buf)				{ static const OpcodeEntry opcodes[] = { { "cbw",     &Instruction::decode0, OP_CBW, FLAG_NONE },            { "cwde",      &Instruction::decode0, OP_CWDE, FLAG_NONE },        { "cdqe",       &Instruction::decode0, OP_CDQE, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_cwd_cdq_cqo(const uint8_t *buf)					{ static const OpcodeEntry opcodes[] = { { "cwd",     &Instruction::decode0, OP_CWD, FLAG_NONE },            { "cdq",       &Instruction::decode0, OP_CDQ, FLAG_NONE },         { "cqo",        &Instruction::decode0, OP_CQO, FLAG_NONE } };            decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_stosw_stosd_stosq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "stosw",   &Instruction::decode0, OP_STOS, FLAG_NONE },           { "stosd",     &Instruction::decode0, OP_STOS, FLAG_NONE },        { "stosq",      &Instruction::decode0, OP_STOS, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_lodsw_lodsd_lodsq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "lodsw",   &Instruction::decode0, OP_LODS, FLAG_NONE },           { "lodsd",     &Instruction::decode0, OP_LODS, FLAG_NONE },        { "lodsq",      &Instruction::decode0, OP_LODS, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_scasw_scasd_scasq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "scasw",   &Instruction::decode0, OP_SCAS, FLAG_NONE },           { "scasd",     &Instruction::decode0, OP_SCAS, FLAG_NONE },        { "scasq",      &Instruction::decode0, OP_SCAS, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_iretw_iret_iretq(const uint8_t *buf)				{ static const OpcodeEntry opcodes[] = { { "iretw",   &Instruction::decode0, OP_IRET, FLAG_NONE },           { "iret",      &Instruction::decode0, OP_IRET, FLAG_NONE },        { "iretq",      &Instruction::decode0, OP_IRET, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_movsw_movsd_movsq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "movsw",   &Instruction::decode0, OP_MOVS, FLAG_NONE },           { "movsd",     &Instruction::decode0, OP_MOVS, FLAG_NONE },        { "movsq",      &Instruction::decode0, OP_MOVS, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_popfw_popfd_popfq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "popfw",   &Instruction::decode0, OP_POPF, FLAG_NONE },           { "popfd",     &Instruction::decode0, OP_POPF, FLAG_NONE },        { "popfq",      &Instruction::decode0, OP_POPF, FLAG_NONE } };           decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_pushfw_pushfd_pushfq(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "pushfw",  &Instruction::decode0, OP_PUSHF, FLAG_NONE },          { "pushfd",    &Instruction::decode0, OP_PUSHF, FLAG_NONE },       { "pushfq",     &Instruction::decode0, OP_PUSHF, FLAG_NONE } };          decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_invalid_cmpxchg8b_cmpxchg16b(const uint8_t *buf)	{ static const OpcodeEntry opcodes[] = { { "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }, { "cmpxchg8b", &Instruction::decode_Mo, OP_CMPXCHG8B, FLAG_NONE }, { "cmpxchg16b", &Instruction::decode_Mo, OP_CMPXCHG16B, FLAG_NONE } };   decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_insw_insd_invalid(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "insw",    &Instruction::decode0, OP_INS, FLAG_NONE },            { "insd",      &Instruction::decode0, OP_INS, FLAG_NONE },         { "invalid",    &Instruction::decode_invalid, OP_INVALID, FLAG_NONE } }; decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_outsw_outsd_invalid(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "outsw",   &Instruction::decode0, OP_OUTS, FLAG_NONE },           { "outsd",     &Instruction::decode0, OP_OUTS, FLAG_NONE },        { "invalid",    &Instruction::decode_invalid, OP_INVALID, FLAG_NONE } }; decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_cmpsw_cmpsd_invalid(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "cmpsw",   &Instruction::decode0, OP_CMPS, FLAG_NONE },           { "cmpsd",     &Instruction::decode0, OP_CMPS, FLAG_NONE },        { "invalid",    &Instruction::decode_invalid, OP_INVALID, FLAG_NONE } }; decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_pushaw_pushad_invalid(const uint8_t *buf)		{ static const OpcodeEntry opcodes[] = { { "pushaw",  &Instruction::decode0, OP_PUSHA, FLAG_NONE },          { "pushad",    &Instruction::decode0, OP_PUSHA, FLAG_NONE },       { "invalid",    &Instruction::decode_invalid, OP_INVALID, FLAG_NONE } }; decode_size_sensitive(buf, opcodes);}
template <class M> void Instruction<M>::decode_popaw_popad_invalid(const uint8_t *buf)			{ static const OpcodeEntry opcodes[] = { { "popaw",   &Instruction::decode0, OP_POPA, FLAG_NONE },           { "popad",     &Instruction::decode0, OP_POPA, FLAG_NONE },        { "invalid",    &Instruction::decode_invalid, OP_INVALID, FLAG_NONE } }; decode_size_sensitive(buf, opcodes);}

//------------------------------------------------------------------------------
// Name: decode_x87(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_x87(const uint8_t *buf) {
	
	// we got enough room for the ModRM byte?
	if(modrm_size_ == 0) {
		BOUNDS_CHECK(Instruction::size() + 1, buffer_size_);
	}
		
	const ModRM modrm(buf[opcode_size_]);
	modrm_size_ = 1;
	
	const uint8_t esc_num = (buf[0] - 0xd8);
	const uint8_t byte2 = buf[opcode_size_];
	
	if((byte2 & 0xc0) != 0xc0) {
		opcode_ = &Opcodes_x87_Lo[modrm.reg() + esc_num * 8];
	} else {
		opcode_ = &Opcodes_x87_Hi[(byte2 & 0x3f) + esc_num * 64];
	}
	
	(this->*(opcode_->decoder))(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_2byte(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_3byte_38(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_3byte_3A(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group1(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group2(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group2D(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group3(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group4(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group5(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group6(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group7(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group8(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group9(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group10(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group11(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group12(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group13(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group14(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group15(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group16(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_group17(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_Ap(const uint8_t *buf) {
	
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
template <class M>
void Instruction<M>::decode_Ib(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sbyte	= get_immediate<int8_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE8;
}

//------------------------------------------------------------------------------
// Name: decode_Iw(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iw(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sword	= get_immediate<int16_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE16;
}

//------------------------------------------------------------------------------
// Name: decode_Id(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Id(const uint8_t *buf) {
	operand_t &operand = next_operand();

	operand.sdword	= get_immediate<int32_t>(buf);
	operand.type_	= operand_t::TYPE_IMMEDIATE32;
}

//------------------------------------------------------------------------------
// Name: decode_Iq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iq(const uint8_t *buf) {
	operand_t &operand = next_operand();
	
	operand.sqword	= get_immediate<int64_t>(buf);	
	operand.type_	= operand_t::TYPE_IMMEDIATE64;
}

//------------------------------------------------------------------------------
// Name: decode_Jb(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jb(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sbyte	= get_immediate<int8_t>(buf);
	operand.type_	= operand_t::TYPE_REL8;
}

//------------------------------------------------------------------------------
// Name: decode_Jw(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jw(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sword	= get_immediate<int16_t>(buf);
	operand.type_	= operand_t::TYPE_REL16;
}

//------------------------------------------------------------------------------
// Name: decode_Jd(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jd(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sdword	= get_immediate<int32_t>(buf);
	operand.type_	= operand_t::TYPE_REL32;
}

//------------------------------------------------------------------------------
// Name: decode_Jq(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Jq(const uint8_t *buf) {
	
	operand_t &operand = next_operand();
	
	operand.sqword	= get_immediate<int64_t>(buf);
	operand.type_	= operand_t::TYPE_REL64;
}

//------------------------------------------------------------------------------
// Name: decode_Ev(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ev(const uint8_t *buf) {

	switch(operand_size()) {
	case 16: decode_Ex<operand_t::TYPE_EXPRESSION16, &Instruction::index_to_reg_16>(buf); break;
	case 32: decode_Ex<operand_t::TYPE_EXPRESSION32, &Instruction::index_to_reg_32>(buf); break;
	case 64: decode_Ex<operand_t::TYPE_EXPRESSION64, &Instruction::index_to_reg_64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Rv(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Rv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Ex<operand_t::TYPE_INVALID, &Instruction::index_to_reg_16>(buf); break;
	case 32: decode_Ex<operand_t::TYPE_INVALID, &Instruction::index_to_reg_32>(buf); break;
	case 64: decode_Ex<operand_t::TYPE_INVALID, &Instruction::index_to_reg_64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: decode_Gv(const uint8_t *buf)
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Gv(const uint8_t *buf) {

	switch(operand_size()) {
	case 16: decode_Gx<&Instruction::index_to_reg_16>(buf); break;
	case 32: decode_Gx<&Instruction::index_to_reg_32>(buf); break;
	case 64: decode_Gx<&Instruction::index_to_reg_64>(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Iv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Iw(buf); break;
	case 32: decode_Id(buf); break;
	case 64: decode_Iq(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Ob(const uint8_t *buf) {
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
template <class M>
void Instruction<M>::decode_Ow(const uint8_t *buf) {
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
template <class M>
void Instruction<M>::decode_Od(const uint8_t *buf) {
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
template <class M>
void Instruction<M>::decode_Ov(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Ow(buf); break;
	case 32: decode_Od(buf); break;
	case 64: throw invalid_instruction(Instruction::size()); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_Mv(const uint8_t *buf) {
	switch(operand_size()) {
	case 16: decode_Mw(buf); break;
	case 32: decode_Md(buf); break;
	case 64: decode_Mq(buf); break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_AL(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R8B>(buf); 
	} else {
		decode_Reg<operand_t::REG_AL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_CL(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R9B>(buf); 
	} else {
		decode_Reg<operand_t::REG_CL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_DL(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R10B>(buf); 
	} else {
		decode_Reg<operand_t::REG_DL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_BL(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R11B>(buf); 
	} else {
		decode_Reg<operand_t::REG_BL>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_AH(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R12B>(buf); 
	} else {
		decode_Reg<operand_t::REG_AH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_CH(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R13B>(buf); 
	} else {
		decode_Reg<operand_t::REG_CH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_DH(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R14B>(buf); 
	} else {
		decode_Reg<operand_t::REG_DH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_BH(const uint8_t *buf) {
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
		decode_Reg<operand_t::REG_R15B>(buf); 
	} else {
		decode_Reg<operand_t::REG_BH>(buf);
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rAX_NOREX(const uint8_t *buf) { 
	switch(operand_size()) {;
	case 16: decode_Reg<operand_t::REG_AX>(buf); break;
	case 32: decode_Reg<operand_t::REG_EAX>(buf); break;
	case 64: decode_Reg<operand_t::REG_RAX>(buf);  break;
	}
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_eAX(const uint8_t *buf) {
	// TODO: is this correct, it seems to be the same
	// because eAX is only used for ops where REX is illegal
	decode_rAX_NOREX(buf);
}

//------------------------------------------------------------------------------
// Name: 
//------------------------------------------------------------------------------
template <class M>
void Instruction<M>::decode_rAX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R8W>(buf); 
		} else {
			decode_Reg<operand_t::REG_AX>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R8D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EAX>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rCX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R9W>(buf); 
		} else {
			decode_Reg<operand_t::REG_CX>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R9D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ECX>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rDX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R10W>(buf); 
		} else {
			decode_Reg<operand_t::REG_DX>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R10D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EDX>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rBX(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R11W>(buf); 
		} else {
			decode_Reg<operand_t::REG_BX>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R11D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EBX>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rSP(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R12W>(buf); 
		} else {
			decode_Reg<operand_t::REG_SP>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R12D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ESP>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rBP(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R13W>(buf); 
		} else {
			decode_Reg<operand_t::REG_BP>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R13D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EBP>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rSI(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R14W>(buf); 
		} else {
			decode_Reg<operand_t::REG_SI>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R14D>(buf); 
		} else {
			decode_Reg<operand_t::REG_ESI>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rDI(const uint8_t *buf) { 
	switch(operand_size()) {
	case 16: 
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R15W>(buf); 
		} else {
			decode_Reg<operand_t::REG_DI>(buf); 
		}
		break;
	case 32:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
			decode_Reg<operand_t::REG_R15D>(buf); 
		} else {
			decode_Reg<operand_t::REG_EDI>(buf); 
		}
		break;
	case 64:
		if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
void Instruction<M>::decode_rAX_rAX_NOREX(const uint8_t *buf) {
	static const OpcodeEntry opcodes[] = {
		{ "nop",	&Instruction::decode0, OP_NOP, FLAG_NONE },
		{ "pause",	&Instruction::decode0, OP_PAUSE, FLAG_NONE },
		{ "xchg", 	&Instruction::template decode2<&instruction_t::decode_rAX, &instruction_t::decode_rAX_NOREX>, OP_XCHG, FLAG_NONE }
	};
	
	// TODO: does F3 or xchg r8, rAX take precidence
	if(M::BITS == 64 && rex_byte_.is_rex() && rex_byte_.b()) {
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
template <class M>
int Instruction<M>::operand_size() const {
	int ret = 32;
		
	// we check if 16-bit mode is enabled
	if(prefix_ & PREFIX_OPERAND) {
		ret = 16;
	}
	
	// we check if 64-bit mode is enabled
	if(M::BITS == 64) {
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
template <class M>
void Instruction<M>::decode0(const uint8_t *buf) {
	UNUSED(buf);
	// does nothing
}

//------------------------------------------------------------------------------
// Name: format_prefix() const
//------------------------------------------------------------------------------
template <class M>
std::string Instruction<M>::format_prefix() const {
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
template <class M>
template <void (Instruction<M>::*F1)(const uint8_t *), void (Instruction<M>::*F2)(const uint8_t *)>
void Instruction<M>::decode_Reg_Mem(const uint8_t *buf) {
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

