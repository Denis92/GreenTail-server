#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    prepareUi();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gt;
}

void MainWindow::prepareUi(){
    gt = new GTServer;

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(clickStart()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(clickStop()));

    connect(gt, SIGNAL(signalNewConnect()), this, SLOT(newConnect()));
}

void MainWindow::clickStart(){
    toConcole("Starting...");
    if(gt->start()){
        toConcole("OK\n");
    }else{
        toConcole("FAILED\n");
    }
}

void MainWindow::clickStop(){
    gt->stop();
    toConcole("Stop\n");
}

void MainWindow::newConnect(){
    toConcole("New connect\n");
}

void MainWindow::toConcole(QString msg){
    ui->concoleBrowser->insertPlainText(msg);
}
