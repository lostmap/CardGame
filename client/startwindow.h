#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class startwindow;
}

class startwindow : public QDialog
{
    Q_OBJECT

public:
    explicit startwindow(QWidget *parent = 0);
    ~startwindow();

private slots:
    void on_play_clicked();

    void on_Quit_clicked();

    void on_connect_clicked();

private:
    Ui::startwindow *ui;
    MainWindow *gameScreen;
};

#endif // STARTWINDOW_H
