#pragma once

#include "../objectHandler.hpp"

class window
{

private:
    ObjectHandler* objects;

public:
    window(ObjectHandler&);
    ~window();

    void renderLoop();
    void checkEvents();
    void Update();
};