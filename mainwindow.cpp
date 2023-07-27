
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // инициализируем коллекцию вилок, а потом и каждую из пяти штук
    for (int i= 0; i < сount; ++i) {
        initialForks.append(new Fork());
    }
    // создаем и инициализируем схематические графические представления философов
    GraphicsPhilosoferItem* epikurGraphicsItem = new GraphicsPhilosoferItem("Epicur", "green");
    GraphicsPhilosoferItem* aristotelGraphicsItem = new GraphicsPhilosoferItem("Aristotel", "sandybrown");
    GraphicsPhilosoferItem* platonGraphicsItem = new GraphicsPhilosoferItem("Platon", "red");
    GraphicsPhilosoferItem* sokratGraphicsItem = new GraphicsPhilosoferItem("Sokrat", "blue");
    GraphicsPhilosoferItem* pifagorGraphicsItem = new GraphicsPhilosoferItem("Pifagor", "rosybrown");

    // теперь инициализируем и философов, каждому даем по потенциально доступной вилке
    initialPhilosofers.append(new Philosopher(initialForks.value(0),
                                              initialForks.value(1),
                                              "Epikur", "green",
                                              epikurGraphicsItem));
    initialPhilosofers.append(new Philosopher(initialForks.value(1),
                                              initialForks.value(2),
                                              "Aristotel", "sandybrown",
                                              aristotelGraphicsItem));
    initialPhilosofers.append(new Philosopher(initialForks.value(2),
                                              initialForks.value(3),
                                              "Platon", "red",
                                              platonGraphicsItem));
    initialPhilosofers.append(new Philosopher(initialForks.value(3),
                                              initialForks.value(4),
                                              "Sokrat", "blue",
                                              sokratGraphicsItem));
    initialPhilosofers.append(new Philosopher(initialForks.value(4),
                                              initialForks.value(0),
                                              "Pifagor", "rosybrown",
                                              pifagorGraphicsItem));
    // текстовое поле для вывода информационных сообщений
    QTextEdit *p_textInfo = new QTextEdit();
    p_textInfo->setReadOnly(true);
    p_textInfo->setStyleSheet("QTextEdit {background-color : Gainsboro}");
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

    Presentation* presentation =
        new Presentation(new QList<GraphicsPhilosoferItem *>{
                                         epikurGraphicsItem,
                                         aristotelGraphicsItem,
                                         platonGraphicsItem,
                                         sokratGraphicsItem,
                                         pifagorGraphicsItem
                                     }, this);

    // layout settings
    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addWidget(p_textInfo);
    layoutMain->addWidget(presentation);
    setLayout(layoutMain);

    setFixedSize(800, 700);
}

void MainWindow::startEating()
{
    emit initialPhilosofers.value(0)->showInfo("Testing");
    foreach (Philosopher* ph, initialPhilosofers) {
        ph->start();
    }
}

MainWindow::~MainWindow()
{
}


