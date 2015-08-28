#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace std;

class GameObject
{
public:
    GameObject(sf::Vector2f pos, sf::Vector2f vel) : _position{pos}, _velocity{vel} {};
    ~GameObject() {};
    enum class Direction {Left, Right}; // it's a side-scroller
    virtual void update(float dt) {};
    shared_ptr<sf::Sprite> getSprite() { return _sprite; };

protected:
    shared_ptr<sf::Texture> _texture = make_shared<sf::Texture>();
    shared_ptr<sf::Sprite> _sprite = make_shared<sf::Sprite>();
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    Direction _direction = Direction::Right;
};

#endif
