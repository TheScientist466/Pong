#include <SFML/Graphics.hpp>
#include "windowConfig.hpp"
#include "window.hpp"

sf::RenderWindow* renderWindow = new sf::RenderWindow(sf::VideoMode(windowConfig::windowSize.x, windowConfig::windowSize.y), windowConfig::windowTitle, sf::Style::Close);;
sf::Event windowEvent;

window::window(ObjectHandler &objHandler)
{
    objects = &objHandler;
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
    renderWindow->clear();
    for(auto &s : objects->getShapes())
        renderWindow->draw(*s);
    renderWindow->display();
}

window::~window()
{
    
}
