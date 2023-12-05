#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QPixmap>


//constructor Main Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;

}



void MainWindow::on_lineButton_clicked()
{
    for(int i = 0; i < 50; ++i){
        scene->addLine(i,10,i,10);

    }
}


void MainWindow::on_clearaButton_clicked()
{
    scene->clear();

}

void MainWindow::on_rectangelButton_clicked()
{
    scene->addRect(-60,60,110,110);
}

void MainWindow::on_testButton_clicked()
{
    QWidget *wdg = new QWidget;
    wdg->show();

    close();
}



































