
#include "graphicsphilosoferitem.h"

GraphicsPhilosoferItem::GraphicsPhilosoferItem(QString name,
                                               QString color)
    : color{color}
    , name{name}
{
    // инициализируем цвет границы и цвет заливки для этого элемента
    setPen(QPen(Qt::black, 5));
    setBrush(QBrush(QColor(color)));
}

