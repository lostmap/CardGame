#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _interLayer(nullptr)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->chatPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInterLayer(InterLayer* interLayer)
{
    _interLayer = interLayer;
}


void MainWindow::on_pushButton_clicked()
{
    _interLayer->sendPass();
}

void MainWindow::on_pushButton_2_clicked()
{
    _interLayer->sendStart();
}

void MainWindow::clear()
{
    ui->roomTextEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString message = ui->sayLineEdit->text().trimmed();
    if(!message.isEmpty())
    {
        _interLayer->sendCard(message.toInt());
    }

    ui->sayLineEdit->clear();
    ui->sayLineEdit->setFocus();
}

void MainWindow::append(QString data)
{
    ui->roomTextEdit->append(data);
}

void MainWindow::insertPlainText(QString data)
{
    ui->roomTextEdit->insertPlainText(data);
}
