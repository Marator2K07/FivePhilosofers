
#include "fork.h"

Fork::Fork(QWidget *parent)
    : QWidget{parent}
{
}

void Fork::slotLock()
{
    locker.try_lock();
}

void Fork::slotUnlock()
{
    locker.unlock();
}

