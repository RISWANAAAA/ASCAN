QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 release precompile_header
QMAKE_CXXFLAGS_RELEASE += -O3 -g0 -DNDEBUG

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddoctor.cpp \
    addlens.cpp \
    addpatient.cpp \
    buttons.cpp \
    calformula.cpp \
    currentdocpat.cpp \
    intkeypad.cpp \
    loaddoctor.cpp \
    main.cpp \
    mainwindow.cpp \
    textkeypad.cpp \
    viewdoc.cpp \
    viewpatient.cpp

HEADERS += \
    adddoctor.h \
    addlens.h \
    addpatient.h \
    buttons.h \
    calformula.h \
    currentdocpat.h \
    intkeypad.h \
    loaddoctor.h \
    mainwindow.h \
    textkeypad.h \
    viewdoc.h \
    viewpatient.h

FORMS += \
    adddoctor.ui \
    addlens.ui \
    addpatient.ui \
    buttons.ui \
    currentdocpat.ui \
    intkeypad.ui \
    loaddoctor.ui \
    mainwindow.ui \
    textkeypad.ui \
    viewdoc.ui \
    viewpatient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
