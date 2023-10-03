#include <iostream>
#include "CommandHandler.hpp"

int main() {
    CommandHandler handler;
    std::string command;
    std::cout << "Enter commands (add, remove, display, change, list, exit):" << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        handler.ExecuteCommand(command);
    }

    return 0;
}
