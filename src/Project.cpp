#include "domain/Project.h"

namespace Familiar {
    
    Project::Project(int id, std::string name, std::string desc, ProjectStatus parent=ProjectStatus::Active):
        id(id), name(name), description(desc), status(parent) {}
    int Project::getId() const {
        return id;
    }
    const std::string& Project::getName() const {
        return name;
    } 
    void Project::setName(const std::string& name) {
        this->name = name;
    }
    const std::string& Project::getDescription() const {
        return description;
    }
    void Project::setDescription(const std::string& desc) {
        this->description = desc;
    }
    ProjectStatus Project::getStatus() const {
        return status;
    }

    void Project::setStatus(ProjectStatus status) {
        this->status = status;
    }
};