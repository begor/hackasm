#include <iostream>
#include <algorithm>
#include <string>
#include "Assembler.h"
#include "Instruction.h"

using namespace std;
using namespace HackAsm;


Assembler::Assembler(string file_name, SymbolTable* table) : _input_file_name(file_name), _table(table) {  
    get_output_file_name();  
    read_file();
};

void Assembler::get_output_file_name() {
    auto dot_pos = _input_file_name.find('.');
    _output_file_name = _input_file_name.substr(0, dot_pos) + ".hack";
}

void Assembler::read_file() {
    string line;
    ifstream file(_input_file_name);
    
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

void Assembler::assembly() {
    ofstream file;
    file.open(_output_file_name);

    for (string& instruction : _asm_program) {
        file << parse_instruction(instruction) << endl;
    }

    file.close();
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
        auto inst = AInstruction(instruction, _table);
        return inst.to_binary();
    } else {
        auto inst = CInstruction(instruction);
        return inst.to_binary();
    }
}