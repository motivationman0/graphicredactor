#include "render.h"
#include <stdint.h>



void Render::DrawCanvas(sf::RenderWindow& window, const std::vector<std::uint8_t>& pixels) {
    // 1. Очищаем окно серым цветом
    window.clear(sf::Color(170, 170, 170, 255));

    unsigned int width = 1000;
    unsigned int height = 1000;

    // 2. Инициализируем текстуру ОДИН раз за все время работы программы
    if (!m_isTextureInitialized) {
        if (m_texture.resize({width, height})) {
            m_isTextureInitialized = true;
        } else {
            // Если видеокарта не смогла выделить память, выходим из функции
            return; 
        }
    }

    // 3. Просто обновляем пиксели в уже существующей текстуре (это работает мгновенно)
    m_texture.update(pixels.data());

    // 4. Создаем спрайт и привязываем его к нашей постоянной текстуре
    sf::Sprite sprite(m_texture);
    sprite.setPosition({200.f, 200.f}); 

    // 5. Рисуем спрайт в буфер кадра
    window.draw(sprite);
    
    // 6. Выводим всё, что нарисовали, на экран (всегда в конце отрисовки кадра)
    window.display();
}