#ifndef TOMATO_HPP
#define TOMATO_HPP

#include "Attributable.hpp" // Assuming Attributable is defined and includes getAttribute and resetAttribute methods
#include "Antioxidants.hpp" // Include the Antioxidants attribute class definition
#include <typeindex>

class Tomato : public Attributable {
public:
    // Constructor, if needed
    Tomato() = default;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Tomato() {}

    // Mimicking the getAntioxidants default method from the Java interface
    Antioxidants* getAntioxidants() const {
        // Assuming getAttribute returns a pointer to Attributable (or Attribute) and needs to be dynamically cast
        return static_cast<Antioxidants*>(getAttribute(std::type_index(typeid(Antioxidants))));
    }

    // Mimicking the resetAntioxidants default method from the Java interface
    void resetAntioxidants() {
        resetAttribute(std::type_index(typeid(Antioxidants)));
    }
};

#endif // TOMATO_HPP
