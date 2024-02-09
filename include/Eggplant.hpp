#ifndef EGGPLANT_HPP
#define EGGPLANT_HPP

#include "Attributable.hpp" // Assuming Attributable is defined and includes getAttribute and resetAttribute methods
#include "Nutrients.hpp" // Include the Nutrients attribute class definition

class Eggplant : public Attributable {
public:
    // Constructor, if needed, can go here

    // Mimicking the getNutrients default method from the Java interface
    Nutrients* getNutrients() const {
        // Assuming getAttribute returns a pointer to Attributable (or Attribute) and needs to be casted
        return static_cast<Nutrients*>(getAttribute(std::type_index(typeid(Nutrients))));
    }

    // Mimicking the resetNutrients default method from the Java interface
    void resetNutrients() {
        resetAttribute(std::type_index(typeid(Nutrients)));
    }

    // Virtual destructor to ensure proper cleanup when objects are deleted through a pointer to Eggplant (or Attributable)
    virtual ~Eggplant() {}
};

#endif // EGGPLANT_HPP
