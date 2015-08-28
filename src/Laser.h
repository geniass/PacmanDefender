#ifndef _LASER_H
#define _LASER_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Laser : public GameObject
{
public:
    Laser(sf::Vector2f pos, sf::Vector2f vel = sf::Vector2f{0,0});
    //sf::RectangleShape& getShape() { return shape; };
    void shoot(Direction d);
    virtual void update(float dt);

private:
    static const float MAX_VELOCITY;
    //sf::RectangleShape shape;
};
#endif
