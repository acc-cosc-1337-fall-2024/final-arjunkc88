#include <iostream>
#include <cstdlib>  // For std::srand and std::rand
#include <ctime>    // For std::time
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Create two instances of Die
    Die die1, die2;

    // Create a Shooter instance
    Shooter shooter;

    // Create a pointer to Roll and a rolled_value variable
    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value;

    // Create a ComeOutPhase instance
    ComeOutPhase come_out_phase;

    // Loop until RollOutcome is not natural or craps
    while (true) {
        rolled_value = roll->roll_value();
        RollOutcome outcome = come_out_phase.get_outcome(roll);
        std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
        if (outcome != RollOutcome::natural && outcome != RollOutcome::craps) {
            break;
        }
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << rolled_value << " start of point phase" << std::endl;
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled" << std::endl;

    // Set point to the current rolled_value
    int point = rolled_value;
    roll = shooter.throw_dice(die1, die2);

    // Create an instance of PointPhase with proper parameter
    PointPhase point_phase(point);

    // Loop until RollOutcome is seven_out or nopoint
    while (true) {
        rolled_value = roll->roll_value();
        RollOutcome outcome = point_phase.get_outcome(roll);
        std::cout << "Rolled " << rolled_value << ", roll again" << std::endl;
        if (outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint) {
            break;
        }
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << rolled_value << " end of point phase" << std::endl;

    // Display all rolled values
    std::cout << "Shooter rolled values:" << std::endl;
    shooter.display_rolled_values();

    return 0;
}
