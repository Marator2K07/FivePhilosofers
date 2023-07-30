
#ifndef FORK_H
#define FORK_H

#include "graphicsforkitem.h"

#include <QObject>

class Fork : public QObject
{
    Q_OBJECT
private:
    QString name;
    QString color;
    GraphicsForkItem *graphicsItem; // условное графическое представление вилки на столе

public:
    explicit Fork(QString name,
                  QString color,
                  QObject *parent = nullptr);
    GraphicsForkItem *getGraphicsItem();
    bool isLocked();

private slots:
    void slotTake(QString color);
    void slotPut();
};

#endif // FORK_H
