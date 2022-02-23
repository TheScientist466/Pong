#include <SFML/Graphics.hpp>
#include "windowConfig.hpp"
#include "window.hpp"

sf::RenderWindow* renderWindow = new sf::RenderWindow(sf::VideoMode(config::windowSize.x, config::windowSize.y), config::windowTitle, sf::Style::Close);;
sf::Event windowEvent;

window::window(ObjectHandler &objHandler)
{
    objects = &objHandler;
    renderWindow->setFramerateLimit(config::framerate);
    renderWindow->setPosition(sf::Vector2i( 
        (config::screenResolution.x - config::windowSize.x) / 2, 
        (config::screenResolution.y - config::windowSize.y) / 2
        ));
} 

void window::renderLoop()
{
    while(renderWindow->isOpen())
    {
        while(renderWindow->pollEvent(windowEvent))
        {
            checkEvents();
        }
        Update();
    }
}

void window::checkEvents()
{
    switch(windowEvent.type)
    {
        case sf::Event::Closed:
            renderWindow->close();
            return;
        
        case sf::Event::KeyPressed:
            objects->ObjectKeyResponse(windowEvent.key.code);
            break;
    }
}

void window::Update()
{
    objects->ObjectFrameResponse();
    renderWindow->clear();
    for(auto &s : objects->getShapes())
        renderWindow->draw(*s);
    renderWindow->display();
}

window::~window()
{
    
}
