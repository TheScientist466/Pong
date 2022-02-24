#include "Ball.hpp"
#include "../window/windowConfig.hpp"
#include <math.h>


static sf::Vector2f VectorNormalize(sf::Vector2f vec)
{
    float magnitude = std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
    return sf::Vector2f(vec.x/magnitude, vec.y/magnitude);
}



Ball::Ball(float radius, sf::Vector2f initDir)
{
    shape = sf::CircleShape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(config::windowSize.x / 2, config::windowSize.y / 2);

    velocityDir = VectorNormalize(initDir);
}

sf::Shape* Ball::getShape()
{
    return &shape;
}

void Ball::move()
{
    shape.move(velocityDir * ballSpeed);
}

void Ball::restart()
{
    shape.setPosition(config::windowSize.x / 2, config::windowSize.y / 2);
    velocityDir = config::ballInitDir;
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

void Ball::BarCollide(sf::Vector2f BarPos, bool inv)
{
    const sf::Vector2f &myPos = shape.getPosition();
    //sf::Vector2f collisionPoint = sf::Vector2f(myPos.x + shape.getRadius() * (myPos.x < BarPos.x ? 1 : -1), myPos.y);

    int multiplier = (!inv ? 1 : -1);
    velocityDir = VectorNormalize(myPos + sf::Vector2f(BarPos.x * multiplier, BarPos.y * multiplier));
}