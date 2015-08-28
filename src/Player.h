#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Laser.h"

class Player : public GameObject
{
public:
    Player(sf::Vector2f pos = sf::Vector2f{0,0}, sf::Vector2f vel = sf::Vector2f{0.f,0.f});
    //sf::Sprite& getSprite() { return _sprite; };
    void accelerate(sf::Vector2f vel);
    Direction getDirection() { return _direction; };
    void setDirection(Direction d);
    void update(float dt);

    Laser shoot();

private:
    static const float MAX_VELOCITY;
    //sf::Sprite _sprite;
};
#endif
