#ifndef BF_INTERPRETER_DETAILS_H
#define BF_INTERPRETER_DETAILS_H

#include <cstddef>
#include <stack>
#include <vector>

namespace bf_interpreter::details {
    struct Loop {
        std::size_t instruction_position;
    };
    using LoopStack = std::stack<Loop, std::vector<Loop>>;
    using InstructionSequence = std::vector<char>;
}// namespace bf_interpreter::details

#endif// BF_INTERPRETER_DETAILS_H
