// Name.hpp
#ifndef NAME_HPP
#define NAME_HPP

#include "Attribute.hpp"
#include <string>

class Name : public Attribute {
public:
    std::string value;

    explicit Name(const std::string& value) : value(value) {}
    virtual ~Name() {}

    std::string toString() const override {
        return value;
    }
};

#endif // NAME_HPP
