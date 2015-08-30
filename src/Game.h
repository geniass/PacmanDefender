#ifndef GAME_H
#define GAME_H

#include "GameScreen.h"
#include <stack>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class Game
{
public:
    Game(const int gameWidth = 800, const int gameHeight = 600, string title = "Pacman Defender");
    void addScreen(shared_ptr<GameScreen> screen);
    void removeCurrentScreen();
    shared_ptr<GameScreen> getCurrentScreen();
    void gameLoop();

private:
    sf::RenderWindow _window;
    std::stack<shared_ptr<GameScreen>> _screens;
};

#endif
