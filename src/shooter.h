//
#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"

class Shooter {
public:
    Shooter();  // Constructor is optionally added for further initialization if needed.
    ~Shooter();  // Destructor to clean up dynamically allocated memory.
    Roll* throw_dice(Die& die1, Die& die2);  // Throws dice, creates a new roll, stores, and returns it.
    void display_rolled_values();  // Displays values of all rolls.

private:
    std::vector<Roll*> rolls;  // Stores pointers to dynamically allocated Roll instances.
};

#endif // SHOOTER_H
