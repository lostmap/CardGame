#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <cmath>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QHash>

#include "qhoversensitivebutton.h"
#include "moveitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backButton_clicked();

    void Clear(int id);

signals:
    void firstScreen();

private:
    Ui::MainWindow *ui;
    int xShift, yShift, scale, buttonSize, offset;

    QGraphicsScene *scene;
    QList<QHoverSensitiveButton*> buttonList;
    QHash<int, QHoverSensitiveButton*> buttonHash;
    //QHoverSensitiveButton* buttonArr[8];
    void rearrangeButtons();
};

#endif // MAINWINDOW_H
