#include "objectHandler.hpp"
#include "window/windowConfig.hpp"
#include "GameConfig.hpp"

static const float xBouncePos = (config::barXPos + config::barSize.x + config::ballRadius);

ObjectHandler::ObjectHandler()
{
    gameStructure.leftBar   = Bar(config::barSize, config::barXPos);
    gameStructure.rightBar  = Bar(config::barSize, config::windowSize.x - config::barXPos);

    gameStructure.ball = Ball(20.f, config::ballInitDir);

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

    switch (keyPressed)
    {
    case sf::Keyboard::R:
        gameStructure.ball.restart();
    }
}

void ObjectHandler::ObjectFrameResponse()
{
    gameStructure.ball.move();
    gameStructure.ball.wallCollideDetect();

    const sf::Vector2f &ballPos =   gameStructure.ball.getShape()->getPosition();
    const float &leftBarYPos =      gameStructure.leftBar.getShape()->getPosition().y;
    const float &rightBarYPos =     gameStructure.rightBar.getShape()->getPosition().y;

    if((ballPos.x > xBouncePos - config::barSize.x && ballPos.x < config::windowSize.x - xBouncePos + config::barSize.x))
    {
        if((ballPos.x <= xBouncePos || ballPos.x >= config::windowSize.x - xBouncePos))
        {
            if((ballPos.y <= leftBarYPos + config::barSize.y / 2 && ballPos.y >= leftBarYPos - config::barSize.y / 2))
                gameStructure.ball.BarCollide(gameStructure.rightBar.getShape()->getPosition(), false);
            else if ((ballPos.y <= rightBarYPos + config::barSize.y / 2 && ballPos.y >= rightBarYPos - config::barSize.y / 2))
                gameStructure.ball.BarCollide(gameStructure.rightBar.getShape()->getPosition(), true);
        }
    }
}