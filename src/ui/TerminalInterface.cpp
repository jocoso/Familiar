#include "ui/TerminalInterface.h"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <iomanip> // std::quoted
#include <vector>
#include <memory>


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

        auto p = std::make_unique<Project>(
            0,
            pName,
            pDesc,
            ProjectStatus::Active
        );

        pm.createProject(std::move(p));

        std::cout << '\n';

        return true;
    }

    void TerminalInterface::printSelectedProjectTask()
    {
        Project* project = getSelectedProject();
        
        if(project == nullptr)
        {
            std::cout << "No project selected.\n";
            return;
        }

        printProject(*project);
        printTasks(project->getTasks());
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

        const int projectId = selectedProject->getId();

        if(!pm.addTaskToProject(projectId, t))
        {
            std::cout << "Failed to add task to project.\n";
            return false;
        }

        const auto& project = pm.findProject(projectId);

        if(!project)
        {
            std::cout << "Task was added, but the project could not be retrieved.\n";
            return false;
        }

        *selectedProject = *project;

        return true;
    }

    Project* TerminalInterface::getSelectedProject() 
    {
        return selectedProject;
    }

    void TerminalInterface::printReport() const 
    {
        if(selectedProject == nullptr)
        {
            std::cout << "No project selected.\n\n";
            return;
        }

        std::cout << "=== SELECTED PROJECT ===\n";
        std::cout << selectedProject->getName() << '\n';
        std::cout << selectedProject->getDescription() << '\n';
        std::cout << "Status: " << selectedProject->getStatus() << '\n';

        std::cout << "\n[ Tasks ]\n";

        const auto tasks = selectedProject->getTasks();

        if(tasks.empty())
        {
            std::cout << "No tasks available.\n";
        }
        else
        {
            for(std::size_t i = 0; i < tasks.size(); ++i)
            {
                std::cout << i + 1 << " - "
                    << tasks[i].getTitle() << '\n';
                std::cout << tasks[i].getDescription() << '\n';
            }
        }
        std::cout << '\n';
    }

    const std::vector<std::unique_ptr<Project>>& 
        TerminalInterface::getProjectList() 
    {
        loadData();
        std::cout << "=== PROJECTS ===\n";
        const auto& projects = pm.getProjects();

        if (projects.empty()) {
            std::cout << "No projects found.\n";
        } else {
            int index = 1;

            for (const auto& p : projects) {
                std::cout << index++ << ". " << p->getName() << '\n';
                std::cout << "   Description: " 
                    << p->getDescription() << '\n';

                const std::vector<Task> t = p->getTasks();
                printTasks(t);
            }
        }

        std::cout << '\n';

        return projects;
    }


    // ================================ //

 


    std::string TerminalInterface::saveProjectList(std::ofstream& datafile)
    {

        datafile << "ROBOT_FAMILIAR_DATA_V1\n";
        const auto& projects = pm.getProjects();

        datafile << projects.size() << '\n';

        for (const auto& project : projects) {

            if(!project) continue;

            // Process project without copying it
            datafile << project->getId() << '\n';
            datafile << std::quoted(project->getName()) << '\n';
            datafile << std::quoted(project->getDescription()) << '\n';
            datafile << static_cast<int>(project->getStatus()) << '\n';  // Space '\n' delimiter

            const auto tasks = project->getTasks();

            datafile << tasks.size() << '\n';

            for(const auto& task : tasks)
            {
                datafile << task.getId() << '\n';
                datafile << std::quoted(task.getTitle()) << '\n';
                datafile << std::quoted(task.getDescription()) << '\n';
            }

        }

        return "";

    }

    void TerminalInterface::loadProjectList(std::ifstream& datafile)
    {
        std::string fileVersion;

        if (!(datafile >> fileVersion) ||
            fileVersion != "ROBOT_FAMILIAR_DATA_V1")
        {
            std::cerr << "Invalid or unsupported data file format.\n";
            return;
        }


        std::size_t projectCount = 0;

        if (!(datafile >> projectCount))
        {
            std::cerr << "Failed to read project count.\n";
            return;
        }

        for (std::size_t i = 0; i < projectCount; ++i)
        {
            int projectId;
            int statusValue;
            std::size_t taskCount;

            std::string name;
            std::string description;

            if(!(datafile >> projectId
                        >> std::quoted(name)
                        >> std::quoted(description)
                        >> statusValue
                        >> taskCount))
            {
                std::cerr << "Incomplete project record found.\n";
                return;
            }

            if (statusValue < 0 || statusValue > 2)
            {
                std::cerr << "Invalid project status.\n";
                return;
            }

            auto project = std::make_unique<Project>(
                projectId,
                name,
                description,
                static_cast<ProjectStatus>(statusValue)
            );

            if(!pm.loadProject(std::move(project)))
            {
                std::cerr << "Failed to load project or duplicate ID found. \n";
            }

            for(std::size_t j = 0; j < taskCount; ++j)
            {
                int taskId;
                std::string taskTitle;
                std::string taskDescription;

                if (!(datafile >> taskId
                            >> std::quoted(taskTitle)
                            >> std::quoted(taskDescription)))
                {
                    std::cerr << "Incomplete task record found.\n";
                    return;
                }

                Task task{
                    taskId,
                    taskTitle,
                    taskDescription
                };

                if (!pm.addTaskToProject(projectId, task))
                {
                    std::cerr << "Failed to restore task "
                            << taskId << " to project "
                            << projectId << ".\n";
                }
            }
        }

        std::cout << "Projects and tasks loaded successfully!\n\n";
    }


    bool TerminalInterface::saveData()
    {
        std::ofstream datafile(
            "datafile.txt",
            std::ios::out | std::ios::trunc
        );
        
        if(!datafile.is_open()) 
        {
            std::cerr << "Failed to open datafile.txt for writing.\n";
            return false;
        }

        saveProjectList(datafile);
        
        if(!datafile.good())
        {
            std::cerr << "Failed to write project data.\n";
            return false;
        }

        datafile.close();

        if (datafile.fail())
        {
            std::cerr << "Failed to close datafile.txt correctly.\n";
            return false;
        }

        std::cout << "Projects and tasks saved successfully!\n\n";

        return true;
    }

    bool TerminalInterface::loadData()
    {
        std::ifstream datafile("datafile.txt");

        if(!datafile.is_open()) 
        {
            std::cerr << "Not existing datafile.txt found.\n";
            return false;
        }

        pm.clearProjects();

        loadProjectList(datafile);

        return true;
    }

    bool TerminalInterface::handleChoice(int choice) {
        switch (choice) {
            case CREATE_PROJECT: // Create projects
                if (createProject()) {
                    std::cout << "Project created successfully!\n";
                    saveData();
                } else {
                    std::cout << "Project name and description "
                            << "cannot be empty.\n";
                }
                std::cout << std::endl;
                break;

            case SELECT_PROJECT: { // Select projects
                const auto& projects = getProjectList();

                if (projects.empty())
                    break;

                std::cout << "What project do you want to select?\n";

                int selection = readNumber();

                if (selection < 1 ||
                    static_cast<std::size_t>(selection) > projects.size()) {
                    std::cout << "Invalid project selection.\n\n";
                    break;
                }

                selectedProject = projects[selection - 1].get();

                std::cout << "Selected Project: \n"
                        << selectedProject->getName() << "\n\n";

                break;
            }

            case DISPLAY_LIST: // Display selected project and its tasks
            {
                getProjectList();
                break;
            }

            case PUSH_TASK_ON_SELECTED_PROJECT: // Add a Task to Project
                if (createTask()) {
                    std::cout << "Task created successfully!\n";
                    saveData();
                } else {
                    std::cout << "Task name and description "
                            << "cannot be empty.\n";
                }
                std::cout << std::endl;
                break;

            case EXIT: // Exit
                saveData();
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

        loadData();
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