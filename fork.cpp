
#include "fork.h"

Fork::Fork(QWidget *parent)
    : QWidget{parent}
{
}

void Fork::slotLock()
{
    locker.lock();
}

void Fork::slotUnlock()
{
    locker.unlock();
}

