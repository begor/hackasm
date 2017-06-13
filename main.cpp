#include <iostream>
#include <fstream>
#include <vector>
#include "instruction.h"

using namespace std;

vector<string> read(string file) {
    vector<string> lines;
    string line;
    ifstream myfile(file);
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            lines.push_back(line);
        }
        myfile.close();
    } else {
        cout << "Unable to open file"; 
    }

    return lines;
}

string translate_a_instruction(string& instruction) {
    string addr_str = instruction.substr(1, instruction.size() - 1);
    int addr_dec = stoi(addr_str);
    cout << addr_dec << endl;
    string binary = "0" + bitset<15>(addr_dec).to_string();
    cout << binary << endl;
    return binary;
}

string translate(string assembly) {
    char& first = assembly.front();

    if (first == '@') {
        auto inst = HackAsm::AInstruction(assembly);
        return inst.to_binary();
    } else {
        auto inst = HackAsm::CInstruction(assembly);
        return inst.to_binary();
    }
}


int main () {
  vector<string> lines = read("hello.txt");
  
  for (string& s : lines) {
      translate(s);
  }
  
  return 0;
}