#include <iostream>
#include "Instruction.h"

using namespace std;
using namespace HackAsm;

Instruction::Instruction(string& assembly_str) : assembly_str(assembly_str) {};


string AInstruction::to_binary() {
    string binary;
    string addr_str = assembly_str.substr(1, assembly_str.size() - 1); // TODO: error handling
    
    int addr_dec;
    
    try {
        addr_dec = stoi(addr_str);
    } catch (const invalid_argument& e) {
        addr_dec = _table->put(addr_str);
        cout << "Generate addr " << addr_dec << endl;
    }
    
    binary = "0" + bitset<15>(addr_dec).to_string();
    return binary;
};

void CInstruction::parse() {
    auto eq_pos = assembly_str.find('='); // TODO: error handling
    dest = assembly_str.substr(0, eq_pos);
    
    string comp_n_jmp = assembly_str.substr(eq_pos + 1, assembly_str.size() - 1);

    auto delim_pos = comp_n_jmp.find(';');

    if (delim_pos != -1) {
        comp = comp_n_jmp.substr(0, delim_pos);
        jmp = comp_n_jmp.substr(delim_pos + 1, comp_n_jmp.size() - 1);
    } else {
        comp = comp_n_jmp;
        jmp = "";
    }

    if (comp.find('M') == string::npos) {
        a = "0";
    } else {
        a = "1";
    }
};

string CInstruction::to_binary() {
    parse();
    
    cout << "Instruction: " << assembly_str << endl;
    cout << "Dest: " << dest << endl;
    cout << "Comp: " << comp << endl;
    cout << "Jmp: " << jmp << endl;
    cout << "A: " << a << endl;

    return comp;
};