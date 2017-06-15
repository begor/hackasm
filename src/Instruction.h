#pragma once
#include <string>
#include <bitset>
#include <map>
#include "SymbolTable.h"

using namespace std;

namespace HackAsm {   
    // Abstract base class for A-, C- and L-instructions
    class Instruction {
        public:
            Instruction(string& inst);
            virtual string to_binary();

        protected:
            string _inst;
    };

    // A-instruction (@21)
    class AInstruction : public Instruction {
        public:
            AInstruction(string& inst, shared_ptr<SymbolTable> st);
            string to_binary() override;
        protected:
            shared_ptr<SymbolTable> _table;
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
            
            map<string, string> dest_translations {
                {"", "000"},
                {"M", "001"},
                {"D", "010"},
                {"MD", "011"},
                {"A", "100"},
                {"AM", "101"},
                {"AD", "110"},
                {"AMD", "111"}
            };

            map<string, string> jmp_translations {
                {"", "000"},
                {"JGT", "001"},
                {"JEQ", "010"},
                {"JGE", "011"},
                {"JLT", "100"},
                {"JNE", "101"},
                {"JLE", "110"},
                {"JMP", "111"}
            };

            map<string, string> comp_translations {
                {"0", "101010"},
                {"1", "111111"},
                {"-1", "111010"},
                {"D", "001100"},
                {"A", "110000"},
                {"M", "110000"},
                {"!D", "001101"},
                {"!A", "110001"},
                {"!M", "110001"},
                {"-D", "001111"},
                {"-A", "110011"},
                {"-M", "110011"},
                {"D+1", "011111"},
                {"A+1", "110111"},
                {"M+1", "110111"},
                {"D-1", "001110"},
                {"A-1", "110010"},
                {"M-1", "110010"},
                {"D+A", "000010"},
                {"D+M", "000010"},
                {"D-A", "010011"},
                {"D-M", "010011"},
                {"A-D", "000111"},
                {"M-D", "000111"},
                {"D&A", "000000"},
                {"D&M", "000000"},
                {"D|A", "010101"},
                {"D|M", "010101"}
            };

            void parse();
            string dest_to_binary();
            string comp_to_binary();
            string jmp_to_binary();
    };
};