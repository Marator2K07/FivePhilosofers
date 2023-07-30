
#ifndef GRAPHICSFORKITEM_H
#define GRAPHICSFORKITEM_H

#include <QGraphicsLineItem>
#include <QPen>

class GraphicsForkItem : public QGraphicsLineItem
{
private:
    QString name;
    QString dropColor;
    int width = 11; // ширина линии

public:
    GraphicsForkItem(QString name,
                     QString dropColor = "black");
    void setTakeColor(QString color);
    void setDropColor();
};

#endif // GRAPHICSFORKITEM_H
