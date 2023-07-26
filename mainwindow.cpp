
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // инициализируем коллекцию вилок, а потом и каждую из пяти штук
    for (int i= 0; i < сount; ++i) {
        initialForks.append(new Fork());
    }
    // теперь инициализируем и философов, каждому даем по потенциально доступной вилке
    initialPhilosofers.append(new Philosopher(initialForks.value(0),
                                              initialForks.value(1)));
    initialPhilosofers.append(new Philosopher(initialForks.value(1),
                                              initialForks.value(2)));
    initialPhilosofers.append(new Philosopher(initialForks.value(2),
                                              initialForks.value(3)));
    initialPhilosofers.append(new Philosopher(initialForks.value(3),
                                              initialForks.value(4)));
    initialPhilosofers.append(new Philosopher(initialForks.value(4),
                                              initialForks.value(0)));
    // текстовое поле для вывода информационных сообщений
    QTextEdit *p_textInfo = new QTextEdit();
    p_textInfo->setReadOnly(true);
    // для каждого из философов проставляем сигнально-слотовые соединения
    for (int i = 0; i < сount; ++i) {
        QObject::connect(initialPhilosofers.value(i),
                         SIGNAL(takeLeftFork()),
                         initialPhilosofers.value(i)->getLeftFork(),
                         SLOT(slotLock()));
        QObject::connect(initialPhilosofers.value(i),
                         SIGNAL(putLeftFork()),
                         initialPhilosofers.value(i)->getLeftFork(),
                         SLOT(slotUnlock()));
        QObject::connect(initialPhilosofers.value(i),
                         SIGNAL(takeRightFork()),
                         initialPhilosofers.value(i)->getLeftFork(),
                         SLOT(slotLock()));
        QObject::connect(initialPhilosofers.value(i),
                         SIGNAL(putRightFork()),
                         initialPhilosofers.value(i)->getLeftFork(),
                         SLOT(slotUnlock()));
        QObject::connect(initialPhilosofers.value(i),
                         SIGNAL(showInfo(QString)),
                         p_textInfo,
                         SLOT(append(QString)));
    }
    // layout settings
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(p_textInfo);
    setLayout(layout);
}

void MainWindow::startEating()
{
    emit initialPhilosofers.value(0)->showInfo("Testing");
}

MainWindow::~MainWindow()
{
}


