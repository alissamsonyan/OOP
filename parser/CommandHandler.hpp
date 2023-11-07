#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "Shape.hpp"
#include "Parser.hpp"
#include <map>
#include <functional>

class CommandHandler {
public:
    CommandHandler();

    void ExecuteCommand(const std::string& command);

private:
    int nextShapeID;
    std::map<int, Shape> shapeMap;
    Parser parser;

    void AddShape(const std::vector<std::string>& tokens);
    void RemoveShape(const std::vector<std::string>& tokens);
    void DisplayShape(const std::vector<std::string>& tokens);
    void ChangeShape(const std::vector<std::string>& tokens);
    void ListShapes();
};

#endif
