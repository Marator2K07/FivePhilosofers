
#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "philosopher.h"

#include <QList>
#include <QWidget>
#include <QRect>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>

class Presentation : public QWidget
{
    Q_OBJECT
private:
    QList<GraphicsPhilosoferItem *> *philosofersGraphItems;
    QList<GraphicsForkItem *> *forksGraphItems;
    QGraphicsScene scene;
    QGraphicsView view;
    QString color;

public:
    explicit Presentation(QList<GraphicsPhilosoferItem *> *philosofersGraphItems,
                          QList<GraphicsForkItem *> *forksGraphItems,
                          QWidget *parent = nullptr);

public slots:
    //void slotRepaint();
};

#endif // PRESENTATION_H
