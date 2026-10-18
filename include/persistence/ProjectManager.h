#pragma once

#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include "domain/Project.h"

namespace Familiar
{
    class ProjectManager
    {
    private:
        std::vector<Project> projects;

    public:
        bool createProject(const Project& project);

        const std::vector<Project>& listProjects() const;

        bool addTaskToProject(int projectId, const Task& task);

        Project* findProject(int id);

        bool updateProject(int id, const Project& updatedProject);

        bool deleteProject(int id);
    };
}

#endif