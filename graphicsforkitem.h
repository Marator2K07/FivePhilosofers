
#ifndef GRAPHICSFORKITEM_H
#define GRAPHICSFORKITEM_H

#include <QGraphicsLineItem>
#include <QPen>

class GraphicsForkItem : public QGraphicsLineItem
{
private:
    QString name;
    QString takeColor;
    QString dropColor;
    int width = 12; // ширина линии

public:
    GraphicsForkItem(QString name,
                     QString takeColor,
                     QString dropColor = "black");
    void setTakeColor();
    void setDropColor();
};

#endif // GRAPHICSFORKITEM_H
