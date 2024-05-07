//
#include "die.h"
#include <ctime>   // For std::time()

// Constructor
Die::Die() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random number generator.
}

// Roll the die
int Die::roll() const {
    return std::rand() % sides + 1; // Random number between 1 and 6.
}
