#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qhoversensitivebutton.h"
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonSize = 100;
    scale = 50;
    xShift = 20;
    yShift = 520;
    offset = 20;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(0));
    int id = rand() % 100;

        QHoverSensitiveButton* btn = new QHoverSensitiveButton(this, id);

        qDebug() << btn->getId() << " written\n";
        btn->setText(QString::number(btn->getId()));
        btn->setGeometry(ui->pushButton->geometry());
        btn->show();
        //buttonList.append(btn);
        buttonHash[id] = btn;
        rearrangeButtons();
        connect(btn, SIGNAL(clicked()), btn,SLOT(del()));
        connect(btn, &QHoverSensitiveButton::clear, this, [=]() {this->Clear(btn->getId());});
}


void MainWindow::rearrangeButtons()
{
    //int buttonCount = buttonList.size();

    QHash<int, QHoverSensitiveButton*>::iterator iter;
    int cont = 0;
    for (iter = buttonHash.begin(); iter != buttonHash.end(); iter++) {
        QHoverSensitiveButton* btn = *iter;
        QPropertyAnimation* animation = new QPropertyAnimation(btn, "geometry");
        animation->setDuration(1000);
        qDebug() << cont << "\n";
        animation->setEasingCurve(QEasingCurve::InOutElastic);
        animation->setEndValue(QRectF(cont * scale + xShift + offset * cont, scale + yShift, buttonSize, buttonSize * 3 / 2));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        cont++;
    }

}
void MainWindow::Clear(int id) {
    //qDebug() << btn->id << " slot\n";
    buttonHash.remove(id);
    rearrangeButtons();
    //emit QHoverSensitiveButton::destroy();
    //return true;

}
//todelete
void MainWindow::on_pushButton_2_clicked()
{
    if (!buttonList.empty()) {

    QHoverSensitiveButton* btn = buttonList.at(4);
    buttonList.removeAt(4);
    delete btn;

    rearrangeButtons();
    }
}

void MainWindow::on_backButton_clicked()
{
    this->close();
    emit firstScreen();
}
