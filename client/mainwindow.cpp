#include "mainwindow.h"

#include "config.h"
#include "log.h"

MainWindow::MainWindow() {

    if(!_background.loadFromFile("images/field.jpg"))
        Log::Instance().log("couldnt load background");

    if(!_backgroundH.loadFromFile("images/fieldh.jpg"))
        Log::Instance().log("couldnt load background");

    if(!_backgroundM.loadFromFile("images/fieldm.jpg"))
        Log::Instance().log("couldnt load background");

    _bgImage.setTexture(_background);


    if(!_pass.loadFromFile("images/pass.png"))
        Log::Instance().log("couldnt load pass image");

    _passImage.setTexture(_pass);
    _passImage.setPosition(100, 500);

    _passEnemyImage.setTexture(_pass);
    _passEnemyImage.setPosition(100, 50);


    if (!_font.loadFromFile(Config::Instance().STRENGTH_FONT))
        Log::Instance().log("couldnt load font");
    
    
    _myScore.setFont(_font);
    
    _enemyScore.setFont(_font);

    _myScore.setCharacterSize(30);
    _enemyScore.setCharacterSize(30);

    _myScore.setPosition(310, 500);
    _enemyScore.setPosition(310, 160);

}

void MainWindow::setScore(int myScore, int enemyScore) {
	_myScore.setString(std::to_string(myScore));
    _enemyScore.setString(std::to_string(enemyScore));
}


bool MainWindow::pass(float x, float y) {

	if (_passImage.getGlobalBounds().contains(x, y)){
        _passImage.setColor(sf::Color::Red);
        return true;
    }
    return false;
}

void MainWindow::setEnemyPass() {
	_passEnemyImage.setColor(sf::Color::Red);
}

void MainWindow::setTurn(bool tern) {
	if(tern)
        _bgImage.setTexture(_backgroundM);
    else 
        _bgImage.setTexture(_backgroundH);
}

void MainWindow::draw(std::shared_ptr<sf::RenderWindow> window) {
	
	window->draw(_bgImage);
    window->draw(_myScore);
    window->draw(_enemyScore);
    window->draw(_passEnemyImage);
    window->draw(_passImage);
}