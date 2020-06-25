
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
Game* game;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    game = new Game();
    game->show();
    this->setCentralWidget(game);

}


void MainWindow::on_pushButton_2_clicked()
{
    QApplication::exit();
}
