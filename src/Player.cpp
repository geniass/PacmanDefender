#include "Player.h"
#include <cmath>
#include <iostream>

using namespace std;

const float Player::MAX_VELOCITY = 100.f;

Player::Player(sf::Vector2f pos, sf::Vector2f vel) : GameObject(pos, vel)
{
    if (!_texture.loadFromFile("resources/pacman.png")){}
    _sprite.setTexture(_texture);
    _sprite.setScale(0.2f,0.2f);
    auto bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.left + bounds.width/2, bounds.top + bounds.height/2);
    _sprite.setPosition(pos);
}

void Player::accelerate(sf::Vector2f vel)
{
    // keep velocity within max and min
    _velocity.x = max(min(_velocity.x + vel.x, MAX_VELOCITY), -MAX_VELOCITY);
    _velocity.y = max(min(_velocity.y + vel.y, MAX_VELOCITY), -MAX_VELOCITY);
}

void Player::setDirection(Direction d)
{
    _direction = d;
    switch (d) {
        case Direction::Left:
            _sprite.setRotation(180.f);
            //_velocity.x = -MAX_VELOCITY;
            break;
        case Direction::Right:
            _sprite.setRotation(0.f);
            //_velocity.x = MAX_VELOCITY;
            break;
        /*case Direction::Up:*/
            ////_velocity.y = -MAX_VELOCITY;
            //break;
        //case Direction::Down:
            ////_velocity.y = MAX_VELOCITY;
            /*break;*/
        default:
            break;
    }
}

void Player::update(float dt)
{
    _sprite.move(dt * _velocity);
}
