QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db_manager.cpp \
    main.cpp \
    login.cpp \
    model/movie.cpp \
    model/moviedto.cpp \
    movie/addmovie.cpp \
    movie/editmovie.cpp \
    welcom.cpp

HEADERS += \
    db_manager.h \
    login.h \
    model/movie.h \
    model/moviedto.h \
    movie/addmovie.h \
    movie/editmovie.h \
    welcom.h

FORMS += \
    login.ui \
    movie/addmovie.ui \
    movie/editmovie.ui \
    welcom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
