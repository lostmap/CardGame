#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"

startwindow::startwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);

    gameScreen = new MainWindow();

    connect(gameScreen, &MainWindow::firstScreen, this, &startwindow::show);
}

startwindow::~startwindow()
{
    delete ui;
}

void startwindow::on_play_clicked()
{

    gameScreen->show();
    this->close();
}


void startwindow::on_Quit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit", "Are you sure?", QMessageBox::No | QMessageBox::Yes);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "quit is not clicked";
    }
}

void startwindow::on_connect_clicked()
{

}
