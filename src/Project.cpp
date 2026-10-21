#include "domain/Project.h"

#include <algorithm>
#include <utility>
 
namespace Familiar {
    
    Project::Project(
        int id, 
        std::string name, 
        std::string desc, 
        ProjectStatus status
    ):
        id(id), name(name), description(desc), status(status) {}
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

     // Task management
    void Project::addTask(const Task& task) 
    {
        tasks.push_back(task);
    }
    bool Project::removeTask(int taskId)
    {
        auto it = std::find_if(
            tasks.begin(),
            tasks.end(),
            [taskId](const Task& task) 
            {
                return task.getId() == taskId;
            }
        );

        if(it == tasks.end())
        {
            return false;
        }

        tasks.erase(it);
        return true;

    }
   
    
    const Task* Project::getTask(int taskId) const
    {
        auto it = std::find_if(
            tasks.begin(),
            tasks.end(),
            [taskId](const Task& task) {
                return task.getId() == taskId;
            }
        );


        if(it == tasks.end()) 
        {
            return nullptr;
        }
        return &(*it);
    }

    const std::vector<Task>& Project::getTasks() const
    {
        return tasks;
    }
};