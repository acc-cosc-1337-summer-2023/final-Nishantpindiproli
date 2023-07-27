#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die();
    Die(int num){roll_value = num;}
    void roll(); 
    int rolled_value() const; 

private:
    int roll_value; 
    const int sides = 6; 
};

#endif 