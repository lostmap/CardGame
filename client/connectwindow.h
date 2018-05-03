#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include "mainwindow.h"
#include <QTcpSocket>
#include <QDialog>

namespace Ui {
class ConnectWindow;
}

class ConnectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = 0);
    ~ConnectWindow();

private slots:

        // This function gets called when a user clicks on the
        // loginButton on the front page (which you placed there
        // with Designer)
        void on_loginButton_clicked();

        // This gets called when you click the sayButton on
        // the chat page.
        void on_sayButton_clicked();

        // This is a function we'll connect to a socket's readyRead()
        // signal, which tells us there's text to be read from the chat
        // server.
        void readyRead();

        // This function gets called when the socket tells us it's connected.
        void connected();

    signals:
        void secondScreen();
    private:
        Ui::ConnectWindow *ui;
        // This is the socket that will let us communitate with the server.
        QTcpSocket *socket;

};

#endif // CONNECTWINDOW_H

