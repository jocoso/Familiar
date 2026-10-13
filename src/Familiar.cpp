#include "Familiar.h"
#include "ui/TerminalInterface.h"

#include <string>

/** 
FUNCTION Familiar::run()
    showTitle()

    WHILE isRunning
        showMenu()
        choice = readMenuChoice()
        handleChoice(choice)
    END WHILE
END FUNCTION
*/

namespace Familiar {
    int Application::run() {
        // Familiar implementation
        TerminalInterface ti;

        ti.run();
        return 0;
    }
}