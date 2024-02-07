#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Thing.hpp" // Assuming Thing is an abstract base class
#include "Circumference.hpp" // Include the Circumference attribute class definition

class Circle : public Thing {
public:
    // Constructor, if needed, can go here

    // Mimicking the getCircumference default method from the Java interface
    Circumference* getCircumference() const {
        // Static cast is used here to cast from Thing* to Circumference*.
        // This assumes getAttribute returns a pointer to Thing (or Attribute) and needs to be dynamic_casted in a real scenario
        // where multiple inheritance or polymorphism is involved.
        return static_cast<Circumference*>(getAttribute(std::type_index(typeid(Circumference))));
    }

    // Mimicking the resetCircumference default method from the Java interface
    void resetCircumference() {
        resetAttribute(std::type_index(typeid(Circumference)));
    }

    // Virtual destructor to ensure proper cleanup when objects are deleted through a pointer to Circle (or Thing)
    virtual ~Circle() {}
};

#endif // CIRCLE_HPP
