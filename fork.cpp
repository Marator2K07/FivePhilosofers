
#include "fork.h"

Fork::Fork(GraphicsForkItem *graphicsItem,
           QWidget *parent)
    : graphicsItem{graphicsItem}
    , QWidget{parent}
{
}

void Fork::slotLock()
{
    locker.lock();
    graphicsItem->setTakeColor();
}

void Fork::slotUnlock()
{
    locker.unlock();
}

