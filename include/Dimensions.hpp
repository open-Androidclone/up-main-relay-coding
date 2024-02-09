#ifndef DIMENSIONS_HPP
#define DIMENSIONS_HPP

#include "Attribute.hpp" // 包含Attribute基类的定义

// Dimensions类定义，继承自Attribute
class Dimensions : public Attribute {
public:
    // 构造函数
    Dimensions() {}

    // 虚析构函数
    virtual ~Dimensions() {}
};

#endif // DIMENSIONS_HPP
