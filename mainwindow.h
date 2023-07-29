
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fork.h"
#include "philosopher.h"
#include "presentation.h"

#include <QThread>
#include <QWidget>
#include <QList>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QApplication>

class MainWindow : public QWidget

{
    Q_OBJECT
private:
    const int сount = 5;
    QList<Fork *> forks; // вилки, которыми пытаются есть философы
    QList<Philosopher *> philosofers; // сами философы
    QList<QThread *> philosofersThreads; // потоки для работы философов

public:
    MainWindow(QWidget *parent = nullptr);    
    ~MainWindow();
};

#endif // MAINWINDOW_H
