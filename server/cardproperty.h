#ifndef CARDPROPERTY_H
#define CARDPROPERTY_H

class Field;
class Player;
class AbstractCard;

#include <memory>

class CardProperty
{
public:
    CardProperty();
    void activate(std::shared_ptr<Player> player1,
                  std::shared_ptr<Player> player2,
                  std::shared_ptr<AbstractCard> card,
                  std::shared_ptr<Field> field);
private:
    void _buff(std::shared_ptr<Player> player1,
              std::shared_ptr<AbstractCard> card,
              std::shared_ptr<Field> field);
    void _rollCall(std::shared_ptr<Player> player1,
                  std::shared_ptr<AbstractCard> card,
                  std::shared_ptr<Field> field);
    void _spy(std::shared_ptr<Player> player1,
             std::shared_ptr<Player> player2,
             std::shared_ptr<AbstractCard> card,
             std::shared_ptr<Field> field);

    void _default(std::shared_ptr<Player> player1,
                  std::shared_ptr<AbstractCard> card,
                  std::shared_ptr<Field> field);
};

#endif // CARDPROPERTY_H
