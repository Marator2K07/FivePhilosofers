QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fork.cpp \
    graphicscenteredtextitem.cpp \
    graphicsforkitem.cpp \
    graphicsphilosoferitem.cpp \
    main.cpp \
    mainwindow.cpp \
    philosofergraphics.cpp \
    philosopher.cpp \
    presentation.cpp

HEADERS += \
    fork.h \
    graphicscenteredtextitem.h \
    graphicsforkitem.h \
    graphicsphilosoferitem.h \
    mainwindow.h \
    philosofergraphics.h \
    philosopher.h \
    presentation.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
