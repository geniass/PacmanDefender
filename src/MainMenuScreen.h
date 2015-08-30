#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class MainMenuScreen : public GameScreen
{
public:
    MainMenuScreen();
    virtual shared_ptr<GameScreen> run(sf::RenderWindow& window);
private:
    bool playing = false;
};

#endif
