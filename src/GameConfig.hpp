#pragma once

#include <SFML/Graphics.hpp>
#include "Theme/colorThemes.hpp"

namespace config
{

    static const sf::Vector2f barSize = sf::Vector2f(10.f, 100.f);
    static const float barXPos = 50.f;
    static const float ballRadius = 10.f;

    static const float barSpeed = 10.f;
    static const float ballSpeed = 3.5f;

    static const sf::Vector2f ballInitDir = sf::Vector2f(-1, 0.5);

    namespace gameColors
    {
        static const sf::Color background = colorThemes::Nord::PolarNight::d1;

        static const sf::Color LeftBarColor = colorThemes::Nord::Arora::Green;
        static const sf::Color RightBarColor = colorThemes::Nord::Arora::Purple;
        static const sf::Color BallColor = colorThemes::Nord::Arora::Red;
    }
}