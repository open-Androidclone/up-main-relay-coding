#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "Attribute.hpp" // 包含Attribute基类的定义

// Memory类定义，继承自Attribute
class Memory : public Attribute {
public:
    // 构造函数
    Memory() {}

    // 虚析构函数
    virtual ~Memory() {}

    // 实现isErasable方法
    bool isErasable() const {
        return true;
    }
};

#endif // MEMORY_HPP
