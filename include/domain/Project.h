#pragma once

#include <string>

namespace Familiar {
    enum ProjectStatus {
        Active=1,
        Completed=2,
        Archived=3
    };
    class Project {
        public:
            explicit Project(int id, std::string name, std::string desc, ProjectStatus);
            int getId() const;
            const std::string& getName() const;
            void setName(const std::string& name);
            const std::string& getDescription() const;
            void setDescription(const std::string& desc);
            ProjectStatus getStatus() const;
            void setStatus(ProjectStatus status);
        public:
            int id = 0;
            std::string name; 
            std::string description;
            ProjectStatus status = ProjectStatus::Active;
    };
}