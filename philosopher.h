
#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "fork.h"
#include "philosofergraphics.h"

#include <QObject>
#include <QList>
#include <QRandomGenerator>

class Philosopher : public QObject
{
    Q_OBJECT

private:
    QString name;
    QString colorText;
    Fork *leftFork; // вилка на столе слева от философа
    Fork *rightFork; // вилка на столе справа от философа
    PhilosoferGraphics *graphics; // графическое схематическое представление философа

public:
    explicit Philosopher(Fork *forkFirst,
                         Fork *forkSecond,
                         QString name,
                         QString colorText);
    const Fork* getLeftFork();
    const Fork* getRightFork();
    const QString getColor();
    PhilosoferGraphics *getGraphics();

signals:
    void takeLeftFork();
    void putLeftFork();
    void takeRightFork();
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
