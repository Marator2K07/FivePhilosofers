
#include "philosopher.h"

Philosopher::Philosopher(Fork *forkFirst,
                         Fork *forkSecond,
                         QString name,
                         QString colorText)
    : leftFork{forkFirst}
    , rightFork{forkSecond}
    , name{name}
    , colorText{colorText}
{
    graphics = new PhilosoferGraphics(name, colorText);
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
    return colorText;
}

PhilosoferGraphics *Philosopher::getGraphics()
{
    return graphics;
}

void Philosopher::taskExecution()
{
    emit changeStatus("Сел за стол",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> садится за стол с едой;")
                          .arg(colorText, name),
                      "grey");
    int time = QRandomGenerator::global()->bounded(1,5000);
    QThread::msleep(QRandomGenerator::global()->bounded(1,5000));
    emit changeStatus("Начинает размышлять",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> "
                          "начинает размышлять %3 миллисекунд;")
                          .arg(colorText, name).arg(time),
                      "black");
    QThread::msleep(time);
    emit changeStatus("Закончил размышлять",
                      QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил размышлять;")
                          .arg(colorText, name),
                      "grey");
    emit takeLeftFork();

    //while(true) {
    //}
}


