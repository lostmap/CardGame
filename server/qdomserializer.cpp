#include "qdomserializer.h"
#include "game.h"

QDomSerializer::QDomSerializer()
{

}

QDomElement QDomSerializer::_domElement(QString elementName, int value) const
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(QString::number(value));
    element.appendChild(text);

    return element;
}

QDomElement QDomSerializer::_domElement(QString elementName, QString value) const
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(value);
    element.appendChild(text);

    return element;
}

QDomElement QDomSerializer::cardToDomElement(std::shared_ptr<AbstractCard> card) const
{
    QDomDocument document;
    QDomElement cardElement = document.createElement("card");

    cardElement.appendChild(_domElement("id", card->getId()));
    cardElement.appendChild(_domElement("info", QString::fromStdString(card->getInfo())));
    cardElement.appendChild(_domElement("type", card->getEntityType()));
    cardElement.appendChild(_domElement("strength", card->getStrength()));
    cardElement.appendChild(_domElement("strength", card->getPropertyType()));

    return cardElement;
}


QDomElement QDomSerializer::deckToQDomElement(std::shared_ptr<Deck> deck, QString deckName) const
{
    QDomDocument document;
    QDomElement element = document.createElement(deckName);

    for (auto card: *deck)
    {
        element.appendChild(cardToDomElement(card));
    }

    return element;
}

QDomElement QDomSerializer::fieldToQDomElement(std::shared_ptr<Field> field, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2) const
{
    QDomDocument document;
    QDomElement node = document.createElement("field");

    node.appendChild(deckToQDomElement(field->getDeck(player2), "partner"));
    node.appendChild(deckToQDomElement(field->getDeck(player1), "mycards"));

   return node;
}

std::string QDomSerializer::partyToXML(std::shared_ptr<Party> party, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2) const
{
     QDomDocument document;

     QDomElement root = document.createElement("server");

     document.appendChild(root);

     party->isMyTern(player1)?root.appendChild(_domElement("turn", 1))
                          :root.appendChild(_domElement("turn", 0));

     root.appendChild(_domElement("win", player1->isWin()));
     root.appendChild(plyerToQDomElementWithHand(player1, "me"));
     root.appendChild(playerToQDomElement(player2, "partner"));
     root.appendChild(fieldToQDomElement(party->getField(), player1, player2));

     return document.toString().toStdString();
}

QDomElement QDomSerializer::plyerToQDomElementWithHand(std::shared_ptr<Player> player, QString playerName) const
{
    QDomDocument document;
    QDomElement node = document.createElement(playerName);

    node.appendChild(playerToQDomElement(player, playerName));
    node.appendChild(deckToQDomElement(player->getHand(), "Hand"));

    return node;
}

QDomElement QDomSerializer::playerToQDomElement(std::shared_ptr<Player> player, QString playerName) const
{
    QDomDocument document;
    QDomElement node = document.createElement(playerName);

    node.appendChild(_domElement("stagescore", player->getStageScore()));
    node.appendChild(_domElement("score", player->getScore()));
    node.appendChild(_domElement("Handsize", player->getHandSize()));

    player->isPass()?node.appendChild(_domElement("pass", 1)):
             node.appendChild(_domElement("pass", 0));

    return node;
}


