#include <QCoreApplication>

#include "myserver.h"
#include "interlayer.h"
#include "game.h"
#include "qserver.h"
#include "config.h"
#include "log.h"

#include <memory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Log& log = Log::Instance("log.txt", "error.txt");
    Config& init = Config::Instance("server.xml");

    auto game = std::make_shared<Game>();
    auto server = std::make_shared<QServer>();
    auto myServer = std::make_shared<MyServer>(server);

    auto interLayer = std::make_shared<InterLayer>(game, myServer);

    server->setMyServer(myServer);
    game->setInterLayer(interLayer);
    myServer->setInterLayer(interLayer);

    bool success =server->listen(QHostAddress::Any, Config::Instance().PORT);

    if(!success)
        Log::Instance().error("Listen on port " + std::to_string(Config::Instance().PORT) + " fail");


    return a.exec();
}
