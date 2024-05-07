//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    Roll(Die& d1, Die& d2);   // Constructor with initializer list for die references.
    void roll_dice();         // Rolls die1 and die2 and stores the sum.
    int roll_value() const;   // Returns the sum of the last roll.

private:
    Die& die1;    // Reference to the first die.
    Die& die2;    // Reference to the second die.
    int rolled_value;  // Stores the combined value of the last roll.
};

#endif // ROLL_H
