
#include "philosopher.h"

Philosopher::Philosopher(Fork *forkFirst,
                         Fork *forkSecond)
    : leftFork{forkFirst}
    , rightFork{forkSecond}
{
}

const Fork *Philosopher::getLeftFork()
{
    return leftFork;
}

const Fork *Philosopher::getRightFork()
{
    return rightFork;
}

void Philosopher::run()
{

}

