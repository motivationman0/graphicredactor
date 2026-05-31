#include "render.h"
#include "inputhandler.h"
int main()
{
    Canvas canvas;
    Render render;
    InputHandler inputhandler;
    sf::RenderWindow window(sf::VideoMode({700, 700}), "huh");
    window.setMinimumSize(sf::Vector2u({700, 700}));
    window.setVerticalSyncEnabled(true);
    render.DrawCanvas(window, canvas);
    while (window.isOpen())
    {
        inputhandler.HandleInput(window, canvas);
        if(inputhandler.NeedRender)
        {
            render.DrawCanvas(window, canvas);
            inputhandler.NeedRender = false;
        }
    }
    return 0;
}