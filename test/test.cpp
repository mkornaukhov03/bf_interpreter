#include <cassert>
#include <iostream>
#include <sstream>

#include "interpreter.h"

int main()
{
    using namespace bf_interpreter;
    {
        // Hello world

        std::string s("+++++++++++++++++++++++++++++++++++++++++++++\n"
                      " +++++++++++++++++++++++++++.+++++++++++++++++\n"
                      " ++++++++++++.+++++++..+++.-------------------\n"
                      " ---------------------------------------------\n"
                      " ---------------.+++++++++++++++++++++++++++++\n"
                      " ++++++++++++++++++++++++++.++++++++++++++++++\n"
                      " ++++++.+++.------.--------.------------------\n"
                      " ---------------------------------------------\n"
                      " ----.-----------------------.");
        Interpreter interpreter(std::cin, std::cout, std::cerr);
        interpreter.upload_source(s);
        interpreter.interpret();
    }
    {
        // sierpinski triangle
        std::string s("++++++++[>+>++++<<-]>++>>+<[-[>>+<<-]+>>]>+[\n"
                      "    -<<<[\n"
                      "        ->[+[-]+>++>>>-<<]<[<]>>++++++[<<+++++>>-]+<<++.[-]<<\n"
                      "    ]>.>+[>>]>+\n"
                      "]");
        Interpreter interpreter(std::cin, std::cout, std::cerr);
        interpreter.upload_source(s);
        interpreter.interpret();
    }
//    {
//        // squares from 0 to 10000
//        std::string s("++++[>+++++<-]>[<+++++>-]+<+[\n"
//                      "        >[>+>+<<-]++>>[<<+>>-]>>>[-]++>[-]+\n"
//                      "        >>>+[[-]++++++>>>]<<<[[<++++++++<++>>-]+<.<[>----<-]<]\n"
//                      "        <<[>>>>>[>>>[-]+++++++++<[>-<-]+++++++++>[-[<->-]+[<<<]]<[>+<-]>]<<-]<<-\n"
//                      "        ]");
//        Interpreter interpreter(std::cin, std::cout, std::cerr);
//        interpreter.upload_source(s);
//        interpreter.interpret();

//    }
//    {
//        // unknown command
//        std::string s("what?");
//        Interpreter interpreter(std::cin, std::cout, std::cerr);
//        interpreter.upload_source(s);
//        interpreter.interpret();
//    }
//    {
//        // incorrect bracket sequence
//        std::string s("what?");
//        Interpreter interpreter(std::cin, std::cout, std::cerr);
//        interpreter.upload_source(s);
//        interpreter.interpret();
//    }
}