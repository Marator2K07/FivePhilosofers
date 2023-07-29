
#ifndef GRAPHICSPHILOSOFERITEM_H
#define GRAPHICSPHILOSOFERITEM_H

#include "graphicscenteredtextitem.h"

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

class GraphicsPhilosoferItem : public QGraphicsEllipseItem
{
private:
    QString name;
    QString color;
    int width = 6; // ширина линии обводки(QPen)
    GraphicsCenteredTextItem *status; // текст статуса выполняемой задачи у философа

public:
    GraphicsPhilosoferItem(QString name,
                           QString color);
    ///
    /// \brief statusInitialization
    /// т.к. не все данные для инициализации известны заранее
    /// выносим метод отдельно и вызываем уже после определенных
    /// условий
    ///
    void statusInitialization();
    void setStatusText(const QString text);
};

#endif // GRAPHICSPHILOSOFERITEM_H
