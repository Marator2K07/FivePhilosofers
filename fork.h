
#ifndef FORK_H
#define FORK_H

#include "graphicsforkitem.h"

#include <QWidget>
#include <QMutex>

class Fork : public QWidget
{
    Q_OBJECT
private:
    QMutex locker;
    GraphicsForkItem *graphicsItem; // условное графическое представление вилки на столе

public:
    explicit Fork(GraphicsForkItem *graphicsItem,
                  QWidget *parent = nullptr);

private slots:
    void slotLock();
    void slotUnlock();
};

#endif // FORK_H
