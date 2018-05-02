#include <QCoreApplication>

#include "myserver.h"
#include "interlayer.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Game *game = new Game();
    MyServer *server = new MyServer();

    InterLayer *interLayer = new InterLayer(game, server);

    game->setInterLayer(interLayer);
    server->setInterLayer(interLayer);

    bool success = server->listen(QHostAddress::Any, 1234);
        if(!success)
        {
            qFatal("Could not listen on port 4200.");
        }

        qDebug() << "Ready";

    return a.exec();
}
