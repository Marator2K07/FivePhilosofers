
#include "fork.h"

Fork::Fork(QString name,
           QString color,
           QObject *parent)
    : QObject{parent}
    , name{name}
    , color{color}
{
    graphicsItem = new GraphicsForkItem(name, color);
}

GraphicsForkItem *Fork::getGraphicsItem()
{
    return graphicsItem;
}

void Fork::slotTake(QString color)
{
    graphicsItem->setTakeColor(color);
}

void Fork::slotPut()
{
    graphicsItem->setDropColor();
}

