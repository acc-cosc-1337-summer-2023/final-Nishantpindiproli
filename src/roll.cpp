#include "roll.h"


#ifndef ROLL_CPP
#define ROLL_CPP

Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2), rolled(false) {}
    void Roll::roll_die(){
        die1.roll();
        die2.roll();
        bool rolled = true;
         int value = die1.rolled_value() + die2.rolled_value();

    }
    int Roll::roll_value() const {return value;}


#endif
