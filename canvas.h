#pragma once
#include <vector>
#include <stdint.h>


class Canvas
{
private:
    unsigned int height;
    unsigned int width;;


public:
    unsigned int GetWidth() const { 
        return width; 
    }
    Canvas();   
    std::vector<uint8_t> pixels;




};      