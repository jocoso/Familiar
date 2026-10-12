#include "Familiar.h"
#include "ui/TerminalInterface.h"

#include <string>

namespace Familiar {
    int Application::run() {
        // Familiar implementation
        TerminalInterface ti;

        ti.run();
        return 0;
    }
}