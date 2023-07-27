#ifndef SHOOTER_H
#define SHOOTER_H

#include <iostream>
#include <vector>
#include "roll.h"
#include "die.h"

class Shooter 
{
    public:
        
        Roll* throw_dice(Die& die1, Die& die2);
       
        friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);
      
        ~Shooter();

    private:
       
        std::vector<Roll*> rolls;

};

#endif