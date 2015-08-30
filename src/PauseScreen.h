#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "GameScreen.h"
#include "GameWorldScreen.h"
#include <SFML/Graphics.hpp>

class PauseScreen : public GameScreen
{
public:
    PauseScreen(GameWorldScreen* gameWorldScreen);
    virtual shared_ptr<GameScreen> run(sf::RenderWindow& window);
private:
    GameWorldScreen* _gameWorldScreen;
};

#endif
