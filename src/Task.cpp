#include "domain/Task.h"
#include "domain/Project.h"

namespace Familiar {
    Task::Task(const Project& parent, int id) 
        : id(id), 
        parentId(parent.getId())
    {}
    int Task::getId() const {
        return id;
    }
    const std::string& Task::getTitle() const {
        return title;
    }
    void Task::setTitle(const std::string& title) {
        this->title = title;
    }
    const std::string& Task::getDescription() const {
        return description;
    }

    void Task::setDescription(const std::string& desc) {
        this->description = desc;
    }

    TaskStatus Task::getStatus() const {
        return status;
    }

    void Task::setStatus(TaskStatus status) {
        this->status = status;
    }
};