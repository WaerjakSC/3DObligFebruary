#include "mainwindow.h"
#include "matrix4x4.h"
#include "vector3d.h"
#include "vector4d.h"
#include <QApplication>
#include <fstream>
#include <iostream>

using namespace jl;
int main(int argc, char *argv[])
{
    //    //    float arr[4][4]{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    //    Matrix4x4 test;
    //    std::cout << test << "\n";
    //    Vector3d v(1, 0, 0);
    //    test.rotate(v, -45);
    //    std::cout << test << "\n";

    //Forces the usage of desktop OpenGL
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes an Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    return a.exec();
}
