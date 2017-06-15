#include "SymbolTable.h"

using namespace HackAsm;

int SymbolTable::get(string key) {
    return _table[key];
};

void SymbolTable::put(string key) {
    _table[key] = emptyMemReg++;
};

void SymbolTable::put(string key, int value) {
    _table[key] = value;
};

bool SymbolTable::contains(string key) {
    return _table.count(key) > 0;
}