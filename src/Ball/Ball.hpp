#pragma once

#include <SFML/Graphics.hpp>
#include "../GameConfig.hpp"

class Ball
{

public:
    Ball(float radius = 0.f, sf::Vector2f initDir = sf::Vector2f(0, 0));

private:
    sf::CircleShape shape;
    sf::Vector2f velocityDir;
    float ballSpeed = config::ballSpeed;

public:
    void move();
    sf::Shape* getShape();

    void restart();

    void wallCollideDetect();
    void BarCollide();
    void BarCollide(sf::Vector2f BarPos, bool inv);
};