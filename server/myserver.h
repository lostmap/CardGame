#ifndef MYSERVER_H
#define MYSERVER_H

#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class InterLayer;

class MyServer : public QTcpServer
{
    Q_OBJECT
    public:
        MyServer(QObject *parent=0);
        void setInterLayer(InterLayer *interLayer);

    private slots:
        void readyRead();
        void disconnected();

    protected:
       void incomingConnection(int socketfd);

    private:
       // QSet<QTcpSocket*> clients;

       InterLayer *_interLayer;
};

#endif // MYSERVER_H
