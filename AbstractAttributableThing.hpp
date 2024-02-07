#ifndef ABSTRACTATTRIBUTABLETHING_HPP
#define ABSTRACTATTRIBUTABLETHING_HPP

#include "Thing.hpp" // Assuming Thing is defined in Thing.hpp
#include "Attribute.hpp" // Assuming Attribute is the base class for all attributes
#include <unordered_map>
#include <typeindex>
#include <string>
#include <iostream>

class AbstractAttributableThing : public Thing {
private:
    std::unordered_map<std::type_index, Attribute*> attributeMap;

public:
    // Override the getAttribute function from Thing interface
    Attribute* getAttribute(const std::type_index& type) const override {
        auto it = attributeMap.find(type);
        if (it != attributeMap.end()) {
            return it->second;
        }
        return nullptr;
    }

    // Implementation of addAttribute
    void addAttribute(Attribute* attribute) {
        if (attribute) {
            attributeMap[std::type_index(typeid(*attribute))] = attribute;
            log("add attr(" + std::string(typeid(*attribute).name()) + ")");
        }
    }

    // Implementation of resetAttribute
    void resetAttribute(const std::type_index& type) {
        auto it = attributeMap.find(type);
        if (it != attributeMap.end()) {
            attributeMap.erase(it);
            log("del attr(" + std::string(type.name()) + ")");
        }
    }

protected:
    // Simple logger function for demonstration
    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // ABSTRACTATTRIBUTABLETHING_HPP
