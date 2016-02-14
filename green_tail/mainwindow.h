#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gtserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void toConcole(QString);

private:
    Ui::MainWindow *ui;
    GTServer *gt;

    void prepareUi();

public slots:
    void clickStart();
    void clickStop();
    void newConnect();
};

#endif // MAINWINDOW_H
