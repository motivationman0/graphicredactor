#pragma once
#include <optional>
#include <SFML/Graphics.hpp>
#include "canvas.h"


class InputHandler
{
private:
    bool MouseHeldDown = false;
    int lastX = 0;
    int lastY = 0;
public:
    InputHandler();
    bool NeedRender = false;
    void HandleInput(sf::RenderWindow& window, Canvas& canvas);

};