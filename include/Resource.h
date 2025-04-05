#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
public:
    enum class Type { Consumable, Usable };
protected:
    std::string name;
    bool isAvailable;
    Type resourceType;
public:
    Resource(std::string name, Type type);
    virtual ~Resource() = default;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] virtual bool isAvailableForUse() const = 0;
    [[nodiscard]] Type getResourceType() const;
    virtual void allocate() = 0;
    virtual void use() = 0;
    virtual void release() = 0;
};
#endif //RESOURCE_H
