#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

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
TEST_CASE("Shooter returns a Roll and verifies roll result is 2-12", "Shooter") {
    Die die1, die2;
    Shooter shooter;

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}
TEST_CASE("ComeOutPhase outcomes", "[ComeOutPhase]") {
    ComeOutPhase cop;
    Die die1, die2;
    Roll roll(die1, die2);

    roll.roll_dice();  // Simulate dice roll
    int value = roll.roll_value();
    if (value == 7 || value == 11) {
        REQUIRE(cop.get_outcome(&roll) == RollOutcome::natural);
    } else if (value == 2 || value == 3 || value == 12) {
        REQUIRE(cop.get_outcome(&roll) == RollOutcome::craps);
    } else {
        REQUIRE(cop.get_outcome(&roll) == RollOutcome::point);
    }
}

TEST_CASE("PointPhase outcomes", "[PointPhase]") {
    PointPhase pp(5);  // Assume point is 5
    Die die1, die2;
    Roll roll(die1, die2);

    roll.roll_dice();  // Simulate dice roll
    int value = roll.roll_value();
    if (value == 5) {
        REQUIRE(pp.get_outcome(&roll) == RollOutcome::point);
    } else if (value == 7) {
        REQUIRE(pp.get_outcome(&roll) == RollOutcome::seven_out);
    } else {
        REQUIRE(pp.get_outcome(&roll) == RollOutcome::nopoint);
    }
}