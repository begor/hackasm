#include <iostream>
#include "src/Assembler.h"

using namespace std;


int main () {
    HackAsm::Assembler p = HackAsm::Assembler("hello.asm");
    
    p.assebmly();
    
    return 0;
}