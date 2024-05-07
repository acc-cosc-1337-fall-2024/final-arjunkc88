//
#include "roll.h"

// Constructor initializing die references using an initializer list
Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2) {}

// Rolls both dice and calculates the total rolled value
void Roll::roll_dice() {
    rolled_value = die1.roll() + die2.roll();
}

// Returns the total value of the dice roll
int Roll::roll_value() const {
    return rolled_value;
}
