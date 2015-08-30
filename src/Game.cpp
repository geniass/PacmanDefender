#include "Game.h"
#include "GameScreen.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

Game::Game(const int gameWidth, const int gameHeight, string title) : _window{sf::VideoMode(gameWidth, gameHeight), title}
{
    _window.setVerticalSyncEnabled(true);
}

void Game::addScreen(shared_ptr<GameScreen> screen)
{
    _screens.push(screen);
}

void Game::removeCurrentScreen()
{
    if (!_screens.empty()) {
        _screens.pop();
    }
}

shared_ptr<GameScreen> Game::getCurrentScreen()
{
    if (!_screens.empty()) {
        return _screens.top();
    }

    return nullptr;
}

void Game::gameLoop()
{
    sf::Clock clock;
    while(_window.isOpen()){
        auto screen = getCurrentScreen();
        // while there is a current screen, run the loop
        if (screen == nullptr) {
            return;
        }

        screen = screen->run(_window);

        if (screen == nullptr) {
            cout << "Removing screen... ";
            removeCurrentScreen();
            cout << _screens.size() << endl;
            continue;
        } else {
            cout << "Adding screen... " ;
            addScreen(screen);
            cout << _screens.size() << endl;
            continue;
        }
    }
}
