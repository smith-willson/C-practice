#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include <string>
#include "Project.h"

class ProjectManager { 
public:
    std::vector<Project> projects;
    
    // Make sure these 4 lines are here!
    void showProjects(); 
    void loadFromFile();
    void saveToFile();
    void addProject(Project p);
};

#endif