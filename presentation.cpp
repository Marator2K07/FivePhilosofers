
#include "presentation.h"

Presentation::Presentation(QList<GraphicsPhilosoferItem *> *philosofersGraphItems,
                           QList<GraphicsForkItem *> *forksGraphItems,
                           QWidget *parent)
    : philosofersGraphItems{philosofersGraphItems}
    , forksGraphItems{forksGraphItems}
    , QWidget{parent}
{
    // самые начальные приготовления для сцены и вида
    view.setSceneRect(rect());
    view.setScene(&scene);
    view.setFixedSize(760, 500);
    // добавляем схематический стол, вокруг корого сидят философы
    scene.addEllipse(QRect(-80, -80, 250, 250),
                     QPen(Qt::black, 5),
                     QBrush(QColor(Qt::white)));
    // инициализируем данные для последующих расчетов
    double toRadiansFactor = 0.017;
    qreal rotation = 0;
    int lenght = 180;
    int lenghtL = 60;
    qreal xBegin = lenght;
    qreal yBegin = 0;
    // а теперь рисую(добавляю) графические представления философов в виджет сцены
    for (GraphicsPhilosoferItem* item : *philosofersGraphItems) {
        // задаю размеры эллипса и добавляю его в коллекцию
        item->setRect(xBegin, yBegin, 90, 90);
        item->statusInitialization(); // т.к. координаты мы указали только строчкой выше, то поставить статус можем только сейчас!
        scene.addItem(item);
        // делаю преобразования для прорисовки следующего итема на след. итерации!
        rotation += 72;
        xBegin = lenght * cos(rotation * toRadiansFactor);
        yBegin = lenght * sin(rotation * toRadiansFactor);
    }
    // добавляем новые данные/переинициализируем старые для последующих расчетов
    int shift = 45;
    rotation = 36;
    xBegin = lenghtL * cos(rotation * toRadiansFactor);
    yBegin = lenghtL * sin(rotation * toRadiansFactor);
    qreal xEnd = lenght * cos(rotation * toRadiansFactor);
    qreal yEnd = lenght * sin(rotation * toRadiansFactor);
    // а теперь рисую(добавляю) графические представления вилок в виджет сцены
    for (GraphicsForkItem* item : *forksGraphItems) {
        // задаю размеры эллипса и добавляю его в коллекцию
        item->setLine(xBegin + shift,
                      yBegin + shift,
                      xEnd + shift,
                      yEnd + shift);
        scene.addItem(item);
        item->setFlag(QGraphicsItem::ItemIsMovable);
        // делаю преобразования для прорисовки следующего итема на след. итерации!
        rotation += 72;
        xBegin = lenghtL * cos(rotation * toRadiansFactor);
        yBegin = lenghtL * sin(rotation * toRadiansFactor);
        xEnd = lenght * cos(rotation * toRadiansFactor);
        yEnd = lenght * sin(rotation * toRadiansFactor);
    }
    // layout settings
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(&view);
    this->setLayout(layout);
}


