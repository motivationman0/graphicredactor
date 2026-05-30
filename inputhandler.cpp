#include "inputhandler.h"


InputHandler::InputHandler() : MouseHeldDown(false), NeedRender(false){
}

void InputHandler::HandleInput(sf::RenderWindow& window, Canvas& canvas){
    std::vector<uint8_t>& pixels = canvas.pixels;
    

    if (const std::optional event = window.waitEvent()) {
        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                MouseHeldDown = true;

            }
        }
        if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (mouseReleased->button == sf::Mouse::Button::Left) {
                MouseHeldDown = false;
            }
        }
        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            if (MouseHeldDown) {
                int x = mouseMoved->position.x;
                int y = mouseMoved->position.y;
                if(x>200&&x<1199&&y>200&&y<1199){
                    unsigned int px = x-200;
                    unsigned int py = y-200;
                    size_t index = (py * 1000 + px) * 4;
                    pixels[index] = 100; 
                    pixels[index + 1] = 100;   
                    pixels[index + 2] = 100;  
                    pixels[index + 3] = 255;
                    NeedRender=true;
                }


            }
        }


        if (event->is<sf::Event::Closed>()) {
            window.close();
        }



        if (const auto* resized = event->getIf<sf::Event::Resized>()) {

            sf::View view;
            view.setSize(sf::Vector2f(resized->size));
            view.setCenter(sf::Vector2f(resized->size) / 2.f);
            window.setView(view);
            NeedRender = true;
        }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::Escape) {
                window.close();
            }
        }
    }
}