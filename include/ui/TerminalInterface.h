#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H

namespace Familiar {

    class TerminalInterface {
    public:
        void run();
    private:
        bool isRunning = true;

        void showTitle() const;
        void showMenu() const;
        int readMenuChoice();
        bool handleChoice(int choice);
        void killSwitch();
    };

} // namespace Familiar

#endif