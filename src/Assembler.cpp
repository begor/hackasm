#include <iostream>
#include <algorithm>
#include <string>
#include "Assembler.h"
#include "Instruction.h"

using namespace std;
using namespace HackAsm;


Assembler::Assembler(string file_name) {
    read_file(file_name);
};

void Assembler::read_file(string& file_name) {
    string line;
    ifstream file(file_name);
    
    if (file.is_open()) {
        while (getline(file, line)) {
            string instruction = remove_comment(line);

            cout << "Read: " << instruction << endl;
            
            if (instruction.size()) {
                _asm_program.push_back(instruction);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl; // TODO: raise?
    }
}

program Assembler::assebmly() {
    for (string& instruction : _asm_program) {
        cout << parse_instruction(instruction) << endl;
    }

    return _asm_program;
}

string Assembler::remove_comment(string& instruction) {
    auto comment_start = instruction.find("//");
    
    if (comment_start != string::npos) {
        return instruction.substr(0, comment_start);
    }
    
    return instruction;
}

string Assembler::parse_instruction(string& instruction) {
    char& first = instruction.front();

    if (first == '@') {
        auto inst = AInstruction(instruction);
        return inst.to_binary();
    } else {
        auto inst = CInstruction(instruction);
        return inst.to_binary();
    }
}