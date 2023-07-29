#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die rolls return a value from 1 to 6", "[die]")
{
	Die die;
	for(int i = 0; i < 10; i++) {
		die.roll();
		int value = die.rolled_value();
		REQUIRE(value >= 1);
		REQUIRE(value <= 6);
	}
}

TEST_CASE("Ensure die rolls return a value from 2 to 12.")
{
	
	Die die1, die2;
	
	Roll roll(die1, die2);
	
	for(int i = 0; i < 10; i++) {
	
		roll.roll_die();
	
		int value = roll.roll_value(); 
	
		REQUIRE(value >= 2);
		REQUIRE(value <= 12);
	
	}
}

TEST_CASE("Shooter class test - Refactored Approach")
{
	Die die1, die2;
	Shooter shooter;

	for(int i=0; i < 10; i++){
		
		Roll* roll = shooter.throw_dice(die1, die2);
	
		REQUIRE(roll->roll_value() >= 2);
		REQUIRE(roll->roll_value() <= 12);
	}
}

TEST_CASE("Shooter class test - Alternate Approach")
{
	Die die1, die2;
	Shooter shooter;

	for(int i=0; i < 10; i++){
		
		Roll* roll = shooter.throw_dice(die1, die2);
		
		int roll_value = roll->roll_value();  
   
        REQUIRE(roll_value >= 2);
        REQUIRE(roll_value <= 12);
	}
}

TEST_CASE("Phase classes ComeOutPhase OutComes")
{
	Die die1, die2;
	Shooter shooter;

	ComeOutPhase come_out_phase;
	
	for(int i = 0; i < 10; i++){
		Roll* roll = shooter.throw_dice(die1, die2);
		RollOutcome outcome = come_out_phase.get_outcome(roll);

		
		REQUIRE((outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point));
	}


}

TEST_CASE("Phase classes PointPhase OutComes")
{
	Die die1, die2;
	Shooter shooter;

	
	PointPhase point_phase(4);
	
	for(int i = 0; i < 10; i++){
		Roll* roll = shooter.throw_dice(die1, die2);
		RollOutcome outcome = point_phase.get_outcome(roll);

		REQUIRE((outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint));
	}


}