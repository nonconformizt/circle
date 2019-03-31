#ifndef CIRCLE_CIRCLE_H
#define CIRCLE_CIRCLE_H


#include <SDL_render.h>

class Circle {
private:
    double
        x, y, // текущие координаты центра
        x_dir, y_dir; // коорд. ортонормированного вектора
    Uint8 r, g, b; // color
    SDL_Renderer * rend;

private:
    void draw(int32_t _x, int32_t _y);
    void change_color();

public:
    Circle( SDL_Renderer * rend );
    void next_frame();
    void change_direction(int new_x, int new_y, int dir); // x and y are pixels
};


#endif
