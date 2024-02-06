#ifndef POINT_SET_HPP
#define POINT_SET_HPP

#include "Thing.hpp" // Assuming Thing is also defined in a corresponding header file
#include "Dimensions.hpp" // Assuming Dimensions is a class that has been suitably defined

// Since C++ does not have interfaces, we use an abstract class to define PointSet.
class PointSet : public Thing {
public:
    // Assuming getAttribute and resetAttribute are implemented in Thing or its ancestors.
    
    // Get the Dimensions attribute of the PointSet.
    std::shared_ptr<Dimensions> getDimensions() {
        return std::dynamic_pointer_cast<Dimensions>(getAttribute(typeid(Dimensions).name()));
    }
    
    // Reset the Dimensions attribute of the PointSet.
    void resetDimensions() {
        resetAttribute(typeid(Dimensions).name());
    }
    
    // Virtual destructor to ensure proper cleanup of derived classes.
    virtual ~PointSet() {}
};

#endif // POINT_SET_HPP
