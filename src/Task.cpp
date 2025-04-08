#include "Task.h"
#include <iostream>

Task::Task(const std::string& name, const std::string& description,
           const std::vector<std::string> &requiredResourcesNames, int durationInUnits)
           : Executable(name, description, requiredResourcesNames, durationInUnits)
           {}

void Task::execute() const {
    if (assignedResources.size() != requiredResourcesNames.size()) {
        throw std::runtime_error("Not all required resources are assigned for task " + name + ".");
    }
    std::cout << "Executing task: " << name
    << ": " << description << " (Duration: " << durationInUnits << " units)"  << std::endl;
    for (const auto* resource : assignedResources) {
        resource->use();
    }
}
