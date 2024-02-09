#ifndef ATTRIBUTABLE_HPP
#define ATTRIBUTABLE_HPP

#include <memory> // 包含标准库memory头文件，以便使用智能指针

// 前向声明Attribute类，因为我们在这里使用它，但是实现可能在其他文件中
class Attribute;

// Attributable类声明
class Attributable {
public:
    // 虚析构函数，确保通过基类指针删除派生类对象时能正确调用派生类的析构函数
    virtual ~Attributable() {}

    // 纯虚函数，用于获取属性，采用模板方法实现多态
    template <typename T>
    virtual std::unique_ptr<Attribute> getAttribute() = 0;

    // 纯虚函数，用于添加属性
    virtual void addAttribute(std::unique_ptr<Attribute> attribute) = 0;

    // 纯虚函数，用于重置属性，采用模板方法实现多态
    template <typename T>
    virtual void resetAttribute() = 0;
};

#endif // ATTRIBUTABLE_HPP
