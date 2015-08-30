#ifndef GAMEWORLDSCREEN_H
#define GAMEWORLDSCREEN_H

#include "Game.h"
#include "GameScreen.h"
#include "Player.h"
#include "Laser.h"
#include <SFML/Graphics.hpp>
#include <list>

class GameWorldScreen : public GameScreen
{
public:
    GameWorldScreen();
    void quit();
    virtual shared_ptr<GameScreen> run(sf::RenderWindow& window);
private:
    Player player;
    Player target{sf::Vector2f{600,300}};

    list<Laser> lasers;
    list<Player> enemies{target};

    bool paused = false;
    bool running = true;

    void draw(sf::RenderWindow& window, const float dt);
    void update(const float dt);
    void handleInput(sf::RenderWindow& window);
};

#endif
