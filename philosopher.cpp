
#include "philosopher.h"

Philosopher::Philosopher(Fork forkFirst,
                         Fork forkSecond,
                         QThread *parent)
    : QThread{parent}
{
    leftFork = forkFirst;
    rightFork = forkSecond;
}

void Philosopher::run()
{

}

