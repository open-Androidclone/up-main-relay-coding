#ifndef LIMIT_HPP
#define LIMIT_HPP

#include "Attribute.hpp" // 包含Attribute基类的定义

// Limit类定义，继承自Attribute
class Limit : public Attribute {
public:
    // 构造函数
    Limit() {}

    // 析构函数
    virtual ~Limit() {}

    // 由于Limit继承了Attribute，它自动拥有toAttribute方法
    // 如果需要，这里可以覆盖或添加其他方法
};

#endif // LIMIT_HPP
