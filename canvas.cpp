#include "canvas.h"




Canvas::Canvas() 
    : height(1000), 
      width(1000),
      pixels(1000*1000*4, uint8_t{255}){
}
