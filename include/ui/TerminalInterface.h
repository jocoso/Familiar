#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H

#include <string>
#include <vector>

#include "persistence/ProjectManager.h"

namespace Familiar {
    const int MAX_NUMBER_OF_OPTIONS = 5;
    class TerminalInterface {
        public:
            void run();
            
        private:
            bool isRunning = true;
            ProjectManager pm;
            Project* selectedProject = nullptr;
            
            const std::vector<std::unique_ptr<Project>>&
            getProjectList();
            
            void showTitle() const;
            void showMenu() const;
            void printReport() const;
            void printSelectedProjectTask();
            void printProject(const Project& p);
            void printTasks(const std::vector<Task>& t);
    
            int readNumber();
            void readWord(std::string& output);
            int readMenuChoice();
            
            bool createProject();
            bool createTask();
            bool handleChoice(int choice);
            void killSwitch();

            bool SaveData();
            std::string saveProjectList(std::ofstream& datafile);

            Project* getSelectedProject();
  
    };

} // namespace Familiar

#endif // FAMILIAR_TERMINAL_INTERFACE_H