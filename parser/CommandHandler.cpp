#include "CommandHandler.hpp"

CommandHandler::CommandHandler() : nextShapeID(1) {
}

void CommandHandler::ExecuteCommand(const std::string& command) {
    std::vector<std::string> tokens = parser.ParseCommand(command);

    if (tokens.empty()) {
        std::cout << "Invalid command. Please enter a valid command." << std::endl;
        return;
    }

    std::string cmd = tokens[0];

    if (cmd == "add") {
        AddShape(tokens);
    } else if (cmd == "remove") {
        RemoveShape(tokens);
    } else if (cmd == "display") {
        DisplayShape(tokens);
    } else if (cmd == "change") {
        ChangeShape(tokens);
    } else if (cmd == "list") {
        ListShapes();
    } else if (cmd == "exit") {
        std::cout << "Exiting program." << std::endl;
    } else {
        std::cout << "Invalid command. Please enter a valid command." << std::endl;
    }
}

void CommandHandler::AddShape(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4 || tokens[1] != "-name") {
        std::cout << "Invalid add command format. Use 'add -name ShapeName -id ShapeID'." << std::endl;
        return;
    }

    const std::string shapeName = tokens[2];
    const int shapeID = std::stoi(tokens[3]);

    std::cout << "Added shape: " << shapeName << " with ID " << shapeID << "." << std::endl;
}


void CommandHandler::RemoveShape(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2 || tokens[1] != "-id") {
        std::cout << "Invalid remove command format. Use 'remove -id ShapeID'." << std::endl;
        return;
    }

    const int shapeID = std::stoi(tokens[2]);
    auto it = shapeMap.find(shapeID);

    if (it != shapeMap.end()) {
        std::string shapeName = it->second.GetName();
        shapeMap.erase(it);
        std::cout << shapeName << " with ID " << shapeID << " removed." << std::endl;
    } else {
        std::cout << "Shape with ID " << shapeID << " not found." << std::endl;
    }
}

void CommandHandler::DisplayShape(const std::vector<std::string>& tokens) {
    if (tokens.size() != 2 || tokens[1] != "-id") {
        std::cout << "Invalid display command format. Use 'display -id ShapeID'." << std::endl;
        return;
    }

    const int shapeID = std::stoi(tokens[2]);
    auto it = shapeMap.find(shapeID);

    if (it != shapeMap.end()) {
        std::string shapeName = it->second.GetName();
        std::cout << "Shape name: " << shapeName << std::endl;
    } else {
        std::cout << "Shape with ID " << shapeID << " not found." << std::endl;
    }
}

void CommandHandler::ChangeShape(const std::vector<std::string>& tokens) {
    if (tokens.size() != 4 || tokens[1] != "-id" || tokens[2] != "-op1") {
        std::cout << "Invalid change command format. Use 'change -id ShapeID -op1 NewShapeID'." << std::endl;
        return;
    }

    const int shapeID = std::stoi(tokens[3]);
    const int newShapeID = std::stoi(tokens[4]);

    auto it = shapeMap.find(shapeID);

    if (it != shapeMap.end()) {
        std::string shapeName = it->second.GetName();
        shapeMap.erase(it);
        Shape newShape(newShapeID, shapeName);
        shapeMap.insert({newShapeID, newShape});
        std::cout << shapeName << " with ID " << shapeID << " changed to " << newShapeID << "." << std::endl;
    } else {
        std::cout << "Shape with ID " << shapeID << " not found." << std::endl;
    }
}

void CommandHandler::ListShapes() {
    std::cout << "List of shapes:" << std::endl;
    for (const auto& entry : shapeMap) {
        std::cout << "ID: " << entry.first << ", Name: " << entry.second.GetName() << std::endl;
    }
}
