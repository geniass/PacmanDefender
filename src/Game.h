#ifndef GAME_H
#define GAME_H

#include <stack>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class GameScreen;
using GameScreenPtr = std::shared_ptr<GameScreen>;

class Game
{
public:
    Game(const int gameWidth = 800, const int gameHeight = 600, string title = "Pacman Defender");
    void addScreen(GameScreenPtr screen);
    void removeCurrentScreen();
    GameScreenPtr getCurrentScreen();
    void gameLoop();

private:
    sf::RenderWindow _window;
    std::stack<GameScreenPtr> _screens;
};

#endif
