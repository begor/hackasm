#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "SymbolTable.h"
#include "Parser.h"

using namespace std;

namespace HackAsm {
    class Assembler {
        public:
            Assembler(string file_name);
            void assembly();
            
        private:
            Parser parser;
            
            string _input;
            string _output;
            
            program read_file();
            void set_output_filename();
            void write_file(program& out);
    };
};