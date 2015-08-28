#include "GameWorldScreen.h"
#include "Player.h"
#include "Laser.h"
#include <SFML/Graphics.hpp>
#include <list>

Player player;
Player target{sf::Vector2f{600,300}};

list<Laser> lasers;
list<Player> enemies{target};

GameWorldScreen::GameWorldScreen()
{
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
            }
        }
    }
}
