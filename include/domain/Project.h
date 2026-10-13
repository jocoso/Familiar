#ifndef FAMILIAR_PROJECT_H
#define FAMILIAR_PROJECT_H

#pragma once

#include <string>

/** 
CLASS Project
    PRIVATE:
        id: Integer
        name: String
        description: String
        status: ProjectStatus

    PUBLIC:
        CONSTRUCTOR Project(id, name, description, status)

        getId() -> Integer
        getName() -> String
        setName(name: String)

        getDescription() -> String
        setDescription(description: String)

        getStatus() -> ProjectStatus
        setStatus(status: ProjectStatus)
END CLASS


ENUM ProjectStatus
    Active = 1
    Completed = 2
    Archived = 3
END ENUM
*/

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

#endif // FAMILIAR_PROJECT_H