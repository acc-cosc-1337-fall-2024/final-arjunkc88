//
#include "shooter.h"
#include <iostream>

Shooter::Shooter() {}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;  // Free dynamically allocated memory for each roll.
    }
    rolls.clear();  // Clear the vector after deleting all pointers.
}

Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* newRoll = new Roll(die1, die2);  // Create a new Roll instance dynamically.
    newRoll->roll_dice();  // Perform the roll.
    rolls.push_back(newRoll);  // Store the pointer in the vector.
    return newRoll;  // Return the new roll instance.
}

void Shooter::display_rolled_values() {
    for (const Roll* roll : rolls) {
        std::cout << "Rolled value: " << roll->roll_value() << std::endl;
    }
}
