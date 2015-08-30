#include "GameWorldScreen.h"
#include "PauseScreen.h"
#include "Player.h"
#include "Laser.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using namespace std;

GameWorldScreen::GameWorldScreen()
{
    running = true;
    paused = false;
    cout << running << endl;
}

shared_ptr<GameScreen> GameWorldScreen::run(sf::RenderWindow& window)
{
    if (!running) {
        // user chose exit on pause menu
        return nullptr;
    }

    paused = false;
    sf::Clock clock;
    while (!paused) {
        handleInput(window);
        float dt = clock.restart().asSeconds();
        update(dt);
        draw(window, dt);
    }

    return make_shared<PauseScreen>(this);
}

void GameWorldScreen::update(const float dt)
{
    float acceleration = 700.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.setDirection(Player::Direction::Left);
        player.accelerate(sf::Vector2f(-acceleration * dt,0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.setDirection(Player::Direction::Right);
        player.accelerate(sf::Vector2f(acceleration * dt,0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player.accelerate(sf::Vector2f(0.f, acceleration * dt));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.accelerate(sf::Vector2f(0.f,-acceleration * dt));
    }


    for (auto l = lasers.begin(); l != lasers.end(); ) {
        l->update(dt);

        bool intersected = false;
        for (auto e = begin(enemies); e != end(enemies); e++) {
            if (l->getSprite()->getGlobalBounds().intersects(e->getSprite()->getGlobalBounds())) {
                cout << "intersects" << endl;
                l = lasers.erase(l);
                enemies.erase(e);
                intersected = true;
                break;
            }

        }
        if(!intersected) {
            l++;
        }

    }

    player.update(dt);
}

void GameWorldScreen::draw(sf::RenderWindow& window, const float dt)
{
    window.clear();

    for (auto& l : lasers) {
        window.draw(*l.getSprite());
    }

    for (auto& l : enemies) {
        window.draw(*l.getSprite());
    }

    window.draw(*player.getSprite());

    window.display();
}

void GameWorldScreen::handleInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Space) {
                auto l = player.shoot();
                lasers.push_back(l);
            } else if (event.key.code == sf::Keyboard::Escape) {
                paused = true;
                return;
            }
        }
    }
}

void GameWorldScreen::quit()
{
    cout << "Quit" << endl;
    running = false;
}
