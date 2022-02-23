#include "Ball.hpp"
#include "../window/windowConfig.hpp"
#include <math.h>

Ball::Ball(float radius, sf::Vector2f initDir, sf::Color color)
{
    shape = sf::CircleShape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(config::windowSize.x / 2, config::windowSize.y / 2);

    float magnitude = std::sqrt(std::pow(initDir.x, 2) + std::pow(initDir.y, 2));
    velocityDir = sf::Vector2f(initDir.x/magnitude, initDir.y/magnitude);

    shape.setFillColor(color);
}

sf::Shape* Ball::getShape()
{
    return &shape;
}

void Ball::move()
{
    shape.move(velocityDir * ballSpeed);
}

void Ball::wallCollideDetect()
{
    if( shape.getPosition().y <= shape.getRadius() || 
        shape.getPosition().y >= config::windowSize.y - shape.getRadius())
        velocityDir.y *= -1;
}

void Ball::BarCollide()
{
    velocityDir.x *= -1;
}