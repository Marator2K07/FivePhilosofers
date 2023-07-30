
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

private:
    ///
    /// \brief preparation вынесена часть, носящая просто подготовительный,
    /// ознакомительный характер
    /// \param defaultPause значение паузы между сообщениями в миллисекундах
    void preparation(int defaultPause);
    ///
    /// \brief reflection метод с частью, где философ начинает и
    /// спустя какое то случаное время заканчивает свои размышления
    /// после какой-либо операции, успешной или нет
    /// \param time для определения и запоминания случайного значения
    /// длительности размышлений
    /// \param defaultPause значение паузы между сообщениями в миллисекундах
    void reflection(int *time,
                    int defaultPause);
    ///
    /// \brief eating часть, где философ успешно берет две вилки
    /// и начинает свою трапезу, заканчивает и убирает вилки на место
    /// \param time для определения и запоминания случайного значения
    /// длительности трапезы
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void eating(int *time,
                int defaultPause);
    ///
    /// \brief successfulUseLeftFork философ забирает левую вилку себе (помечает цветом)
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void successfulUseLeftFork(int defaultPause);
    ///
    /// \brief successfulUseRightFork философ забирает правую вилку себе (помечает цветом)
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void successfulUseRightFork(int defaultPause);
    ///
    /// \brief failedUseLeftFork оповещение пользователя о неудачности операции
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void failedUseLeftFork(int defaultPause);
    ///
    /// \brief failedUseRightFork оповещение пользователя о неудачности операции, но
    /// в условиях алгоритма, на этот раз, философ еще и сдается (кладет левую вилку обратно на стол)
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void failedUseRightFork(int defaultPause);
    ///
    /// \brief tryTakeLeftFork попытка взять (заблокировать) левую вилку
    /// \param blocked переменная для запоминания операции попытки блокировки
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void tryTakeLeftFork(bool *blocked,
                         int defaultPause);
    ///
    /// \brief tryTakeRightFork попытка взять (заблокировать) правую вилку
    /// \param blocked переменная для запоминания операции попытки блокировки
    /// \param defaultPause значение паузы между сообщениями в  миллисекундах
    void tryTakeRightFork(bool *blocked,
                          int defaultPause);

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
