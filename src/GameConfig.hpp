#pragma once

#include <SFML/Graphics.hpp>

namespace config
{

    static const sf::Vector2f barSize = sf::Vector2f(10.f, 100.f);
    static const float barXPos = 50.f;
    static const float ballRadius = 10.f;

    static const float barSpeed = 10.f;
    static const float ballSpeed = 2.f;

    static const sf::Vector2f ballInitDir = sf::Vector2f(1, 0.5);
}