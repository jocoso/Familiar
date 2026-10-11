#include "Familiar.h"
#include "domain/Project.h"

#include <string>

namespace Familiar {
    int Application::run() {
        // Familiar implementation
        const int fooId = 1;
        const std::string name = "fooProject";
        const std::string desc = "fooDesc";
        const ProjectStatus status = ProjectStatus::Active;

        Project fooProject{fooId, name, desc, status};

        return 0;
    }
}