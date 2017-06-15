#include <iostream>
#include "src/Assembler.h"

using namespace std;
using namespace HackAsm;


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage..." << endl;
        return 1;
    }

    auto file_name = argv[1];
    Assembler(file_name).assembly();
    
    return 0;
}