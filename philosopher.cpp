
#include "philosopher.h"

Philosopher::Philosopher(Fork *forkLeft,
                         Fork *forkRight,
                         QMutex *leftMutex,
                         QMutex *rightMutex,
                         QString name,
                         QString color)
    : leftFork{forkLeft}
    , rightFork{forkRight}
    , leftMutex{leftMutex}
    , rightMutex{rightMutex}
    , name{name}
    , color{color}
{
    graphics = new PhilosoferGraphics(name, color);
    connect(this, SIGNAL(changeStatus(QString,QString,QString)),
            graphics, SLOT(slotChangeStatus(QString,QString,QString)));
}

const Fork *Philosopher::getLeftFork()
{
    return leftFork;
}

const Fork *Philosopher::getRightFork()
{
    return rightFork;
}

const QString Philosopher::getColor()
{
    return color;
}

PhilosoferGraphics *Philosopher::getGraphics()
{
    return graphics;
}

void Philosopher::taskExecution()
{
    bool blocked;
    int time;
    int defaultPause = 1111;
    // подготовительная часть
    emit changeStatus("Сел за стол",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> садится за стол с едой;")
                          .arg(color, name),
                      "grey");    
    QThread::msleep(defaultPause);
    // прелюдия закончилась, теперь начинается основное действие
    while(true) {
        time = QRandomGenerator::global()->bounded(1000,5000);
        emit changeStatus("Начинает размышлять",
                          QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                                  "начинает размышлять %3 миллисекунд;")
                              .arg(color, name).arg(time),
                          "black");
        QThread::msleep(time);
        emit changeStatus("Закончил размышлять",
                          QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил размышлять;")
                              .arg(color, name),
                          "grey");
        QThread::msleep(defaultPause);
        emit changeStatus("Пытается взять левую вилку",
                          QString("Философ <font color=\"%1\" size=\"4\">%2</font> пытается взять левую вилку;")
                              .arg(color, name),
                          "grey");
        QThread::msleep(time);
        blocked = leftMutex->try_lock();
        if (blocked) {
            emit takeLeftFork(color);
            emit changeStatus("Успешно взял левую вилку",
                              QString("Философ <font color=\"%1\" size=\"4\">%2</font> успешно взял левую вилку;")
                                  .arg(color, name),
                              "mediumslateblue");
            QThread::msleep(defaultPause);
            time = QRandomGenerator::global()->bounded(1000,5000);
            emit changeStatus("Начинает размышлять",
                              QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                                      "начинает размышлять %3 миллисекунд;")
                                  .arg(color, name).arg(time),
                              "black");
            QThread::msleep(time);
            emit changeStatus("Закончил размышлять",
                              QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил размышлять;")
                                  .arg(color, name),
                              "grey");
            QThread::msleep(defaultPause);
            emit changeStatus("Пытается взять правую вилку",
                              QString("Философ <font color=\"%1\" size=\"4\">%2</font> пытается взять правую вилку;")
                                  .arg(color, name),
                              "grey");
            QThread::msleep(time);
            blocked = rightMutex->try_lock();
            if (blocked) {
                emit takeRightFork(color);
                emit changeStatus("Успешно взял правую вилку",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> успешно взял правую вилку;")
                                      .arg(color, name),
                                  "mediumslateblue");
                QThread::msleep(defaultPause);
                time = QRandomGenerator::global()->bounded(1,5000);
                emit changeStatus("Начинает принимать пищу",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                                          "принимается за трепазу длительностью %3 миллисекунд;")
                                      .arg(color, name).arg(time),
                                  "darkviolet");
                QThread::msleep(time);
                emit changeStatus("Закончил принимать пищу",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил принимать пищу;")
                                      .arg(color, name),
                                  "grey");
                QThread::msleep(defaultPause);
                emit changeStatus("Кладет вилки на место.",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> кладет вилки на место;")
                                      .arg(color, name),
                                  "grey");
                QThread::msleep(defaultPause);
                emit putRightFork();
                rightMutex->unlock();
            }
            else {
                emit changeStatus("Не смог взять правую вилку",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> не смог взять правую вилку;")
                                      .arg(color, name),
                                  "grey");
                QThread::msleep(defaultPause);
                emit changeStatus("Кладет левую вилку обратно",
                                  QString("Философ <font color=\"%1\" size=\"4\">%2</font> сдается и кладет левую вилку обратно на стол;")
                                      .arg(color, name),
                                  "grey");
                QThread::msleep(defaultPause);
            }
            emit putLeftFork();
            leftMutex->unlock();
        }
        else {
            emit changeStatus("Не смог взять левую вилку",
                              QString("Философ <font color=\"%1\" size=\"4\">%2</font> не смог взять левую вилку;")
                                  .arg(color, name),
                              "grey");
            QThread::msleep(defaultPause);
        }

        //rightForkLocker.lock();
        //emit takeRightFork(color);
    }
}


