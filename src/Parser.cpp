#include "Parser.h"
#include <algorithm>
#include <memory>

using namespace std;
using namespace HackAsm;

program Parser::parse(program& in) {
    program machine_program;
    program only_instructions = labels_and_comments(in);
    
    for (string& inst : only_instructions) {
        auto i = parse_instruction(inst);
        machine_program.push_back(i->to_binary());
    }

    return machine_program;
};

program Parser::labels_and_comments(program& in) {
    program without_labels;
    
    int line_no = 1;
    for (string& inst : in) {
        string stripped = strip_instruction(inst);

        if (stripped.empty())
            continue;
        
        char& first = stripped.front();
        
        if (first == '(') {
            string l = get_label(stripped);
            _table->put(l, line_no);
        } else if (stripped.size() > 0) {
            ++line_no;
            without_labels.push_back(stripped);
        }
    }

    return without_labels;
};


unique_ptr<Instruction> Parser::parse_instruction(string& inst) {
    char& first = inst.front();

    if (first == '@')
        return std::make_unique<AInstruction>(inst, _table);
    
    return std::make_unique<CInstruction>(inst);
};

string Parser::strip_instruction(string& inst) {
    inst.erase(0, inst.find_first_not_of(' '));
    inst.erase(inst.find_last_not_of(' ') + 1);
    
    if (!inst.empty()) {
        auto comment_start = inst.find("//");
        
        if (comment_start != string::npos) {
            return inst.substr(0, comment_start);
        }
    }

    return inst;
};

string Parser::get_label(string& inst) {
    return inst.substr(1, inst.size() - 2);
};
