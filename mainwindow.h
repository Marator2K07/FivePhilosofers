
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QList>

class MainWindow : public QMainWindow

{
    Q_OBJECT
private:
    const int forksCount = 5;
    QList<QMutex*>* forks; // вилки, которыми пытаются есть философы
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
