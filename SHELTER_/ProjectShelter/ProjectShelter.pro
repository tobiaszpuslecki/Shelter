TEMPLATE = app
TARGET = ProjectShelter

QT = core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    loginwindow.cpp \
    newanimalwindow.cpp \
    adoptionwindow.cpp \
    sqlcontroller.cpp \
    filtersearchwindow.cpp \
    manualmodewindow.cpp \
    ownerwindow.cpp \
    shelter.cpp

FORMS += \
    mainwindow.ui \
    loginwindow.ui \
    newanimalwindow.ui \
    adoptionwindow.ui \
    filtersearchwindow.ui \
    manualmodewindow.ui \
    ownerwindow.ui

HEADERS += \
    mainwindow.h \
    loginwindow.h \
    newanimalwindow.h \
    adoptionwindow.h \
    sqlcontroller.h \
    filtersearchwindow.h \
    manualmodewindow.h \
    ownerwindow.h \
    shelter.h


