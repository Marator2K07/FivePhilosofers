
#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "fork.h"
#include "graphicsphilosoferitem.h"

#include <QThread>
#include <QList>
#include <QRandomGenerator>

class Philosopher : public QThread
{
    Q_OBJECT

private:
    QString name; // для идентификации среди других философов
    QString colorText; // цвет текста в инфо поле для большей наглядности
    Fork *leftFork; // вилка на столе слева от философа
    Fork *rightFork; // вилка на столке справа от философа
    GraphicsPhilosoferItem *graphicsItem; // условное графическое представление философа

public:
    explicit Philosopher(Fork *forkFirst,
                         Fork *forkSecond,
                         QString name,
                         QString colorText,
                         GraphicsPhilosoferItem* graphicsItem);
    const Fork* getLeftFork();
    const Fork* getRightFork();
    const QString getColor();

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
    void showInfo(const QString);

    // QThread interface
protected:
    void run() override;
};

#endif // PHILOSOPHER_H
