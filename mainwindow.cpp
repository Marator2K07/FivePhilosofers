
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // инициализируев блокировки
    for (int i = 0; i < сount; ++i) {
        mutexes.append(new QMutex);
    }
    // инициализируем коллекцию вилок
    forks.append(new Fork("fork1","black",this));
    forks.append(new Fork("fork2","black",this));
    forks.append(new Fork("fork3","black",this));
    forks.append(new Fork("fork4","black",this));
    forks.append(new Fork("fork5","black",this));
    // теперь инициализируем и философов, каждому даем по потенциально доступной вилке
    philosofers.append(new Philosopher(forks.value(0), forks.value(4),
                                       mutexes.value(0), mutexes.value(4),
                                       "Epikur", "green"));
    philosofers.append(new Philosopher(forks.value(1), forks.value(0),
                                       mutexes.value(1), mutexes.value(0),
                                       "Aristotel", "sandybrown"));
    philosofers.append(new Philosopher(forks.value(2), forks.value(1),
                                       mutexes.value(2), mutexes.value(1),
                                       "Platon", "red"));
    philosofers.append(new Philosopher(forks.value(3), forks.value(2),
                                       mutexes.value(3), mutexes.value(2),
                                       "Sokrat", "blue"));
    philosofers.append(new Philosopher(forks.value(4), forks.value(3),
                                       mutexes.value(4), mutexes.value(3),
                                       "Pifagor", "rosybrown"));

    // текстовое поле для вывода информационных сообщений (лог)
    QTextEdit *p_textInfo = new QTextEdit();
    p_textInfo->setReadOnly(true);
    p_textInfo->setStyleSheet("QTextEdit {background-color : Gainsboro}");
    // для каждого из философов проставляем сигнально-слотовые соединения
    for (int i = 0; i < сount; ++i) {
        connect(philosofers.value(i), SIGNAL(takeLeftFork(QString)),
                philosofers.value(i)->getLeftFork(), SLOT(slotTake(QString)));
        connect(philosofers.value(i), SIGNAL(putLeftFork()),
                philosofers.value(i)->getLeftFork(), SLOT(slotPut()));
        connect(philosofers.value(i), SIGNAL(takeRightFork(QString)),
                philosofers.value(i)->getRightFork(), SLOT(slotTake(QString)));
        connect(philosofers.value(i), SIGNAL(putRightFork()),
                philosofers.value(i)->getRightFork(), SLOT(slotPut()));
        connect(philosofers.value(i)->getGraphics(), SIGNAL(showInfoInLog(QString)),
                p_textInfo, SLOT(append(QString)));
    }
    // создаем и инициализируем обьект графического представления задачи
    Presentation* presentation =
        new Presentation(new QList<GraphicsPhilosoferItem *>{
                             philosofers.value(0)->getGraphics()->getItem(),
                             philosofers.value(1)->getGraphics()->getItem(),
                             philosofers.value(2)->getGraphics()->getItem(),
                             philosofers.value(3)->getGraphics()->getItem(),
                             philosofers.value(4)->getGraphics()->getItem()
                         },
                         new QList<GraphicsForkItem *>{
                             forks.value(0)->getGraphicsItem(),
                             forks.value(1)->getGraphicsItem(),
                             forks.value(2)->getGraphicsItem(),
                             forks.value(3)->getGraphicsItem(),
                             forks.value(4)->getGraphicsItem()
                         },
                         this);
    // layout settings
    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addWidget(p_textInfo);
    layoutMain->addWidget(presentation);
    setLayout(layoutMain);
    setFixedSize(800, 800);

    // а теперь наконец-то запускаем потоки
    foreach (Philosopher *ph, philosofers) {
        QThread *thread = new QThread(this);
        connect(thread, SIGNAL(started()), ph, SLOT(taskExecution()));
        ph->moveToThread(thread);
        philosofersThreads.append(thread);
        thread->start();
    }
}

MainWindow::~MainWindow()
{
    // из основного потока даем команду остановиться запущенным потокам
    // не сразу конечно, а когда доделают итерацию
    foreach (Philosopher *ph, philosofers) {
        ph->stop();
    }
    // чтобы приложение закрывалось без исключений, надо каждый поток
    // плавно остановить
    foreach (QThread* thread, philosofersThreads) {
        thread->quit();
        thread->wait();
    }
}


