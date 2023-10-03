#include "Parser.hpp"
#include <sstream>

Parser::Parser() {}

std::vector<std::string> Parser::ParseCommand(const std::string& command) {
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}
