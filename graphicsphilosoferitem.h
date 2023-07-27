
#ifndef GRAPHICSPHILOSOFERITEM_H
#define GRAPHICSPHILOSOFERITEM_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

class GraphicsPhilosoferItem : public QGraphicsEllipseItem
{
private:
    QString name;
    QString color;
public:
    GraphicsPhilosoferItem(QString name,
                           QString color);
};

#endif // GRAPHICSPHILOSOFERITEM_H
