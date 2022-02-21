#include "window/window.hpp"
#include "SFML/System.hpp"
#include "objectHandler.hpp"

int main(int, char**) 
{
    ObjectHandler o;
    window w (o);
    w.renderLoop();
    return 0;
}
