
#include "presentation.h"

Presentation::Presentation(QList<GraphicsPhilosoferItem *> *philosofersGraphItems,
                                                   QWidget *parent)
    :   philosofersGraphItems{philosofersGraphItems}
    ,   QWidget{parent}
{
    // самые начальные приготовления для сцены и вида
    view.setSceneRect(rect());
    view.setScene(&scene);
    view.setFixedSize(750, 550);
    // инициализируем данные для последующих расчетов
    qreal rotationForPhi = 0;
    int lenght = 180;
    qreal xThis = lenght;
    qreal yThis = 0;
    // а теперь рисую(добавляю) графические представления философов в виджет сцены
    for (GraphicsPhilosoferItem* item : *philosofersGraphItems) {
        // задаю размеры эллипса и добавляю его в коллекцию
        item->setRect(xThis, yThis, 90, 90);
        scene.addItem(item);
        item->setFlag(QGraphicsItem::ItemIsMovable);
        // делаю преобразования для прорисовки следующего итема на след. итерации!
        rotationForPhi += 72;
        xThis = lenght * cos(rotationForPhi*0.017);
        yThis = lenght * sin(rotationForPhi*0.017);
    }
    // layout settings
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(&view);
    this->setLayout(layout);
}


