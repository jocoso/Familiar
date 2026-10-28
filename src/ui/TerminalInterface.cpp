#include "ui/TerminalInterface.h"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "ErrorHandler.h"


const int CREATE_PROJECT                = 1;
const int SELECT_PROJECT                = 2;
const int DISPLAY_LIST                  = 3;
const int PUSH_TASK_ON_SELECTED_PROJECT = 4;
const int EXIT                          = 5;

namespace Familiar {

    void TerminalInterface::showTitle() const {
        std::cout << "================================\n";
        std::cout << "           FAMILIAR\n";
        std::cout << "================================\n\n";
        std::cout << "Welcome to Familiar.\n\n";
    }

    void TerminalInterface::showMenu() const {
        std::cout << "1. Create a Project\n";
        std::cout << "2. Select a project\n";
        std::cout << "3. List Projects\n";
        std::cout << "4. Add Task to Project\n";
        std::cout << "5. Exit\n\n";
        std::cout << "Select an option: ";
    }

    bool isValidMenuChoice(int choice) {
        return choice >= 1 && choice <= MAX_NUMBER_OF_OPTIONS;
    }

    void TerminalInterface::killSwitch() {
        isRunning = false;
    }

    int TerminalInterface::readMenuChoice() {
        while (true) {
            showMenu();

            int choice = readNumber();

            if (choice == -1) {
                continue;
            }

            if (isValidMenuChoice(choice)) {
                return choice;
            }

            std::cout << "Invalid choice. Please select a number from 1 to .\n\n";
        }
    }

    int TerminalInterface::readNumber() 
    {
        std::string input;

        if (!std::getline(std::cin, input)) {
            if (std::cin.eof())
            {
                throw std::runtime_error("EOF: TerminalInterface::readNumber CIN_EOF_ERROR\n");
            }

            std::cin.clear();
            return -1;
        }

    try
    {
        std::size_t pos = 0;
        int number = std::stoi(input, &pos);

        // Reject inputs such as "1abc" or "2.5".
        if (pos != input.size())
        {
            Familiar::reportError(
                "Invalid input. Please enter a number."
            );
            return -1;
        }

        return number;
        }
        catch (const std::invalid_argument&)
        {
            Familiar::reportError(
                "Invalid input. Please enter a number."
            );
            return -1;
        }
        catch (const std::out_of_range&)
        {
            Familiar::reportError(
                "Number is out of range."
            );
            return -1;
        }
    }

    void TerminalInterface::readWord(std::string &output) {
        if (!std::getline(std::cin, output)) {
            if (std::cin.eof()) {
                throw std::runtime_error(
                    "EOF: TerminalInterface::readWord CIN_EOF_ERROR\n"
                );
            }

            std::cin.clear();
            output.clear();
        }
    }

    bool TerminalInterface::createProject() {
        std::string pName;
        std::string pDesc;

        std::cout << "What is the name of your project?\n";
        readWord(pName);

        std::cout << "Write a one-sentence description of the project.\n";
        readWord(pDesc);

        if (pName.empty() || pDesc.empty()) {
            return false;
        }

        Familiar::Project p{0, pName, pDesc, Familiar::ProjectStatus::Active};

        pm.createProject(p);

        return true;
    }

    void TerminalInterface::printSelectedProjectTask()
    {
        std::optional<Project> p = getSelectedProject();
        
        if(!p)
        {
            std::cout << "No project selected.\n";
            return;
        }

        printProject(*p);

        const std::vector<Task>& t_list =  p->getTasks();

        printTasks(t_list);
    }

    void TerminalInterface::printProject(const Project& p)
    {
        std::cout << p.getName() << "\n";
        std::cout << p.getDescription() << "\n";
        std::cout << "Status: " << p.getStatus() << "\n";
    }

    void TerminalInterface::printTasks(const std::vector<Task>& t) 
    {
        std::cout << "[ Tasks ]\n";

        if (t.empty())
        {
            std::cout << "No tasks available.\n";
            return;
        }

        for(std::size_t i = 0; i < t.size(); ++i)
        {
            std::cout << i + 1 << " - " << t[i].getTitle() << "\n";
            std::cout << t[i].getDescription() << "\n";
        }
    }

    bool TerminalInterface::createTask() 
    {
        if (!selectedProject)
        {
            std::cout << "No project selected.\n";
            return false;
        }

        std::string pName;
        std::string pDesc;

        std::cout << "Task Name?\n";
        readWord(pName);

        std::cout << "Write a description of your task.\n";
        readWord(pDesc);

        if (pName.empty() || pDesc.empty()) {
            std::cout << "Task name and description cannot be empty.\n";
            return false;
        }


        Task t{0, pName, pDesc};

        if(!pm.addTaskToProject(selectedProject->getId(), t))
        {
            std::cout << "Failed to add task to project.\n";
            return false;
        }

        selectedProject = *pm.findProject(selectedProject->getId());

        return true;
    }

    std::optional<Project> TerminalInterface::getSelectedProject() 
    {
        return selectedProject;
    }

    std::vector<Project> TerminalInterface::printProjectList() {
        std::cout << "=== PROJECTS ===\n";

        std::vector<Project> projects = pm.listProjects();

        if (projects.empty()) {
            std::cout << "No projects found.\n";
        } else {
            int index = 1;

            for (const Project &p : projects) {
                std::cout << index++ << ". " << p.getName() << '\n';
                std::cout << "   Description: " << p.getDescription() << '\n';

                const std::vector<Familiar::Task> t = p.getTasks();
                printTasks(t);
            }
        }

        std::cout << '\n';

        return projects;
    }


    // ================================ //


    bool TerminalInterface::SaveData()
    {
        std::ofstream datafile;
        datafile.open("datafile.txt");
        datafile << "[This is where I would put my data... If I had anyyyy.] \n";
        datafile.close();

        std::cout << "Data Saved! \n\n";

        return true;
    }

    bool TerminalInterface::handleChoice(int choice) {
        switch (choice) {
            case CREATE_PROJECT: // Create projects
                if (createProject()) {
                    std::cout << "Project created successfully!\n";
                    SaveData();
                } else {
                    std::cout << "Project name and description "
                            << "cannot be empty.\n";
                }
                std::cout << std::endl;
                break;

            case SELECT_PROJECT: { // Select projects
                std::vector<Project> projects = printProjectList();

                if (projects.empty())
                    break;

                std::cout << "What project do you want to select?\n";

                int selection = readNumber();

                if (selection < 1 ||
                    static_cast<std::size_t>(selection) > projects.size()) {
                    std::cout << "Invalid project selection.\n\n";
                    break;
                }

                selectedProject = projects[selection - 1];

                std::cout << "Selected Project: \n"
                        << selectedProject->getName() << "\n\n";

                break;
            }

            case DISPLAY_LIST: // Display selected project and its tasks
            {
                printProjectList();
                break;
            }

            case PUSH_TASK_ON_SELECTED_PROJECT: // Add a Task to Project
                if (createTask()) {
                    std::cout << "Task created successfully!\n";
                } else {
                    std::cout << "Task name and description "
                            << "cannot be empty.\n";
                }
                std::cout << std::endl;
                break;

            case EXIT: // Exit
                killSwitch();
                std::cout << "Goodbye!\n\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
                return false;
            }

        return true;
    }

    void TerminalInterface::run() {
        showTitle();

        while (isRunning) {
            try {
                int choice = readMenuChoice();
                handleChoice(choice);
            } catch (const std::runtime_error &e) {
                std::cerr << '\n' << e.what() << '\n';
                killSwitch();
            }
        }
    }

} // namespace Familiar