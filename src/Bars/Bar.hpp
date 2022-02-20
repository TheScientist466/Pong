#pragma once

#include <SFML/Graphics.hpp>
#include "KeyDir.hpp"
#include "../window/windowConfig.hpp"

class Bar
{
public:
    Bar(float initXPos = windowConfig::windowSize.x / 2, sf::Vector2f barDimentions = sf::Vector2f(0, 0));

private:
    sf::RectangleShape shape;
    float BarSpeed = 10.f;

public:
    KeyDir keyDir = {sf::Keyboard::W, sf::Keyboard::S};

public:
    sf::RectangleShape getShape();
    void move(int8_t yMultiplier);

    void setKey(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
    void setKey(KeyDir dir);
};