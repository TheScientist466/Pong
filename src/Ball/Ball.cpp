#include "Ball.hpp"
#include "../window/windowConfig.hpp"

Ball::Ball(float radius = 0.f, sf::Vector2f initDir)
{
    shape = sf::CircleShape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(config::windowSize.x / 2, config::windowSize.y / 2);

    velocityDir = initDir;
}