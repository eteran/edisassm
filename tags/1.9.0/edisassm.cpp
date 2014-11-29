/*
Copyright (C) 2006 - 2014 Evan Teran
                          eteran@alum.rit.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Instruction.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cstring>

namespace {

enum DISPLAY_FLAGS {
	FLAG_NONE       = 0x00,
	FLAG_SHOW_BYTES = 0x01
};

template <class M>
std::string format_invalid_instruction(const edisassm::Instruction<M> &inst) {
	char byte_buffer[32];
	const uint8_t *const buf = inst.bytes();

	switch(inst.size()) {
	case 1:
		snprintf(byte_buffer, sizeof(byte_buffer), "db 0x%02x", buf[0] & 0xff);
		break;
	case 2:
		snprintf(byte_buffer, sizeof(byte_buffer), "dw 0x%02x%02x", buf[1] & 0xff, buf[0] & 0xff);
		break;
	case 4:
		snprintf(byte_buffer, sizeof(byte_buffer), "dd 0x%02x%02x%02x%02x", buf[3] & 0xff, buf[2] & 0xff, buf[1] & 0xff, buf[0] & 0xff);
		break;
	case 8:
		snprintf(byte_buffer, sizeof(byte_buffer), "dq 0x%02x%02x%02x%02x%02x%02x%02x%02x", buf[7] & 0xff, buf[6] & 0xff, buf[5] & 0xff, buf[4] & 0xff, buf[3] & 0xff, buf[2] & 0xff, buf[1] & 0xff, buf[0] & 0xff);
		break;
	default:
		// we tried...didn't we?
		return "invalid";
	}
	return byte_buffer;
}

//------------------------------------------------------------------------------
// Name: disassemble
//------------------------------------------------------------------------------
template <class M, class In>
void disassemble(In first, In last, typename edisassm::Instruction<M>::address_type rva, unsigned int flags) {

	typedef edisassm::Instruction<M> insn_t;
	
	while(first != last) {
	
		insn_t instruction(first, last, rva, std::nothrow);
		if(instruction) {
			std::cout << std::hex << rva << ": ";
			if(flags & FLAG_SHOW_BYTES) {
				std::cout << to_byte_string(instruction) << " ";
			}
			std::cout << to_string(instruction) << '\n';
			first += instruction.size();
			rva   += instruction.size();
		} else {
			std::cout << std::hex << rva << ": ";
			if(flags & FLAG_SHOW_BYTES) {
				std::cout << to_byte_string(instruction) << " ";
			}
			std::cout << format_invalid_instruction(instruction) << " (bad)\n";
			first += instruction.size();
			rva   += instruction.size();
		}
	}
}

//------------------------------------------------------------------------------
// Name: print_usage
//------------------------------------------------------------------------------
void print_usage(const char *arg0) {
	std::cerr << arg0 << " [-m32|-m64] [-x] [--rva <address>] [--show-bytes] [<filename> | -]" << std::endl;
	exit(-1);
}

//------------------------------------------------------------------------------
// Name: get_input
//------------------------------------------------------------------------------
std::vector<uint8_t> get_input(const std::string &filename, bool hex_chars) {

	std::vector<uint8_t> r;
	
	std::ifstream file;
	std::istream *s = 0;

	if(filename == "-") {
		s = &std::cin;
	} else {
		file.open(filename.c_str(), std::ios::binary);
		if(file) {
			s = &file;
		} else {
			std::cerr << "could not open the file: " << filename << std::endl;
		}
	}
	
	if(s) {
		std::istream &stream = *s;
		
		if(hex_chars) {
			uint32_t x;
			while(stream >> std::hex >> x) {
				r.push_back(x);
			}
		} else {
			r.assign(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
		}
	}
	
	return r;
}

}

//------------------------------------------------------------------------------
// Name: main
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {

	if(argc == 1) {
		print_usage(argv[0]);
	}

	unsigned int flags    = FLAG_NONE;
	bool x86_64_mode      = false;
	bool hex_chars        = false;
	uint64_t rva_address  = 0;
	std::string filename;

	for(int i = 1; i < argc; ++i) {
		if(argv[i][0] == '-') {
			if(strcmp(argv[i], "-m32") == 0) {
				x86_64_mode = false;
			} else if(strcmp(argv[i], "-m64") == 0) {
				x86_64_mode = true;
			} else if(strcmp(argv[i], "-x") == 0) {
				hex_chars = true;
			} else if(strcmp(argv[i], "--rva") == 0) {
				++i;
				if(argv[i] == 0) {
					print_usage(argv[0]);
				}
				rva_address = strtoul(argv[i], 0, 0);
			} else if(strcmp(argv[i], "--show-bytes") == 0) {
				flags |= FLAG_SHOW_BYTES;
			} else if(strcmp(argv[i], "-") == 0) {
				filename = argv[i];
				break;
			} else {
				print_usage(argv[0]);
			}
		} else {
			filename = argv[i];
			break;
		}
	}
	
	if(filename.empty()) {
		print_usage(argv[0]);
	}

	const std::vector<uint8_t> data = get_input(filename, hex_chars);
	const uint8_t *const first = &data[0];
	const uint8_t *const last  = first + data.size();

	if(x86_64_mode) {
		disassemble<edisassm::x86_64>(first, last, rva_address, flags);
	} else {
		disassemble<edisassm::x86>(first, last, rva_address, flags);
	}
}
