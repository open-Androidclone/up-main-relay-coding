#ifndef ABSTRACTFEELABLETHING_HPP
#define ABSTRACTFEELABLETHING_HPP

#include "AbstractMovableThing.hpp" // Assuming AbstractMovableThing is defined in this header
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class AbstractFeelableThing : public AbstractMovableThing {
protected:
    std::vector<std::string> feelings;
    Thing* satisfaction = nullptr;

public:
    // Adds a feeling to the feelings vector
    void addFeeling(const std::string& feeling) {
        feelings.push_back(feeling);
        log("feel " + feeling + "!");
    }

    // Removes a feeling from the feelings vector
    void removeFeeling(const std::string& feeling) {
        auto it = std::find(feelings.begin(), feelings.end(), feeling);
        if (it != feelings.end()) {
            feelings.erase(it);
            log("del '" + feeling + "'");
        }
    }

    // Returns the index of a feeling in the feelings vector
    int getFeelingIndex(const std::string& feeling) const {
        auto it = std::find(feelings.begin(), feelings.end(), feeling);
        if (it != feelings.end()) {
            return std::distance(feelings.begin(), it);
        }
        return -1; // Indicates not found
    }

    // A method to simulate visibility changes
    void canSee(bool state) {
        log("set canSee=" + std::to_string(state));
    }

    // Placeholder functions for stimulation counts
    virtual int getNumStimulationsAvailable() const {
        return 0;
    }

    virtual int getNumStimulationsNeeded() const {
        return 0;
    }

    // Returns a pointer to self as satisfaction, simulating the toSatisfaction method
    Thing* toSatisfaction() {
        return this;
    }

    // Sets the satisfaction and adds "happy" to feelings
    void setSatisfaction(Thing* thing) {
        satisfaction = thing;
        addFeeling("happy");
    }

protected:
    // Logging function to output messages
    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // ABSTRACTFEELABLETHING_HPP
