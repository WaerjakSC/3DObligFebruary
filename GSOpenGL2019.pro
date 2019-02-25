QT          += core gui widgets

TEMPLATE    = app
CONFIG      += c++11

TARGET      = 3D-programmering

SOURCES += main.cpp \
    renderwindow.cpp \
    shader.cpp \
    mainwindow.cpp \
    vector3d.cpp \
    vector4d.cpp \
    matrix4x4.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp \
    trianglesurface.cpp \
    cube.cpp \
    camera.cpp \
    interactiveobject.cpp \
    octahedronball.cpp \
    sceneone.cpp \
    slidergroup.cpp \
    qdoubleslider.cpp \
    scenetwo.cpp \
    door.cpp

HEADERS += \
    renderwindow.h \
    shader.h \
    mainwindow.h \
    vector3d.h \
    vector4d.h \
    matrix4x4.h \
    vertex.h \
    visualobject.h \
    xyz.h \
    trianglesurface.h \
    cube.h \
    camera.h \
    interactiveobject.h \
    octahedronball.h \
    sceneone.h \
    slidergroup.h \
    qdoubleslider.h \
    scenetwo.h \
    door.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    plainfragment.frag \
    plainvertex.vert
