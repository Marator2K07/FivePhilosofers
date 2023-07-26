
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // инициализируем коллекцию вилок, а потом и каждую из пяти штук
    forks = new QList<QMutex*>();
    for (int i= 0; i < forksCount; ++i) {
        forks->append(new QMutex());
    }
}

MainWindow::~MainWindow()
{
}


