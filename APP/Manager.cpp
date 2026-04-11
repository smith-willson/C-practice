#include "ProjectManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Change "Manager::" to "ProjectManager::"
void ProjectManager::showProjects() {
    for (const auto& p : projects) {
        std::cout << "Client: " << p.clientName << " | Project: " << p.title << " | $" << p.budget << std::endl;
    }
}

void ProjectManager::saveToFile() {
    std::ofstream file("database.txt");
    if (file.is_open()) {
        for (const auto& p : projects) {
            file << p.clientName << "," << p.title << "," << p.budget << "," << p.status << "\n";
        }
        file.close();
    }
}

void ProjectManager::loadFromFile() {
    projects.clear();
    std::ifstream file("database.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, title, budgetStr, status;

        if (std::getline(ss, name, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, budgetStr, ',') &&
            std::getline(ss, status, ',')) {
            
            Project p;
            p.clientName = name;
            p.title = title;
            p.budget = std::stod(budgetStr);
            p.status = status;
            projects.push_back(p);
        }
    }
}

void ProjectManager::addProject(Project p) {
    projects.push_back(p);
    saveToFile();
}