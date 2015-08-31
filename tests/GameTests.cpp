#include "Laser.h"

#include <gtest/gtest.h>

TEST(Laser, canBeCreated)
{
    Laser laser1{sf::Vector2f(0,0)};
    EXPECT_FALSE(laser1.getSprite() == nullptr);
}
