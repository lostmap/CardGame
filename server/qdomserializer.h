#ifndef QDOMSERIALIZER_H
#define QDOMSERIALIZER_H

#include "abstractcard.h"
#include "deck.h"
#include "field.h"
#include "party.h"
#include "player.h"

#include <QDomElement>
#include <QDomDocument>

#include <memory>
#include <string>

class QDomSerializer
{
public:
    QDomSerializer();

    QDomElement cardToDomElement(std::shared_ptr<AbstractCard>) const;
    QDomElement deckToQDomElement(std::shared_ptr<Deck>, QString) const;
    QDomElement fieldToQDomElement(std::shared_ptr<Field>, std::shared_ptr<Player>, std::shared_ptr<Player>) const;
    QDomElement plyerToQDomElementWithHand(std::shared_ptr<Player>, QString) const;
    QDomElement playerToQDomElement(std::shared_ptr<Player>, QString) const;
    std::string partyToXML(std::shared_ptr<Party>, std::shared_ptr<Player>, std::shared_ptr<Player>) const;

private:
    QDomElement _domElement(QString elementName, QString value) const;
    QDomElement _domElement(QString elementName, int value) const;
};

#endif // QDOMSERIALIZER_H
