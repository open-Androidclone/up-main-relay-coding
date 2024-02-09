#ifndef CIRCUMFERENCE_HPP
#define CIRCUMFERENCE_HPP

#include "Attribute.hpp" // 包含Attribute基类的定义

// Circumference类定义，继承自Attribute
class Circumference : public Attribute {
public:
    // 构造函数
    Circumference() {}

    // 虚析构函数
    virtual ~Circumference() {}
};

#endif // CIRCUMFERENCE_HPP
