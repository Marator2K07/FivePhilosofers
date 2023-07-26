
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
    Fork *leftFork; // вилка на столе слева от философа
    Fork *rightFork; // вилка на столке справа от философа

public:
    explicit Philosopher(Fork *forkFirst,
                         Fork *forkSecond);
    const Fork* getLeftFork();
    const Fork* getRightFork();

signals:
    void takeLeftFork();
    void putLeftFork();
    void takeRightFork();
    void putRightFork();
    ///
    /// \brief showInfo
    /// сигнал показа деталей происходящих операций в текстовом поле виджета
    /// \param text
    /// текст для показа
    ///
    void showInfo(QString);

    // QThread interface
protected:
    void run() override;
};

#endif // PHILOSOPHER_H
