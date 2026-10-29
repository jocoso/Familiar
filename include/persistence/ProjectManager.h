#pragma once

#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include <memory>
#include "domain/Project.h"



namespace Familiar
{
    class ProjectManager
    {
    private:
        std::vector<std::unique_ptr<Project>> projects;

    public:
        const std::vector<std::unique_ptr<Project>>& 
        getProjects() const;

        bool createProject(std::unique_ptr<Project> project);

        bool addTaskToProject(int projectId, const Task& task);

        Project *findProject(int id);
        const Project* findProject(int id) const;

        bool updateProject(int id, const Project& updatedProject);

        bool deleteProject(int id);
    };
}

#endif