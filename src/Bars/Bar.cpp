#include "Bar.hpp"


Bar::Bar(sf::Vector2f size, float initXPos)
{
    shape = sf::RectangleShape(size);
    shape.setPosition(initXPos, windowConfig::windowSize.y / 2);
}

void Bar::move(int8_t yMult)
{
    shape.move(sf::Vector2f(0, yMult * BarSpeed));
}

sf::RectangleShape Bar::getShape()
{
    return shape;
}

void Bar::setKey(sf::Keyboard::Key _upKey, sf::Keyboard::Key _downKey)
{
    keyDir.upKey    = _upKey;
    keyDir.downKey  = _downKey;
}

void Bar::setKey(KeyDir k)
{
    keyDir.upKey    = k.upKey;
    keyDir.downKey  = k.downKey;
}