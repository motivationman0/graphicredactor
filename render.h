#pragma once
#include <SFML/Graphics.hpp>
#include "canvas.h"

class Render {
    private:
        sf::Texture m_texture;
        bool m_isTextureInitialized = false;
    
    public:
        void DrawCanvas(sf::RenderWindow& window, const std::vector<std::uint8_t>& pixels);
    };