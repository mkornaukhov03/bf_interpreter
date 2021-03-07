#ifndef BF_INTERPRETER_INTERPRETER_H
#define BF_INTERPRETER_INTERPRETER_H

#include "details.h"
#include <istream>
#include <ostream>

namespace bf_interpreter
{
struct Interpreter
{
    Interpreter(std::istream &stdin, std::ostream &stdout, std::ostream &stderr);
    Interpreter(Interpreter &&) = default;
    Interpreter(const Interpreter &) = default;
    ~Interpreter() = default;

    void interpret();
    void upload_source(const std::string &);

  private:
    constexpr static std::size_t MAX_SIZE = 30000;
    int memory_[MAX_SIZE]{};
    details::LoopStack stack_{};
    details::InstructionSequence instructs_{};
    std::istream &stdin_;
    std::ostream &stdout_;
    std::ostream &stderr_;
};
} // namespace bf_interpreter

#endif // BF_INTERPRETER_INTERPRETER_H
