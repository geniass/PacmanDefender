#ifndef GAMEWORLDSCREEN_H
#define GAMEWORLDSCREEN_H

#include "Game.h"
#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class GameWorldScreen : public GameScreen
{
public:
    GameWorldScreen();
    virtual void draw(sf::RenderWindow& window, const float dt);
    virtual void update(const float dt);
    virtual void handleInput(sf::RenderWindow& window);
};

#endif
