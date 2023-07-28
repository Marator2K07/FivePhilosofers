
#include "graphicsforkitem.h"

GraphicsForkItem::GraphicsForkItem(QString name,
                                   QString takeColor,
                                   QString dropColor)
    : name{name}
    , takeColor{takeColor}
    , dropColor{dropColor}
{
    setDropColor();
}

void GraphicsForkItem::setTakeColor()
{
    setPen(QPen(QColor(takeColor), width));
}

void GraphicsForkItem::setDropColor()
{
    setPen(QPen(QColor(dropColor), width));
}

