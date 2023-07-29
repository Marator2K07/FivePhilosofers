
#ifndef FORK_H
#define FORK_H

#include "graphicsforkitem.h"

#include <QWidget>
#include <QMutex>

class Fork : public QWidget
{
    Q_OBJECT
private:
    QString name;
    QString color;
    QMutex locker;
    GraphicsForkItem *graphicsItem; // условное графическое представление вилки на столе

public:
    explicit Fork(QString name,
                  QString color,
                  QWidget *parent = nullptr);
    GraphicsForkItem *getGraphicsItem();

private slots:
    void slotLock();
    void slotUnlock();
};

#endif // FORK_H
