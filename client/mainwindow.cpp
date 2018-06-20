#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qhoversensitivebutton.h"
#include <ctime>
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        //view = new QGraphicsView;
        //scene = new QGraphicsScene(0, 0, 1366, 768, this);
       // scene->addText("Hello, world!");

    ui->setupUi(this);
    //view->setScene(scene);
    //view = new QGraphicsView();
    //view->setSceneRect(0, 0, 500, 500);
    //view->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    //view->setScene(&scene);
    ui->graphicsView->setFrameStyle(0);
    //ui->graphicsView->setFixedSize(1000, 700);
    ui->graphicsView->setSceneRect(0, 0, 620, 400);
    ui->graphicsView->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    ui->graphicsView->setScene(&scene);
    buttonSize = 60;
    scale = 50;
    xShift = 20;
    yShift = 520;
    offset = 10;
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
        buttonList.append(btn);
        //buttonHash[id] = btn;
        rearrangeButtons();

        connect(btn,  &QHoverSensitiveButton::clicked, &scene, [=]() {scene.handle(btn);});
        connect(&scene, SIGNAL(clicked()), btn, SLOT(del()));
       // connect(btn, &QHoverSensitiveButton::clear, this, [=]() {this->Clear(btn->getId());});

}


void MainWindow::rearrangeButtons()
{
    //int buttonCount = buttonList.size();
    //QList<QHoverSensitiveButton*>::iterator iter;
    //QHash<int, QHoverSensitiveButton*>::iterator iter;
    for (int i = 0; i < buttonList.size(); i++) {
        QPropertyAnimation* animation = new QPropertyAnimation(buttonList[i], "geometry");
        animation->setDuration(1000);
       // qDebug() << i << "\n";
        animation->setEasingCurve(QEasingCurve::InOutElastic);
        animation->setEndValue(QRectF(i * scale + xShift + offset * i, scale + yShift, buttonSize, buttonSize * 4 / 3));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}
void MainWindow::Clear(int id) {
    //qDebug() << btn->id << " slot\n";
    //buttonHash.remove(id);
    /*QList<QHoverSensitiveButton*>::iterator iter;
    for (iter = buttonList.begin(); iter != buttonList.end(); iter++) {
        QHoverSensitiveButton* btn = *iter;
        if (btn->getId() == id) {
            buttonList.erase(iter);
        }
    }*/
    qDebug() << "before " << buttonList.size() << "\n";
    for (int i = 0; i < buttonList.size(); i++) {
        if (buttonList[i]->getId() == id) {
            buttonList.removeAt(i);
            qDebug() << "after " << buttonList.size() << "\n";
        }
    }
    //buttonList
    rearrangeButtons();
    //emit QHoverSensitiveButton::destroy();
    //return true;

}
//todelete


void MainWindow::on_backButton_clicked()
{
    this->close();
    emit firstScreen();
}
