#ifndef GAMEWORLDSCREEN_H
#define GAMEWORLDSCREEN_H

#include "Game.h"
#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class GameWorldScreen : public GameScreen
{
public:
    GameWorldScreen();
    void draw(sf::RenderWindow& window, const float dt);
    void update(const float dt);
    void handleInput(sf::RenderWindow& window);
    virtual shared_ptr<GameScreen> run(sf::RenderWindow& window);
};

#endif
