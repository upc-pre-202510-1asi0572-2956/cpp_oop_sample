#ifndef USABLE_RESOURCE_H
#define USABLE_RESOURCE_H

#include "Resource.h"

class UsableResource final : public Resource {
private:
    int capacity;
public:
    UsableResource(const std::string& name, int capacity);
    [[nodiscard]] bool isAvailableForUse() const override;
    void allocate() override;
    void use() const override;
    void release() override;
};
#endif //USABLE_RESOURCE_H
