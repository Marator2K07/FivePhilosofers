
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

private slots:
    void slotLock();
    void slotUnlock();
};

#endif // FORK_H
