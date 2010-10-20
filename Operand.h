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

#ifndef OPERAND_20070521_H_
#define OPERAND_20070521_H_

#include <string>
#include "edisassm_types.h"
#include "edisassm_util.h"
#include "edisassm_exception.h"

template <class Model>
class Instruction;

template <class Model>
class Operand {
private:
	friend class Instruction<Model>;
	
public:
	Operand();
	~Operand() {}

private:
	typedef Operand<Model>				operand_t;
	typedef typename Model::address_t	address_t;
	typedef Instruction<Model>			instruction_t;
	
private:
	instruction_t *owner_;

public:
	enum Register {
		// a special value to mean "no register used" when appropriate
		REG_NULL,
		
		REG_RAX,	REG_RCX,	REG_RDX,	REG_RBX,
		REG_RSP,	REG_RBP,	REG_RSI,	REG_RDI,
		REG_R8,		REG_R9,		REG_R10,	REG_R11,
		REG_R12,	REG_R13,	REG_R14,	REG_R15,
			
		REG_EAX,	REG_ECX,	REG_EDX,	REG_EBX,
		REG_ESP,	REG_EBP,	REG_ESI,	REG_EDI,
		REG_R8D,	REG_R9D,	REG_R10D,	REG_R11D,
		REG_R12D,	REG_R13D,	REG_R14D,	REG_R15D,
		
		REG_AX,		REG_CX,		REG_DX,		REG_BX,
		REG_SP,		REG_BP,		REG_SI,		REG_DI,
		REG_R8W,	REG_R9W,	REG_R10W,	REG_R11W,
		REG_R12W,	REG_R13W,	REG_R14W,	REG_R15W,
		
		REG_AL,		REG_CL,		REG_DL,		REG_BL,
		REG_AH,		REG_CH,		REG_DH,		REG_BH,
		REG_R8B,	REG_R9B,	REG_R10B,	REG_R11B,
		REG_R12B,	REG_R13B,	REG_R14B,	REG_R15B,
		REG_SPL,	REG_BPL,	REG_SIL,	REG_DIL,
		
		
		REG_ES,		REG_CS,		REG_SS,		REG_DS,
		REG_FS,		REG_GS,		REG_SEG7,	REG_SEG8,
		
		REG_CR0,	REG_CR1,	REG_CR2,	REG_CR3,
		REG_CR4,	REG_CR5,	REG_CR6,	REG_CR7,
		REG_CR8,	REG_CR9,	REG_CR10,	REG_CR11,
		REG_CR12,	REG_CR13,	REG_CR14,	REG_CR15,
		
		REG_DR0,	REG_DR1,	REG_DR2,	REG_DR3,
		REG_DR4,	REG_DR5,	REG_DR6,	REG_DR7,
		REG_DR8,	REG_DR9,	REG_DR10,	REG_DR11,
		REG_DR12,	REG_DR13,	REG_DR14,	REG_DR15,
		
		REG_TR0,	REG_TR1,	REG_TR2,	REG_TR3,
		REG_TR4,	REG_TR5,	REG_TR6,	REG_TR7,
		
		REG_MM0,	REG_MM1,	REG_MM2,	REG_MM3,
		REG_MM4,	REG_MM5,	REG_MM6,	REG_MM7,
		
		REG_XMM0,	REG_XMM1,	REG_XMM2,	REG_XMM3,
		REG_XMM4,	REG_XMM5,	REG_XMM6,	REG_XMM7,	
		REG_XMM8,	REG_XMM9,	REG_XMM10,	REG_XMM11,
		REG_XMM12,	REG_XMM13,	REG_XMM14,	REG_XMM15,	
		
		REG_ST,
		REG_ST0,	REG_ST1,	REG_ST2,	REG_ST3,
		REG_ST4,	REG_ST5,	REG_ST6,	REG_ST7,
		
		REG_RIP,
		REG_EIP,
		
		// special value meaning an error in decoding
		REG_INVALID
	};

	enum Type {
		TYPE_INVALID		= 0x00000000,
		TYPE_REGISTER		= 0x00000100,
		TYPE_IMMEDIATE		= 0x00000200,
		TYPE_IMMEDIATE8		= 0x00000201,
		TYPE_IMMEDIATE16	= 0x00000202,
		TYPE_IMMEDIATE32	= 0x00000203,
		TYPE_IMMEDIATE64	= 0x00000204,
		TYPE_REL			= 0x00000300,
		TYPE_REL8			= 0x00000301,
		TYPE_REL16			= 0x00000302,
		TYPE_REL32			= 0x00000303,
		TYPE_REL64			= 0x00000304,
		TYPE_EXPRESSION		= 0x00000400,
		TYPE_EXPRESSION8	= 0x00000401,
		TYPE_EXPRESSION16	= 0x00000402,
		TYPE_EXPRESSION32	= 0x00000403,
		TYPE_EXPRESSION48	= 0x00000404,
		TYPE_EXPRESSION64	= 0x00000405,
		TYPE_EXPRESSION80	= 0x00000406,
		TYPE_EXPRESSION128	= 0x00000407,
		TYPE_ABSOLUTE		= 0x00000500,
		TYPE_MASK			= 0xffffff00
	};
	
private:
	Type type_;
	
public:


	enum DisplacementType {
		DISP_NONE,
		DISP_U8,
		DISP_U16,
		DISP_U32,
		DISP_S8,
		DISP_S16,
		DISP_S32
	};

	union {
		int8_t		sbyte;
		int16_t		sword;
		int32_t		sdword;
		int64_t		sqword;
		uint8_t		byte;
		uint16_t	word;
		uint32_t	dword;
		uint64_t	qword;
		Register	reg;
		
		struct {
			uint16_t seg;
			uint32_t offset;
		} absolute;


		struct {
			union {
				int8_t		s_disp8;
				int16_t		s_disp16;
				int32_t		s_disp32;
				uint8_t		u_disp8;
				uint16_t	u_disp16;
				uint32_t	u_disp32;
			};
			
			DisplacementType	displacement_type;
			Register			base;
			Register			index;
			uint8_t				scale;
		} expression;
	};

private:
	std::string format_immediate(bool upper) const;
	std::string format_relative(bool upper) const;
	std::string format_expression(bool upper) const;
	std::string format_absolute(bool upper) const;
	std::string format_register(bool upper) const;
		
	template <class T> 
	static std::string hex_string(T value, bool upper);
	
public:
	std::string to_string() const;
	std::string to_string(bool upper) const;
	
public:
	void swap(Operand &other);
	instruction_t *owner() const	{ return owner_; }
	int32_t displacement() const;
	int64_t immediate() const;
	address_t relative_target() const;
	Type general_type() const;
	Type complete_type() const		{ return type_; }
	bool valid() const				{ return type_ != TYPE_INVALID; }
	
private:
	void invalidate()						{ type_ = TYPE_INVALID; }
	void set_owner(instruction_t *owner)	{ owner_ = owner; }
	
public:
	static std::string register_name(Register reg) { return RegisterName[reg]; }
	
private:
	static const char *RegisterName[];
};

#include "Operand.tcc"

#endif

