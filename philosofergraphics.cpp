
#include "philosofergraphics.h"

PhilosoferGraphics::PhilosoferGraphics(QString name,
                                       QString color)
{
    item = new GraphicsPhilosoferItem(name, color);
}

GraphicsPhilosoferItem* PhilosoferGraphics::getItem()
{
    return item;
}

void PhilosoferGraphics::slotChangeStatus(QString statusText,
                                          QString fullText,
                                          QString borderColor)
{
    // сначала меняем текст внутри графического представления философа
    // а потом и его границы для наглядности
    item->setStatusText(statusText);
    item->setPen(QPen(QColor(borderColor), 6));
    // этот слот далее вызывает сигнал показа уже полного текста статуса
    // в виджете для лога сообщений
    emit showInfoInLog(fullText);
}

