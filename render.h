#pragma once
#include <SFML/Graphics.hpp>
#include <stdint.h>
#include "canvas.h"

class Render 
{
private:
    sf::Texture m_texture;
    bool m_isTextureInitialized = false;

public:
    void DrawCanvas(sf::RenderWindow& window, const Canvas& canvas);
};