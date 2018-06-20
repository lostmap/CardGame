#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

#include <memory>


class MainWindow
{
public:
    MainWindow();

    void draw(std::shared_ptr<sf::RenderWindow> window);

    void setScore(int myScore, int enemyScore);

    bool pass(float x, float y);

    void setEnemyPass();

    void setTurn(bool tern);


private:

	sf::Texture _background;
    sf::Texture _backgroundH;
    sf::Texture _backgroundM;
    sf::Sprite _bgImage;

    sf::Texture _pass;
    sf::Sprite _passImage;

    sf::Sprite _passEnemyImage;

    sf::Font _font;

    sf::Text _myScore;
    sf::Text _enemyScore;
};

#endif 