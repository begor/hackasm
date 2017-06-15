#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "SymbolTable.h"

using namespace std;

namespace HackAsm {
    using program = vector<string>;

    class Assembler {
        public:
            Assembler(string file_name, SymbolTable* table);
            // TODO: decompose
            void assembly();
            

        private:
            SymbolTable* _table;  // TODO: shared_ptr
            string _input_file_name;
            string _output_file_name;
            program _asm_program;
            program _machine_program;

            void read_file();
            void write_file();
            void get_output_file_name();
            string parse_instruction(string& instruction);
            string remove_comment(string& instruction);
    };
};