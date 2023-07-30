
#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "fork.h"
#include "philosofergraphics.h"

#include <QObject>
#include <QMutex>
#include <QList>
#include <QRandomGenerator>

class Philosopher : public QObject
{
    Q_OBJECT

private:
    QString name;
    QString color;
    Fork *leftFork; // вилка на столе слева от философа
    Fork *rightFork; // вилка на столе справа от философа
    QMutex *leftMutex;
    QMutex *rightMutex;
    PhilosoferGraphics *graphics; // графическое схематическое представление философа

public:
    explicit Philosopher(Fork *forkLeft,
                         Fork *forkRight,
                         QMutex *leftMutex,
                         QMutex *rightMutex,
                         QString name,
                         QString color);
    const Fork* getLeftFork();
    const Fork* getRightFork();
    const QString getColor();
    PhilosoferGraphics *getGraphics();

signals:
    void takeLeftFork(QString color);
    void putLeftFork();
    void takeRightFork(QString color);
    void putRightFork();
    void changeStatus(QString statusText,
                      QString fullText,
                      QString borderColor);

public slots:
    ///
    /// \brief taskExecution
    /// основной метод выполнения поставленной задачи
    void taskExecution();
};

#endif // PHILOSOPHER_H
