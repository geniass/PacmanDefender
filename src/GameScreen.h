#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class GameScreen
{
public:
    // Runs the screen. Should return a pointer to the next screen to be
    // displayed or nullptr to go back to the previous screen
    virtual shared_ptr<GameScreen> run(sf::RenderWindow& window) = 0;
};

#endif
