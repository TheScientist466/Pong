#include <SFML/Graphics.hpp>
#include "windowConfig.hpp"
#include "window.hpp"

sf::RenderWindow* renderWindow = new sf::RenderWindow(sf::VideoMode(windowConfig::windowSize.x, windowConfig::windowSize.y), windowConfig::windowTitle, sf::Style::Close);;
sf::Event windowEvent;

window::window()
{

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
    }
}

void window::Update()
{
    renderWindow->clear();
    renderWindow->display();
}

window::~window()
{
    
}
