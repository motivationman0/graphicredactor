#pragma once
#include <vector>
#include <stdint.h>


class Canvas
{
private:
    unsigned int height;
    unsigned int width;
    int offsetx;
    int offsety;
    std::vector<uint8_t> pixels;


public:

    int GetOffsetX() const { return offsetx; }
    int GetOffsetY() const { return offsety; }
    unsigned int GetWidth() const { return width; }
    unsigned int GetHeight() const { return height; }
    const std::vector<uint8_t>& GetPixels() const { return pixels; }
    std::vector<uint8_t>& GetPixels() { return pixels; }
    Canvas();  

};