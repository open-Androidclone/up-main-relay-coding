#ifndef POSE_HPP
#define POSE_HPP

#include <cmath> // For std::cos and std::sin
#include <string> // For std::to_string

class Pose {
public:
    double x;
    double y;
    double theta; // Assume theta is in radians for consistency with Java version

    // Constructor
    Pose(double x, double y, double theta) : x(x), y(y), theta(theta) {}

    // toString method converted to a member function that returns a std::string
    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(theta * 180.0 / M_PI) + ")";
    }
};

#endif // POSE_HPP
