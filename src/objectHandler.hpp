#pragma once
#include <SFML/Graphics.hpp>
#include "Bars/Bar.hpp"
#include "Ball/Ball.hpp"
#include <vector>

struct GameStructure
{
    Bar leftBar;
    Bar rightBar;
    Ball ball;
};

class ObjectHandler
{
public:
    ObjectHandler();
    ~ObjectHandler();

private:
    GameStructure gameStructure;
    std::vector<sf::Shape*> shapes;

public:
    void ObjectKeyResponse(sf::Keyboard::Key keyPressed);
    void ObjectFrameResponse();
    std::vector<sf::Shape*> getShapes();
};