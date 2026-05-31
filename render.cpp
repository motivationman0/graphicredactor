#include "render.h"

void Render::DrawCanvas(sf::RenderWindow& window, const Canvas& canvas) 
{
    window.clear(sf::Color(170, 170, 170, 255));

    unsigned int width = canvas.GetWidth();
    unsigned int height = canvas.GetHeight();
    const std::vector<uint8_t>& pixels = canvas.GetPixels();

    if (!m_isTextureInitialized) 
    {
        if (m_texture.resize({width, height})) 
        {
            m_isTextureInitialized = true;
        } else 
        {
            return; 
        }
    }

    m_texture.update(pixels.data());
    sf::Sprite sprite(m_texture);
    sprite.setPosition({static_cast<float>(canvas.GetOffsetX()), static_cast<float>(canvas.GetOffsetY())});
    window.draw(sprite);
    window.display();
}