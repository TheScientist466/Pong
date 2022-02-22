#include "objectHandler.hpp"
#include "window/windowConfig.hpp"

ObjectHandler::ObjectHandler()
{
    gameStructure.leftBar   = Bar(sf::Vector2f(10, 100), 50.f);
    gameStructure.rightBar  = Bar(sf::Vector2f(10, 100), config::windowSize.x - 50);

    gameStructure.ball = Ball(20.f, sf::Vector2f(1, 0.2));

    shapes.push_back(gameStructure.leftBar.getShape());
    shapes.push_back(gameStructure.rightBar.getShape());
    shapes.push_back(gameStructure.ball.getShape());

    gameStructure.rightBar.keyDir.upKey     = sf::Keyboard::Up;
    gameStructure.rightBar.keyDir.downKey   = sf::Keyboard::Down;
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

void ObjectHandler::ObjectFrameResponse()
{
    gameStructure.ball.Move();
}