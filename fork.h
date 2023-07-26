
#ifndef FORK_H
#define FORK_H

#include <QWidget>
#include <QMutex>

class Fork : public QWidget
{
    Q_OBJECT
private:
    QMutex locker;
public:
    explicit Fork(QWidget *parent = nullptr);

signals:
    void taken(); // сигнал поднятия вилки со стола
    void put(); // сигнал опускания вилки на стол

private slots:
    void slotLock();
    void slotUnlock();
};

#endif // FORK_H
