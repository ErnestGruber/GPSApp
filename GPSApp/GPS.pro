greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui qml quick location positioning quickcontrols2 network

CONFIG += c++11

SOURCES += main.cpp \
    asd.cpp \
    gps.cpp \
    gpstrack.cpp \
    gpstrackstat.cpp \
    storagemodel.cpp \
    filesystemmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    asd.h \
    gps.h \
    gpstrack.h \
    gpstrackstat.h \
    storagemodel.h \
    filesystemmodel.h

DISTFILES +=

FORMS += \
    asd.ui \
    gps.ui
