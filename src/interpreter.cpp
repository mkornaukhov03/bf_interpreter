#include "interpreter.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <iostream> // tmp

namespace bf_interpreter
{
Interpreter::Interpreter(std::istream &stdin, std::ostream &stdout, std::ostream &stderr)
    : stdin_(stdin), stdout_(stdout), stderr_(stderr)
{
}
void Interpreter::upload_source(const std::string &src)
{
    static std::array commands = {'<', '>', ',', '.', '+', '-', '[', ']'};
    int balance = 0;

    for (auto cmd : src)
    {
        if (cmd == '[')
        {
            balance++;
        }
        else if (cmd == ']')
        {
            balance--;
        }
        if (balance < 0)
        {
            stderr_ << "Incorrect bracket sequences!\n";
            instructs_.clear();
            return;
        }

        if (isspace(cmd))
            continue;
        else if (std::none_of(std::begin(commands), std::end(commands),
                              [&cmd = cmd](const char ch) { return ch == cmd; }))
        {
            stderr_ << "Unknown command!\n";
            instructs_.clear();
            return;
        }
        else
        {
            instructs_.push_back(cmd);
        }
    }
    if (balance != 0)
    {
        stderr_ << "Incorrect bracket sequences!\n";
        instructs_.clear();
        return;
    }
}
void Interpreter::interpret()
{
    std::size_t tape_ind = 0;
    std::size_t inst_ind = 0;

    // std::cin, cout - just for view, fix later

    for (; inst_ind < std::size(instructs_); ++inst_ind)
    {
        auto cur_inst = instructs_[inst_ind];
        switch (cur_inst)
        {
        case '>':
            ++tape_ind;
            break;
        case '<':
            --tape_ind;
            break;
        case '+':
            ++memory_[tape_ind];
            break;
        case '-':
            --memory_[tape_ind];
            break;
        case '.':
            stdout_ << static_cast<char>(memory_[tape_ind]);
            break;
        case ',':
            int tmp;
            stdin_ >> tmp;
            memory_[tape_ind] = tmp;
            break;
        case '[':
            if (memory_[tape_ind] == 0)
            { // skip to after-[
                int l = 1;
                for (inst_ind++; l != 0; ++inst_ind)
                {
                    if (instructs_[inst_ind] == ']') l--;
                    if (instructs_[inst_ind] == '[') l++;
                }
                --inst_ind;
            }
            else
            {
                stack_.push({inst_ind});
            }
            break;
        case ']':
            if (memory_[tape_ind] == 0)
            {
                stack_.pop();
            }
            else
            {
                inst_ind = stack_.top().instruction_position;
                assert(!stack_.empty());
            }
            break;
        default:
            stderr_ << "Unknown command! Terminate!\n";
            return;
        }
    }
}
} // namespace bf_interpreter