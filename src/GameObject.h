#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:
    GameObject(sf::Vector2f pos, sf::Vector2f vel) : _postion{pos}, _velocity{vel} {};
    ~GameObject() {};
    enum class Direction {Left, Right}; // it's a side-scroller
    virtual void update(float dt) {};
    sf::Sprite& getSprite() { return _sprite; };
protected:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Vector2f _postion;
    sf::Vector2f _velocity;
    Direction _direction = Direction::Right;
};

#endif
