#pragma once

class window
{

public:
    window();
    ~window();

    void renderLoop();
    void checkEvents();
    void Update();
};