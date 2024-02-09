// Attribute.hpp
#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <string>

class Attribute {
public:
    virtual ~Attribute() {} // 虚析构函数以允许通过指针安全删除
    virtual std::string toString() const = 0; // 纯虚函数，表示该函数必须在派生类中被实现
};

#endif // ATTRIBUTE_HPP
