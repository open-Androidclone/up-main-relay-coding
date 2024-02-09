#ifndef ABSTRACTMOVABLETHING_HPP
#define ABSTRACTMOVABLETHING_HPP

#include "AbstractAttributableThing.hpp" // Include the base class header
#include "Pose.hpp" // Include the Pose class header
#include <string>
#include <iostream>

class AbstractMovableThing : public AbstractAttributableThing {
protected:
    Pose pose; // Composition: Pose object as a member

public:
    // Constructor to initialize pose, if needed
    AbstractMovableThing(double x = 0, double y = 0, double theta = 0) : pose(x, y, theta) {}

    // Getter for the x position from the pose
    double getXPosition() const {
        return pose.x;
    }

    // Method to add an action, taking a Pose object and a type of action as parameters
    void addAction(const std::string& type, const Pose& pose) {
        // For demonstration, just logs the action. Actual implementation will vary.
        log("set ACTION='" + type + "'");
    }

protected:
    // Logging function to output messages
    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // ABSTRACTMOVABLETHING_HPP
