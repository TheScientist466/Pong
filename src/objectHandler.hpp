#pragma once
#include <SFML/Graphics.hpp>
#include "Bars/Bar.hpp"
#include <vector>

struct GameStructure
{
    Bar leftBar;
    Bar rightBar;
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
    std::vector<sf::Shape*> getShapes();
};