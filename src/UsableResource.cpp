#include "UsableResource.h"
#include <iostream>
#include <stdexcept>

UsableResource::UsableResource(const std::string &name, int capacity)
: Resource(name, Type::Usable), capacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource " + name + " must be positive.");
    }
}

bool UsableResource::isAvailableForUse() const {
    return isAvailable;
}

void UsableResource::allocate() {
    if (!isAvailable) {
        throw std::runtime_error("UsableResource " + getName() + " is already allocated.");
    }
    isAvailable = false;
}

void UsableResource::release() {
    if (isAvailable) {
        std::cerr << "Warning: UsableResource " << getName() << " is already released." << std::endl;
    }
    isAvailable = true;
}

void UsableResource::use() const {
    std::cout << "Using resource: " << getName() << " (capacity: "<< capacity << " GHz)" << std::endl;
}

