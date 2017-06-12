#include <iostream>
#include "instruction.h"

using namespace std;
using namespace HackAsm;

Instruction::Instruction(string& assembly) : assembly(assembly) {};


string AInstruction::to_binary() {
    string addr_str = assembly.substr(1, assembly.size() - 1);
    int addr_dec = stoi(addr_str);
    string binary = "0" + bitset<15>(addr_dec).to_string();
    return binary;
};