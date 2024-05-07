//
#ifndef DIE_H
#define DIE_H

#include <cstdlib>  // For std::rand()

class Die {
public:
    Die();            // Constructor to initialize the random number generator.
    int roll() const; // Returns a random number between 1 and 6.

private:
    static const int sides = 6; // Number of sides on the die.
};

#endif // DIE_H
