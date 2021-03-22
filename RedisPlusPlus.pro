TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    RedisRepo.cpp


INCLUDEPATH += /usr/local/include \
               `pkg-config --cflags opencv`
LIBS += -L/usr/local/lib -lhiredis -lredis++ -pthread \
        `pkg-config --libs opencv`

HEADERS += \
    RedisRepo.h


