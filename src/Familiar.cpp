#include "Familiar.h"
#include "ui/TerminalInterface.h"

#include <string>

namespace Familiar {

    int Application::run() {
        TerminalInterface ti;

        ti.run();
        return 0;
    }

}