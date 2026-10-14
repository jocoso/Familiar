#include "ui/TerminalInterface.h"

#include <iostream>
#include <limits>
#include <stdexcept>

#include "ErrorHandler.h"

namespace Familiar {

    void TerminalInterface::showTitle() const
    {
        std::cout << "================================\n";
        std::cout << "           FAMILIAR\n";
        std::cout << "================================\n\n";
        std::cout << "Welcome to Familiar.\n\n";
    }

    void TerminalInterface::showMenu() const
    {
        std::cout << "1. Create a Project\n";
        std::cout << "2. Select a project\n";
        std::cout << "3. List Projects\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Select an option: ";
    }

    bool isValidMenuChoice(int choice)
    {
        return choice >= 1 && choice <= 4;
    }

    void TerminalInterface::killSwitch()
    {
        isRunning = false;
    }

    int TerminalInterface::readMenuChoice()
    {
        while (true) {
            showMenu();

            int choice = readNumber();

            if (choice == -1) continue;

            if (isValidMenuChoice(choice)) 
            {
                return choice;
            }

            std::cout
                << "Invalid choice. Please select a number from 1 to 4.\n\n";
        }
    }

    int TerminalInterface::readNumber()
    {
        int output;

        if (std::cin >> output) {
            return output;
        }

        if (std::cin.eof()) {
            throw std::runtime_error(
                "EOF: TerminalInterface::readNumber CIN_EOF_ERROR"
            );
        }

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );

        Familiar::reportError("Invalid input. Please enter a number.");
        return -1;
    }

    void TerminalInterface::readWord(std::string& output)
    {
        if (!std::getline(std::cin >> std::ws, output)) {
            if (std::cin.eof()) {
                throw std::runtime_error(
                    "EOF: TerminalInterface::readWord CIN_EOF_ERROR"
                );
            }

            output.clear();
        }
    }

    bool TerminalInterface::createProject()
    {
        std::string pName;
        std::string pDesc;

        std::cout << "What is the name of your project?\n";
        readWord(pName);

        std::cout
            << "Write a one-sentence description of the project.\n";
        readWord(pDesc);

        if (pName.empty() || pDesc.empty()) {
            return false;
        }

        Familiar::Project p{
            0,
            pName,
            pDesc,
            Familiar::ProjectStatus::Active
        };

        pm.createProject(p);

        return true;
    }

     std::vector<Project> TerminalInterface::printProjectList() 
     {
        std::cout << "=== PROJECTS ===\n";

        std::vector<Project> projects = pm.listProjects();

        if (projects.empty()) {
            std::cout << "No projects found.\n";
        } else {
            int index = 1;

            for (const Project& p : projects) {
                std::cout << index++ << ". " << p.getName() << '\n';
                std::cout << "   Description: "
                        << p.getDescription() << '\n';
            }
        }

        std::cout << '\n';

        return projects;
    }

    bool TerminalInterface::handleChoice(int choice)
    {
        switch (choice) {
            case 1: // Create projects
                if (createProject()) {
                    std::cout
                        << "Project created successfully!\n";
                } else {
                    std::cout
                        << "Project name and description "
                        << "cannot be empty.\n";
                }
                std::cout << std::endl;
                break;

            case 2: 
            {// Select projects
                std::vector<Project> projects = printProjectList();
                
                if (projects.empty()) break;

                std::cout << "What project do you want to select?\n";

                int selection = readNumber();

                if (selection <1 || static_cast<std::size_t> (selection) > projects.size()) 
                {
                    std::cout << "Invalid project selection.\n\n";
                    break;
                }
                
                selectedProject = projects[selection - 1];

                std::cout << "Selected Project: \n" << selectedProject->getName() << "\n\n";
                
            
                break;
            }

            case 3: // List Projects
                printProjectList();
                break;

            case 4: // Exit
                killSwitch();
                std::cout << "Goodbye!\n";
                std::cout << std::endl;
                break;

            default:
                std::cout << "Invalid choice.\n";
                return false;
        }

        return true;
    }

    void TerminalInterface::run()
    {
        showTitle();

        while (isRunning) {
            try {
                int choice = readMenuChoice();
                handleChoice(choice);
            } catch (const std::runtime_error& e) {
                std::cerr << '\n' << e.what() << '\n';
                killSwitch();
            }
        }
    }

} // namespace Familiar