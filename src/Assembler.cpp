#include <iostream>
#include <algorithm>
#include <string>
#include "Assembler.h"
#include "Instruction.h"

using namespace std;
using namespace HackAsm;


Assembler::Assembler(string filename) : _input(filename) {  set_output_filename(); };

void Assembler::set_output_filename() {
    auto dot_pos = _input.find('.');
    _output = _input.substr(0, dot_pos) + ".hack";
};

void Assembler::assembly() {
    program pr = read_file();
    program out = parser.parse(pr);
    write_file(out);
};

program Assembler::read_file() {
    program pr;
    string line;
    ifstream file(_input);
    
    if (file.is_open()) {
        while (getline(file, line)) {            
            pr.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return pr;
};

void Assembler::write_file(program& pr) {
    ofstream file;
    file.open(_output);

    for (string& instruction : pr) {
        file << instruction << endl;
    }

    file.close();
};