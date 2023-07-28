
#include "graphicscenteredtextitem.h"

GraphicsCenteredTextItem::GraphicsCenteredTextItem(QGraphicsItem *parent)
    : QGraphicsTextItem{parent}
{
}

void GraphicsCenteredTextItem::paint(QPainter *painter,
                                     const QStyleOptionGraphicsItem *option,
                                     QWidget *widget)
{
    // рисуем белым цветом отцентрированный текст
    painter->setPen(Qt::white);
    painter->drawText(boundingRect(),
                      toPlainText(),
                      Qt::AlignHCenter | Qt::AlignVCenter);
}

