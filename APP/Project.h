#ifndef PROJECT_H
#define PROJECT_H
#include <string>

struct Project {
    std::string clientName; // Changed from 'client' to 'clientName'
    std::string title;
    double budget;
    std::string status;

    // This is the 'serialize' function the compiler said was missing
    std::string serialize() const {
        return clientName + "|" + title + "|" + std::to_string(budget) + "|" + status;
    }
};
#endif