#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H

#include "persistence/ProjectManager.h"
#include <string>
#include <optional>

namespace Familiar {

    class TerminalInterface {
        private:
            bool isRunning = true;
            ProjectManager pm;
            std::optional<Project> selectedProject;
        
        public:
            void run();
        private:
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