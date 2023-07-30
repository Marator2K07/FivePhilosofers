
#include "philosopher.h"

void Philosopher::preparation(int defaultPause)
{
    emit changeStatus("Сел за стол",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> садится за стол с едой;")
                          .arg(color, name),
                      "grey");
    QThread::msleep(defaultPause);
}

void Philosopher::reflection(int *time,
                             int defaultPause)
{
    *time = QRandomGenerator::global()->bounded(1000,5000);
    emit changeStatus("Начинает размышлять",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                              "начинает размышлять %3 миллисекунд;")
                          .arg(color, name).arg(*time),
                      "black");
    QThread::msleep(*time);
    emit changeStatus("Закончил размышлять",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил размышлять;")
                          .arg(color, name),
                      "grey");
    QThread::msleep(defaultPause);
}

void Philosopher::eating(int *time,
                         int defaultPause)
{
    *time = QRandomGenerator::global()->bounded(1,5000);
    emit changeStatus("Начинает принимать пищу",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                              "принимается за трепазу длительностью %3 миллисекунд;")
                          .arg(color, name).arg(*time),
                      "darkviolet");
    QThread::msleep(*time);
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
    emit putLeftFork();
    leftMutex->unlock();
}

void Philosopher::successfulUseLeftFork(int defaultPause)
{
    emit takeLeftFork(color);
    emit changeStatus("Успешно взял левую вилку",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> успешно взял левую вилку;")
                          .arg(color, name),
                      "mediumslateblue");
    QThread::msleep(defaultPause);
}

void Philosopher::successfulUseRightFork(int defaultPause)
{
    emit takeRightFork(color);
    emit changeStatus("Успешно взял правую вилку",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> успешно взял правую вилку;")
                          .arg(color, name),
                      "mediumslateblue");
    QThread::msleep(defaultPause);
}

void Philosopher::failedUseLeftFork(int defaultPause)
{
    emit changeStatus("Не смог взять левую вилку",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> не смог взять левую вилку;")
                          .arg(color, name),
                      "grey");
    QThread::msleep(defaultPause);
}

void Philosopher::failedUseRightFork(int defaultPause)
{
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
    emit putLeftFork();
    leftMutex->unlock();
}

void Philosopher::tryTakeLeftFork(bool *blocked,
                                  int defaultPause)
{
    emit changeStatus("Пытается взять левую вилку",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> пытается взять левую вилку;")
                          .arg(color, name),
                      "grey");
    QThread::msleep(defaultPause);
    *blocked = leftMutex->try_lock();
}

void Philosopher::tryTakeRightFork(bool *blocked,
                                   int defaultPause)
{
    emit changeStatus("Пытается взять правую вилку",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> пытается взять правую вилку;")
                          .arg(color, name),
                      "grey");
    QThread::msleep(defaultPause);
    *blocked = rightMutex->try_lock();
}

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
    , stoped{false}
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
    preparation(defaultPause);
    // прелюдия закончилась, теперь начинается основное действие
    while(!stoped) {
        reflection(&time, defaultPause);
        tryTakeLeftFork(&blocked, defaultPause);
        // если левая вилка была доступна - мы ее взяли и заблокировали мьютексом
        if (blocked) {
            successfulUseLeftFork(defaultPause);
            reflection(&time, defaultPause);
            tryTakeRightFork(&blocked, defaultPause);
            // теперь если правая вилка доступна, то мы ее берем и блокируем доступ другим потокам
            if (blocked) {
                successfulUseRightFork(defaultPause);
                eating(&time, defaultPause); // употребление пищи и уборка столовых приборов (разблокировка мьютексов)
            }
            // в случае неудачной попытки взять правую вилку, философ сдается и кладет левую вилку
            // чтобы не мешать другими и как лишняя страховка против дедлоков
            else {
                failedUseRightFork(defaultPause);
            }
        }
        // в случае неудачной попытки взять левую вилку, то философ просто продолжает
        // дальше размышлять
        else {
            failedUseLeftFork(defaultPause);
        }
    }
}

void Philosopher::stop()
{
    stoped = true;
}


