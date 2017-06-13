#pragma once
#include <string>
#include <bitset>

using namespace std;

namespace HackAsm {   
    // Abstract base class for A-, C- and L-instructions
    class Instruction {
        public:
            Instruction(string& ins);
            virtual string to_binary() = 0;

        protected:
            string assembly_str;
    };

    // A-instruction (@21)
    class AInstruction : public Instruction {
        public:
            using Instruction::Instruction;
            string to_binary() override;
    };

    // C-instruction (D=D+1;JEQ)
    class CInstruction : public Instruction {
        public:
            using Instruction::Instruction;
            string to_binary() override;

        private:
            string a;
            string dest;
            string comp;
            string jmp;

            void parse();
            string dest_to_binary(string& dest);
            string comp_to_binary(string& comp);
            string jmp_to_binary(string& jmp);
    };
};