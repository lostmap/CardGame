#ifndef INTERLAYER_H
#define INTERLAYER_H

#include <QDomDocument>
#include <QDomElement>
#include <QString>

class Client;
class MainWindow;

class InterLayer
{
public:
    InterLayer(MainWindow*, Client*);
    void parseData(QByteArray);

    // скорее всего будет передавать карту
    // или её id
    void sendCard(int id);
    void sendStart();
    void sendLogin(QString login, QString password);
    void sendPass();

private:
    MainWindow *_mainWindow;
    Client *_client;

    void _parseNode(QDomElement);
    void _parseDeck(QDomElement);
    void _parseCard(QDomElement);
};

#endif // INTERLAYER_H
