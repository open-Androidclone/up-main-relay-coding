#ifndef WORLD_HPP
#define WORLD_HPP
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "allinone.hpp"
class Thing; // Forward declaration to make Thing known
class Lovable; // Forward declaration for Lovable, assuming it's derived from Thing

class World : public AbstractAttributableThing {
public:
    std::vector<std::shared_ptr<Thing>> things;
    std::shared_ptr<Thing> god;

    explicit World(int i) {
        // Assuming addAttribute takes a pointer to an attribute
        addAttribute(std::make_shared<Name>("WORLD"));
    }

    void addThing(std::shared_ptr<Thing> thing) {
        things.push_back(thing);
        log("ADD " + thing->getNameRef());
        if (!god) {
            god = thing;
        }
    }

    void removeThing(std::shared_ptr<Thing> thing) {
        auto it = std::remove_if(things.begin(), things.end(), 
                                 [&thing](const std::shared_ptr<Thing>& t) { return t == thing; });
        if (it != things.end()) {
            log("DEL " + thing->getNameRef());
            things.erase(it, things.end());
        }
    }

    int getThingIndex(std::shared_ptr<Thing> thing) {
        auto it = std::find(things.begin(), things.end(), thing);
        if (it == things.end()) {
            log("CAN NOT FIND " + thing->getNameRef() + "!");
            return -1;
        }
        return std::distance(things.begin(), it);
    }

    std::shared_ptr<Thing> getGod() const {
        return god;
    }

    void startSimulation() {
        log("START...");
    }

    void timeTravel(const std::string& period, int year, std::shared_ptr<Thing> t1) {
        t1->log("traveled to " + period + std::to_string(year));
    }

    void timeTravelForTwo(const std::string& period, int year, std::shared_ptr<Thing> t1, std::shared_ptr<Thing> t2) {
        timeTravel(period, year, t1);
        timeTravel(period, year, t2);
    }

    void lockThing(std::shared_ptr<Thing> thing) {
        log("LOCK " + thing->getNameRef());
    }

    void unlock(std::shared_ptr<Thing> thing) {
        log("UNLOCK " + thing->getNameRef());
    }

    void unite(std::shared_ptr<Lovable> t1, std::shared_ptr<Lovable> t2) {
        log(t1->getNameRef() + " UNITE " + t2->getNameRef());
    }

    void procreate(std::shared_ptr<Lovable> l1, std::shared_ptr<Lovable> l2) {
        procreate0(l1, l2);
        procreate0(l2, l1);
    }

    void makeHigh(std::shared_ptr<Lovable> lovable) {
        lovable->log("make high!");
    }

    void runExecution() {
        log("EXECUTION");
    }

    void execute(std::shared_ptr<Thing> thing) {
        auto it = std::remove_if(things.begin(), things.end(), 
                                 [&thing](const std::shared_ptr<Thing>& t) { return t == thing; });
        if (it != things.end()) {
            log("EXECUTE " + thing->getNameRef());
            things.erase(it, things.end());
        }
    }

    bool isExecutableBy(std::shared_ptr<Thing> thing) {
        return true; // Simplified logic
    }

    void announce(const std::string& val) {
        log(val);
    }

    void announce(const std::string& val, const std::string& locale) {
        // Locale translation unsupported
        log(val + " (" + locale + ")");
    }

protected:
    void log(const std::string& message) {
        std::cout << message << std::endl;
    }

private:
    void procreate0(std::shared_ptr<Lovable> l1, std::shared_ptr<Lovable> l2) {
        // Assuming gender is a public or accessible member of Lovable
        if (l1->gender && !l2->gender) {
            l2->log("procreated!");
        }
    }
};

#endif // WORLD_HPP
