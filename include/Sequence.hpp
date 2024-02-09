#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include "Thing.hpp" // Assuming Thing is an abstract class that Sequence will extend
#include <iostream>
#include <string>

class Sequence : public Thing {
public:
    // Constructor, if needed
    Sequence() = default;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Sequence() {}

    // Mimicking the toLimit default method from the Java interface
    virtual Thing* toLimit() {
        return this;
    }

    // Mimicking the setLimit default method from the Java interface
    virtual void setLimit(Thing* limit) {
        // Assuming Thing has a method getNameRef() that returns a string reference
        log("set limit=" + limit->getNameRef());
    }

private: // Changed from protected to private
    // Logging function to output messages, similar to Java's log method
    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // SEQUENCE_HPP
