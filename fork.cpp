
#include "fork.h"

Fork::Fork(QString name,
           QString color,
           QWidget *parent)
    : QWidget{parent}
    , name{name}
    , color{color}
{
    graphicsItem = new GraphicsForkItem(name, color);
}

GraphicsForkItem *Fork::getGraphicsItem()
{
    return graphicsItem;
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

