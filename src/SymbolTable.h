#pragma once
#include <map>
#include <string>
#include <memory>

using namespace std;


namespace HackAsm {
    class SymbolTable {
        public:
            int get(string key);
            bool contains(string key);
            int put(string key, int value);
            int put(string key);
        
        private:
            int emptyMemReg = 16;
            map<string, int> _table {
                {"R1", 1},
                {"R2", 2},
                {"R3", 3},
                {"R4", 4},
                {"R5", 5},
                {"R6", 6},
                {"R7", 7},
                {"R8", 8},
                {"R9", 9},
                {"R10", 10},
                {"R11", 11},
                {"R12", 12},
                {"R13", 13},
                {"R14", 14},
                {"R15", 15},
                {"KBD", 24576},
                {"SCREEN", 16384}, 
                {"SP", 0},
                {"LCL", 1},
                {"ARG", 2},
                {"THIS", 3},
                {"THAT", 4}
            };
    };
}