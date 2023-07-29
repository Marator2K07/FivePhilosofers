
#ifndef PHILOSOFERGRAPHICS_H
#define PHILOSOFERGRAPHICS_H

#include "graphicsphilosoferitem.h"

#include <QObject>
#include <QThread>

class PhilosoferGraphics : public QObject
{
    Q_OBJECT
private:
    GraphicsPhilosoferItem *item;

public:
    explicit PhilosoferGraphics(QString name,
                                QString color);
    GraphicsPhilosoferItem *getItem();

signals:
    ///
    /// \brief showInfoInLog сигнал показа деталей происходящих
    /// операций в текстовом поле виджета
    /// \param text текст для показа
    void showInfoInLog(const QString);

public slots:
    void slotChangeStatus(QString statusText,
                          QString fullText,
                          QString borderColor);
};

#endif // PHILOSOFERGRAPHICS_H
