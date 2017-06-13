#pragma once

#include <string>
#include <fstream>
#include <vector>

using namespace std;

namespace HackAsm {
    using program = vector<string>;

    class Assembler {
        public:
            Assembler(string file_name);
            program assebmly();
            

        private:
            program _asm_program;
            program _machine_program;

            void read_file(string& file_name);
            string parse_instruction(string& instruction);
    };
};