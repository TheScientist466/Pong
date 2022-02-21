#include "objectHandler.hpp"
#include "window/windowConfig.hpp"

ObjectHandler::ObjectHandler()
{
    gameStructure.leftBar   = Bar(sf::Vector2f(10, 100), 50.f);
    gameStructure.rightBar  = Bar(sf::Vector2f(10, 100), windowConfig::windowSize.x - 50);

    shapes.push_back(gameStructure.leftBar.getShape());
    shapes.push_back(gameStructure.rightBar.getShape());
}

ObjectHandler::~ObjectHandler()
{

}

std::vector<sf::Shape*> ObjectHandler::getShapes()
{
    return shapes;
}

void ObjectHandler::ObjectKeyResponse(sf::Keyboard::Key keyPressed)
{
    gameStructure.leftBar.move(keyPressed);
    gameStructure.rightBar.move(keyPressed);
}