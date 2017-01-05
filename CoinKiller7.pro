#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T21:23:38
#
#-------------------------------------------------

QT       += core gui\
            xml\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinKiller
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    sarcfilesystem.cpp \
    externalfilesystem.cpp \
    externalfile.cpp \
    memoryfile.cpp \
    filebase.cpp \
    leveleditorwindow.cpp \
    levelview.cpp \
    ctpk.cpp \
    sillytest.cpp \
    level.cpp \
    tileset.cpp \
    game.cpp \
    objects.cpp \
    unitsconvert.cpp \
    propertygrid.cpp \
    objectrenderer.cpp \
    tileseteditorwindow.cpp \
    tileseteditorwidgets.cpp \
    editionmode.cpp \
    spritedata.cpp \
    tilesetpalette.cpp \
    entranceeditorwidget.cpp \
    spriteeditorwidget.cpp \
    areaeditorwidget.cpp \
    zoneeditorwidget.cpp \
    locationeditorwidget.cpp \
    levelmanager.cpp \
    patheditorwidget.cpp \
    progresspatheditorwidget.cpp \
    settingsmanager.cpp \
    filedownloader.cpp \
    spriteimages.cpp

HEADERS  += mainwindow.h \
    filesystembase.h \
    filebase.h \
    sarcfilesystem.h \
    externalfilesystem.h \
    externalfile.h \
    shit.h \
    memoryfile.h \
    filesystem.h \
    leveleditorwindow.h \
    levelview.h \
    ctpk.h \
    sillytest.h \
    level.h \
    tileset.h \
    game.h \
    objects.h \
    unitsconvert.h \
    propertygrid.h \
    objectrenderer.h \
    tileseteditorwindow.h \
    tileseteditorwidgets.h \
    is.h \
    editionmode.h \
    spritedata.h \
    tilesetpalette.h \
    entranceeditorwidget.h \
    spriteeditorwidget.h \
    areaeditorwidget.h \
    zoneeditorwidget.h \
    levelmanager.h \
    patheditorwidget.h \
    progresspatheditorwidget.h \
    locationeditorwidget.h \
    settingsmanager.h \
    filedownloader.h \
    spriteimages.h

FORMS    += mainwindow.ui \
    leveleditorwindow.ui \
    tileseteditorwindow.ui

CONFIG += c++11

RC_FILE = TotallyNotTheIcon.rc

DISTFILES += \
    It's Green.ico \
    TotallyNotTheIcon.rc \
    It's Green.ico \
    TotallyNotTheIcon.rc \
    Sprite_Images.txt
