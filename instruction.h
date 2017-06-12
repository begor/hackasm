#pragma once
#include <string>
#include <bitset>

using namespace std;

namespace HackAsm {
    enum InstructionType { A, C, L };
    
    // Abstract base class for A-, C- and L-instructions
    class Instruction {
        public:
            Instruction(string& ins);
            virtual string to_binary() = 0;

        protected:
            string assembly;
            InstructionType type;
    };

    // A-instruction (@21)
    class AInstruction : public Instruction {
        public:
            using Instruction::Instruction;
            string to_binary() override;
    };
};