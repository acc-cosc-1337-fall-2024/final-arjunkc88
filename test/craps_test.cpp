#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Verify Die Rolls", "Die") {
    Die die;
    for (int i = 0; i < 10; ++i) {
        int roll = die.roll();
        REQUIRE(roll >= 1);
        REQUIRE(roll <= 6);
    }
}
TEST_CASE("Die rolls return a value from 2 to 12", "Roll") {
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int result = roll.roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}