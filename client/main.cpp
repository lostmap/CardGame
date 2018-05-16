#include "mainwindow.h"
#include "client.h"
#include "interlayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    Client *client = new Client();

    InterLayer *interLayer = new InterLayer(mainWindow, client);

    mainWindow->setInterLayer(interLayer);
    client->setInterLayer(interLayer);

    mainWindow->show();

    return a.exec();
}
