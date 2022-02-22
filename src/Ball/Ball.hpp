#pragma once

#include <SFML/Graphics.hpp>
#include "../GameConfig.hpp"

class Ball
{

public:
    Ball(float radius = 0.f, sf::Vector2f initDir = sf::Vector2f(0, 0));

private:
    sf::CircleShape shape;
    sf::Vector2f velocityDir = sf::Vector2f(0, 0);
    float BallSpeed = config::ballSpeed;

public:
    void Move();
    sf::Shape* getShape();
};