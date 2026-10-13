#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H



/** 
     * CLASS TerminalInterface
        PRIVATE:
            isRunning
            ProjectManager
            TaskManager

        PUBLIC:
            run()

        PRIVATE:
            showTitle()
            showMenu()
            readMenuChoice()
            handleChoice(choice)
            killSwitch()
    END CLASS
*/

namespace Familiar {

    class TerminalInterface {
        private:
            bool isRunning = true;
        
        public:
            void run();
            void showTitle() const;
            void showMenu() const;
            int readMenuChoice();
            bool handleChoice(int choice);
            void killSwitch();
    };

} // FAMILIAR_TERMINAL_INTERFACE_H

#endif