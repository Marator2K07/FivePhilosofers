
#include "graphicsphilosoferitem.h"

GraphicsPhilosoferItem::GraphicsPhilosoferItem(QString name,
                                               QString color)
    : color{color}
    , name{name}
{
    // инициализируем цвет границы и цвет заливки для этого элемента
    setPen(QPen(Qt::black, width));
    setBrush(QBrush(QColor(color)));
}

void GraphicsPhilosoferItem::statusInitialization()
{
    // сначала просто инициализация задание ширины для текста
    status = new GraphicsCenteredTextItem(this);
    status->setTextWidth(this->boundingRect().width() - width);
    // указание верной позиции
    QRectF parentRect = this->boundingRect();
    status->setPos(parentRect.topLeft().rx() + width/2,
                   parentRect.topLeft().ry() + width/2);
    // задание шрифта и его применение
    QFont sansFont("Helvetica [Cronyx]", 14);
    status->setFont(sansFont);
    status->setPlainText("...");
}

void GraphicsPhilosoferItem::setStatusText(const QString text)
{
    status->setPlainText(text);
}

