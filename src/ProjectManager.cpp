#include <vector>
#include <algorithm>

#include "persistence/ProjectManager.h"
#include "domain/Project.h"

namespace Familiar
{
    bool ProjectManager::createProject(const Project& project)
    {
        projects.push_back(project);
        return true;
    }

    const std::vector<Project>& ProjectManager::listProjects()
 const   
    {
        return projects;
    }

    Project* ProjectManager::findProject(int id)
    {
        for (Project& project : projects)
        {
            if (project.getId() == id)
            {
                return &project;
            }
        }

        return nullptr;
    }

    bool ProjectManager::updateProject(
        int id,
        const Project& updatedProject)
    {
        for(Project& project : projects) 
        {
            if (project.getId() == id) 
            {
                project = updatedProject;
                return true;
            }
        }

        return false;
    }

    bool ProjectManager::addTaskToProject(int pId, const Task& t) 
    {
        Project* p = findProject(pId);

        if (p == nullptr)
        {
            return false;
        }

        p->addTask(t);
        return true;
    }

    bool ProjectManager::deleteProject(int id)
    {
        auto it = std::find_if(
            projects.begin(),
            projects.end(),
            [id](const Project& project)
            {
                return project.getId() == id;
            }
        );

        if (it == projects.end())
        {
            return false;
        }

        projects.erase(it);
        return true;
    }
}