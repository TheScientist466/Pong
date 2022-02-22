#pragma once

#include <SFML/Graphics.hpp>
#include "KeyDir.hpp"
#include "../window/windowConfig.hpp"

class Bar
{
public:
    Bar(sf::Vector2f barDimentions = sf::Vector2f(0, 0), float initXPos = config::windowSize.x / 2);

private:
    sf::RectangleShape shape;
    float BarSpeed = 10.f;

public:
    KeyDir keyDir = {sf::Keyboard::W, sf::Keyboard::S};

public:
    sf::RectangleShape* getShape();
    void move(int8_t yMultiplier);
    void move(sf::Keyboard::Key key);

    void setKey(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
    void setKey(KeyDir dir);
};