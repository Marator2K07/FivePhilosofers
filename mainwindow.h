
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fork.h"
#include "philosopher.h"
#include "presentation.h"

#include <QWidget>
#include <QList>
#include <QString>
#include <QTextEdit>
#include <QVBoxLayout>

class MainWindow : public QWidget

{
    Q_OBJECT
private:
    const int сount = 5;
    QList<Fork*> initialForks; // вилки, которыми пытаются есть философы
    QList<Philosopher*> initialPhilosofers; // сами философы

public:
    MainWindow(QWidget *parent = nullptr);    
    ///
    /// \brief startEating
    /// Метод начала работы всех потоков задания
    ///
    void startEating();
    ~MainWindow();
};

#endif // MAINWINDOW_H
