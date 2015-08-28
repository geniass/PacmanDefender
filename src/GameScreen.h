#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Game.h"
#include <SFML/Graphics.hpp>

class GameScreen
{
public:
    virtual void draw(sf::RenderWindow& window, const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput(sf::RenderWindow& window) = 0;

};

#endif
