#ifndef SINEWAVE_HPP
#define SINEWAVE_HPP

#include "Thing.hpp" // Assuming Thing is an abstract class that SineWave will extend
#include "Pose.hpp" // Include the Pose class definition
#include <cmath> // For std::atan, std::cos, and std::sin functions

class SineWave : public Thing {
public:
    // Constructor, if needed
    SineWave() = default;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~SineWave() {}

    // Mimicking the getTangent default method from the Java interface
    Pose getTangent(double x) const {
        double theta = std::atan(std::cos(x));
        return Pose(x, std::sin(x), theta);
    }
};

#endif // SINEWAVE_HPP
