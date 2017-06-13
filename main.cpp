#include <iostream>
#include "src/Assembler.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage..." << endl;
        return 1;
    }

    auto file_name = argv[1];
    
    cout << "File name: " << file_name << endl;
    
    HackAsm::Assembler p = HackAsm::Assembler(file_name);
    p.assembly();
    
    return 0;
}