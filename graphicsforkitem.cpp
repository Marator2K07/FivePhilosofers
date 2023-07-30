
#include "graphicsforkitem.h"

GraphicsForkItem::GraphicsForkItem(QString name,
                                   QString dropColor)
    : name{name}
    , dropColor{dropColor}
{
    setDropColor();
}

void GraphicsForkItem::setTakeColor(QString color)
{
    setPen(QPen(QColor(color), width));
}

void GraphicsForkItem::setDropColor()
{
    setPen(QPen(QColor(dropColor), width));
}

