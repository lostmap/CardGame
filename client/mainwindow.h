#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

#include "interlayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setInterLayer(InterLayer*);
    void append(QString);
    void insertPlainText(QString);
    void clear();


private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();

private:
        Ui::MainWindow *ui;

        // пока что добавлю сюда
        // но между окном и промежуточным слоем
        // нужно добавить слой логики нак клиенте
        InterLayer *_interLayer;
};

#endif // MAINWINDOW_H
