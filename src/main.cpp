#include "window/window.hpp"
#include "SFML/System.hpp"

int main(int, char**) 
{
    window w;
    sf::Thread t (&window::renderLoop, &w);
    t.launch();
    t.wait();
    return 0;
}
