#include "canvas.h"

Canvas::Canvas() 
    : height(500), 
      width(500),
      offsetx(50),
      offsety(50),
      pixels(height*width*4, uint8_t{255}){}
