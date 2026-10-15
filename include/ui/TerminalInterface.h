#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H

#include <optional>
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
            std::optional<Project> selectedProject;
            std::vector<Project> printProjectList();
            void showTitle() const;
            void showMenu() const;
    
            int readNumber();
            void readWord(std::string& output);
            int readMenuChoice();
            
            bool createProject();
            bool handleChoice(int choice);
            void killSwitch();

        
  
    };

} // namespace Familiar

#endif // FAMILIAR_TERMINAL_INTERFACE_H