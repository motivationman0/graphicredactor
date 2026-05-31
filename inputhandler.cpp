#include "inputhandler.h"


void SetPixel(unsigned int px, unsigned int py, std::vector<uint8_t>& pixels, unsigned int width){
    size_t index = (py * width + px) * 4;
    pixels[index] = 100; 
    pixels[index + 1] = 100;   
    pixels[index + 2] = 100;  
    pixels[index + 3] = 255;
}

InputHandler::InputHandler() : MouseHeldDown(false), NeedRender(false), HasPrevious(false){
}

void InputHandler::HandleInput(sf::RenderWindow& window, Canvas& canvas)
{
    std::vector<uint8_t>& pixels = canvas.GetPixels();
    

    if (const std::optional event = window.waitEvent()) 
    {
        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) 
        {
            if (mousePressed->button == sf::Mouse::Button::Left) 
            {
                MouseHeldDown = true;

            }
        }
        if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) 
        {
            if (mouseReleased->button == sf::Mouse::Button::Left) 
            {
                MouseHeldDown = false;
                HasPrevious = false;
            }
        }
        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) 
        {
            if (MouseHeldDown) 
            {
                int x = mouseMoved->position.x;
                int y = mouseMoved->position.y;
                if(x>canvas.GetOffsetX()&&x<canvas.GetWidth()+canvas.GetOffsetX()&&y>canvas.GetOffsetY()&&y<canvas.GetHeight()+canvas.GetOffsetY())
                {
                    unsigned int px = x-canvas.GetOffsetX();
                    unsigned int py = y-canvas.GetOffsetY();
                    SetPixel(px, py, pixels, canvas.GetWidth());

                    NeedRender=true;
                }
            }
        }

        if (event->is<sf::Event::Closed>()) 
        {
            window.close();
        }

        if (const auto* resized = event->getIf<sf::Event::Resized>()) 
        {

            sf::View view;
            view.setSize(sf::Vector2f(resized->size));
            view.setCenter(sf::Vector2f(resized->size) / 2.f);
            window.setView(view);
            NeedRender = true;
        }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) 
        {
            if (keyPressed->code == sf::Keyboard::Key::Escape) 
            {
                window.close();
            }
        }
    }
}
