#include <iostream>
#include "Instruction.h"

using namespace std;
using namespace HackAsm;

Instruction::Instruction(string& inst) : _inst(inst) {};

string Instruction::to_binary() { cout << "HERE" << endl; return ""; };


AInstruction::AInstruction(string& inst, shared_ptr<SymbolTable> st) : Instruction(inst), _table(st) {};


string AInstruction::to_binary() {
    string binary;
    string addr_str = _inst.substr(1, _inst.size() - 1); // TODO: error handling
    
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
    auto eq_pos = _inst.find('='); // TODO: error handling
    dest = _inst.substr(0, eq_pos);
    
    string comp_n_jmp = _inst.substr(eq_pos + 1, _inst.size() - 1);

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
    return "111" + a + comp_to_binary() + dest_to_binary() + jmp_to_binary();
};

string CInstruction::dest_to_binary() {
    return dest_translations[dest];
};

string CInstruction::comp_to_binary() {
    return comp_translations[comp];
};

string CInstruction::jmp_to_binary() {
    return jmp_translations[jmp];
};