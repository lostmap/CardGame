#ifndef MYSERVER_H
#define MYSERVER_H


#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class MyServer : public QTcpServer
{
    Q_OBJECT
    public:
        MyServer(QObject *parent=0);

    private slots:
        void readyRead();
        void disconnected();

    protected:
       void incomingConnection(int socketfd);

    private:
       // QSet<QTcpSocket*> clients;
       QMap<QTcpSocket*, QTcpSocket*> partner;
       QTcpSocket *waiting_client;
       QMap<QTcpSocket*,QString> user;
};

#endif // MYSERVER_H
