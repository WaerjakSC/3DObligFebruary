#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "camera.h"
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>
#include <vector>
class QWidget;
class RenderWindow;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateLabelMatrix();

private:
    void init();
    Ui::MainWindow *ui;

    std::vector<QLabel *> matrixLabels;
    QGroupBox *createMatrix(Camera *cam);

    QWidget *mRenderWindowContainer;
    RenderWindow *mRenderWindow;
};

#endif // MAINWINDOW_H
