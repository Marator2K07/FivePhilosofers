
#include "philosopher.h"

Philosopher::Philosopher(Fork *forkFirst,
                         Fork *forkSecond,
                         QString name,
                         QString colorText,
                         GraphicsPhilosoferItem* graphicsItem)
    : leftFork{forkFirst}
    , rightFork{forkSecond}
    , name{name}
    , colorText{colorText}
    , graphicsItem{graphicsItem}
{
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

void Philosopher::run()
{    
    quint32 time = QRandomGenerator::global()->bounded(1,5000);
    emit showInfo(QString("Философ <font color=\"%1\" size=\"4\">%2</font> садится за стол с едой и "
                          "начинает размышлять %3 миллисекунд;")
                      .arg(colorText)
                      .arg(name)
                      .arg(time));
    msleep(time);
    emit showInfo(QString("Философ <font color=\"%1\" size=\"4\">%2</font> закончил размышлять;")
                      .arg(colorText)
                      .arg(name));
    while(true) {

    }
}

