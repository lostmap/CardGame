#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QObject>
#include <QMainWindow>

#include "interlayer.h"

class Client: public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client() {}
    void setInterLayer(InterLayer*);
    void send(QString data);
signals:

private slots:
    void readyRead();
    void connected();
    void disconnected();

private:
    QTcpSocket *_socket;
    InterLayer *_interLayer;
};

#endif // CLIENT_H
