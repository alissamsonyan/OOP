#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class Parser {
public:
    std::vector<std::string> ParseCommand(const std::string& command);
};

#endif // PARSER_HPP
