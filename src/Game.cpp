#include "Game.h"
#include "GameScreen.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

using namespace std;

Game::Game(const int gameWidth, const int gameHeight, string title) : _window{sf::VideoMode(gameWidth, gameHeight), title}
{
    _window.setVerticalSyncEnabled(true);
}

void Game::addScreen(GameScreenPtr screen)
{
    _screens.push(screen);
}

void Game::removeCurrentScreen()
{
    if (!_screens.empty()) {
        _screens.pop();
    }
}

GameScreenPtr Game::getCurrentScreen()
{
    if (!_screens.empty()) {
        return _screens.top();
    }

    shared_ptr<GameScreen> ptr;
    return ptr;
}

void Game::gameLoop()
{
    sf::Clock clock;
    while(_window.isOpen()){
        auto screen = getCurrentScreen();
        // while there is a current screen, run the loop
        if (screen == nullptr) {
            continue;
        }

        screen->handleInput(_window);

        float dt = clock.restart().asSeconds();
        screen->update(dt);
        screen->draw(_window, dt);
    }
}
