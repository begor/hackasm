#include "SymbolTable.h"

using namespace HackAsm;

int SymbolTable::get(string key) {
    return _table[key];
};

// TODO: check exists

int SymbolTable::put(string key) {
    _table[key] = emptyMemReg;
    return emptyMemReg++;
};

int SymbolTable::put(string key, int value) {
    _table[key] = value;
    return value;
};

bool SymbolTable::contains(string key) {
    return _table.count(key) > 0;
}