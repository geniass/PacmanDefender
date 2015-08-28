#include "Laser.h"
#include <memory>

using namespace std;

const float Laser::MAX_VELOCITY = 400.f;

Laser::Laser(sf::Vector2f pos, sf::Vector2f vel) : GameObject(pos, vel)
{
    if (!_texture->loadFromFile("resources/pacman.png")){}
    _sprite->setTexture(*_texture);
    _sprite->setScale(0.02f,0.002f);
    auto bounds = _sprite->getLocalBounds();
    _sprite->setOrigin(bounds.left + bounds.width/2, bounds.top + bounds.height/2);

    //_sprite.setSize(sf::Vector2f(10,5));
    _sprite->setPosition(pos);
}

void Laser::shoot(Direction d)
{
    switch (d) {
        case Direction::Left:
            _velocity.x = -MAX_VELOCITY;
            break;
        case Direction::Right:
            _velocity.x = MAX_VELOCITY;
            break;
        default:
            break;
    }
}

void Laser::update(float dt)
{
    _sprite->move(dt * _velocity);
}
