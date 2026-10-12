#include "ui/TerminalInterface.h"
#include <iostream>
#include <string>
#include <limits>

namespace Familiar {
    void TerminalInterface::showTitle() const {
        std::cout << "================================\n";
        std::cout << "           FAMILIAR\n";
        std::cout << "================================\n\n";
        std::cout << "Welcome to Familiar.\n\n";
    }

    void TerminalInterface::showMenu() const {
        std::cout << "1. Projects\n";
        std::cout << "2. Tasks\n";
        std::cout << "3. Exit\n\n";
        std::cout << "Select an option: \n";
    }

    bool isValidMenuChoice(int choice) {
        return choice >= 1 && choice <= 3;
    }

    int TerminalInterface::readMenuChoice() {
        int choice;

        while(true) {

            if(std::cin >> choice && isValidMenuChoice(choice)) {
                return choice;
            }
            
            if(std::cin.eof()) {
                return 3; // Exit on EOF
            }
            
            std::cout << "Invalid input. Please select 1, 2, or 3.\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
                
            showMenu();
                
        }
    }

    void TerminalInterface::killSwitch() 
    {
        isRunning = false;
    }

    bool TerminalInterface::handleChoice(int choice) 
    {
        switch (choice) {
            case 1:
                // Opt 1
                break;
            case 2:
                // Opt 2
                break;
            case 3:
                // Exit
                killSwitch();
                break;
            default:
                std::cout << "Invalid choice\n";
                return false;
        }
        return true;
    }

    void TerminalInterface::run() 
    {
        showTitle();
        while(isRunning) 
        {
            showMenu();
            int choice = readMenuChoice();
            handleChoice(choice);
        }


    }
} // Closes readMenuChoice