#include <QCoreApplication>

#include "myserver.h"
#include "interlayer.h"
#include "game.h"
#include "server.h"
#include "config.h"
#include "log.h"

#include <memory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Log& log = Log::Instance("log.txt", "error.txt");
    Config& init = Config::Instance("server.xml");

    auto game = std::shared_ptr<Game>(new Game());
    auto server = std::shared_ptr<Server>(new Server());
    auto myServer = std::shared_ptr<MyServer>(new MyServer(server));

    auto interLayer = std::shared_ptr<InterLayer>(new InterLayer(game, myServer));

    server->setMyServer(myServer);
    game->setInterLayer(interLayer);
    myServer->setInterLayer(interLayer);

    bool success =server->listen(QHostAddress::Any, Config::Instance().PORT);

    if(!success)
        Log::Instance().error("Listen on port " + std::to_string(Config::Instance().PORT) + " fail");


    return a.exec();
}
