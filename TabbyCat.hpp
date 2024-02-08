#ifndef TABBYCAT_HPP
#define TABBYCAT_HPP

#include "Thing.hpp" // Assuming Thing is an abstract class that TabbyCat will extend
#include <iostream>
#include <string>

class TabbyCat : public Thing {
public:
    // Constructor, if needed
    TabbyCat() = default;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~TabbyCat() {}

    // Mimicking the purr default method from the Java interface
    void purr() const {
        log("set ACTION='purr'");
    }

private:
    // Logging function to output messages, similar to Java's log method
    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // TABBYCAT_HPP
