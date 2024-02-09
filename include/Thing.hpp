#ifndef THING_HPP
#define THING_HPP

#include "Attributable.hpp" // Assumed to be an abstract class or interface
#include "Name.hpp" // Assuming Name is a class with a public member `value` of type std::string
#include <iostream>
#include <memory>
#include <iomanip>

class Thing : public Attributable {
public:
    // Assuming getAttribute is a template method in Attributable returning std::shared_ptr to the requested attribute
    virtual std::shared_ptr<Name> getName() const {
        return std::static_pointer_cast<Name>(getAttribute<Name>());
    }

    virtual void log(const std::string& state) const {
        auto name = getName();
        int length = name->value.length();
        int max = 5;
        int l1 = (max - length + 1) / 2 + 1;
        int l2 = (max - length) / 2 + length;
        std::cout << std::left << std::setw(l1) << "[" << std::setw(l2) << name->value << "] " << state << std::endl;
    }

    virtual std::string getNameRef() const {
        auto name = getName();
        return "[" + name->value + "]";
    }
};

#endif // THING_HPP

