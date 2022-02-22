#include "Ball.hpp"
#include "../window/windowConfig.hpp"

Ball::Ball(float radius, sf::Vector2f initDir)
{
    shape = sf::CircleShape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(config::windowSize.x / 2, config::windowSize.y / 2);

    velocityDir = initDir;
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