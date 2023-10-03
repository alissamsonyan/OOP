#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Shapes.hpp"
#include "Parser.hpp"

class CommandHandler {
public:
    CommandHandler();
    void ExecuteCommand(const std::string& command);

private:
    std::map<int, Shape> shapeMap;
    int nextShapeID;
    Parser parser;

    void AddShape(const std::vector<std::string>& tokens);
    void RemoveShape(const std::vector<std::string>& tokens);
    void DisplayShape(const std::vector<std::string>& tokens);
    void ChangeShape(const std::vector<std::string>& tokens);
    void ListShapes();
};

#endif // COMMAND_HANDLER_HPP
