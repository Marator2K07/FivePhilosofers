
#ifndef GRAPHICSCENTEREDTEXTITEM_H
#define GRAPHICSCENTEREDTEXTITEM_H

#include <QGraphicsTextItem>
#include <QPainter>

///
/// \brief The GraphicsCenteredTextItem class
/// т.к. обычный класс не умеет выполнять центрирование текста
/// по вертикали, пришлось создавать свой, справляющийся с
/// данной задачей
///
class GraphicsCenteredTextItem : public QGraphicsTextItem
{
public:
    GraphicsCenteredTextItem(QGraphicsItem *parent);

    // QGraphicsItem interface
public:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // GRAPHICSCENTEREDTEXTITEM_H
