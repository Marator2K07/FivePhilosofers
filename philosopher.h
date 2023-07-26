
#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "fork.h"

#include <QWidget>
#include <QThread>
#include <QList>

class Philosopher : public QThread
{
    Q_OBJECT
private:
    Fork leftFork; // вилка на столе слева от философа
    Fork rightFork; // вилка на столке справа от философа

public:
    explicit Philosopher(Fork forkFirst,
                         Fork forkSecond,
                         QThread *parent = nullptr);

signals:

public slots:

    // QThread interface
protected:
    void run() override;
};

#endif // PHILOSOPHER_H
