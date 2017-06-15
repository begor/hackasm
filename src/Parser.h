#pragma once
#include <memory>
#include <vector>
#include "Instruction.h"
#include "SymbolTable.h"

using namespace std;

namespace HackAsm {
    using program = vector<string>;
    
    class Parser {
        public:
            program parse(program& in);

        private:
            shared_ptr<SymbolTable> _table = make_shared<SymbolTable>();
            
            unique_ptr<Instruction> parse_instruction(string& inst);
            string get_label(string& inst);
            program labels_and_comments(program& program);
            string strip_instruction(string& inst);
    };
}