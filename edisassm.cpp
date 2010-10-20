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

#include "Instruction.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cstring>

#define SHOW_BYTES

template <class Model>
void disassemble(const uint8_t *start_ptr, const uint8_t *end_ptr) {
	
	typedef Instruction<Model> insn_t;
	
	const uint8_t *ptr = start_ptr;
	while(ptr < end_ptr) {
		const typename insn_t::address_t addr = 0x10000000;
		insn_t instruction(ptr, end_ptr - ptr,  addr + (ptr - start_ptr), std::nothrow);
		if(instruction.valid()) {
			std::cout << std::hex << (addr + (ptr - start_ptr)) << ": ";
#ifdef SHOW_BYTES
			for(unsigned int i = 0; i < instruction.size(); ++i) {
				std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[i]) << " " << std::dec;;
			}
#endif
			std::cout << instruction.format() << std::endl;
			ptr += instruction.size();
		} else {
			std::cout << "(bad)" << std::endl;
			ptr += 1;
		}
	}
}

int main(int argc, char *argv[]) {
#if 0
	// assembler test
	Instruction<edisassm::x86>::assemble("push eax, eax");
#else

	if(argc == 3) {
		std::ifstream file(argv[2], std::ios::binary);
		if(file) {
		
			std::vector<uint8_t> data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

			const uint8_t *const start_ptr = &data[0];
			const uint8_t *const end_ptr = start_ptr + data.size();
			
			if(std::strcmp(argv[1], "-m32") == 0) {
				disassemble<edisassm::x86>(start_ptr, end_ptr);
			} else if(std::strcmp(argv[1], "-m64") == 0) {
				disassemble<edisassm::x86_64>(start_ptr, end_ptr);
			} else {
				std::cout << argv[0] << " [-m32|-m64] <file>" << std::endl;
			}
		}
	} else if(argc == 2) {
		std::ifstream file(argv[1], std::ios::binary);
		if(file) {
		
			std::vector<uint8_t> data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());	

			const uint8_t *const start_ptr = &data[0];
			const uint8_t *const end_ptr = start_ptr + data.size();
			
			disassemble<edisassm::x86>(start_ptr, end_ptr);
		}
	} else {
		std::cout << argv[0] << " [-m32|-m64] <file>" << std::endl;
	}
#endif
}
