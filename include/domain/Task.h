
#pragma once

#include <string>
#include "Project.h"

/** 
CLASS Task
    PRIVATE:
        taskData

    PUBLIC:
        initializeTask()
        getTaskData()
        updateTaskData()
END CLASS
*/

namespace Familiar {
    enum class TaskStatus {
        Pending=1,
        Active=2,
        Completed=3,
        Blocked=4,
        Cancelled=5
    };
    class Task {
        public:
            Task(const Project& parent, int id);
            
            int getId() const;
            int getProjectId() const;

            const std::string& getTitle() const;
            void setTitle(const std::string& title);

            const std::string& getDescription() const;
            void setDescription(const std::string& desc);

            TaskStatus getStatus() const;
            void setStatus(TaskStatus status);
            
        public:
            int id = 0;
            int projectId = 0;

            std::string title;
            std::string description;
            
            TaskStatus status = TaskStatus::Pending;
    };
}