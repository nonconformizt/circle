
#include "../header.h"

Circle::Circle(SDL_Renderer *renderer) {
    srand((unsigned int)time(nullptr));
    rend = renderer;
    x = START_X;
    y = START_Y;
    x_dir = 0.0;
    y_dir = 0.0;
}


void Circle::draw(int32_t _x, int32_t _y)
{
    int32_t radius = RADIUS - 1;
    int32_t x = radius - 1;
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err = tx - (radius << 1); // shifting bits left by 1 effectively
    // doubles the value. == tx - diameter
    SDL_SetRenderDrawColor( rend, r, g, b, 0 );

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(rend, _x + x, _y - y);
        SDL_RenderDrawPoint(rend, _x + x, _y + y);
        SDL_RenderDrawPoint(rend, _x - x, _y - y);
        SDL_RenderDrawPoint(rend, _x - x, _y + y);
        SDL_RenderDrawPoint(rend, _x + y, _y - x);
        SDL_RenderDrawPoint(rend, _x + y, _y + x);
        SDL_RenderDrawPoint(rend, _x - y, _y - x);
        SDL_RenderDrawPoint(rend, _x - y, _y + x);

        if (err <= 0)
        {
            y++;
            err += ty;
            ty += 2;
        }
        if (err > 0)
        {
            x--;
            tx += 2;
            err += tx - (radius << 1);
        }
    }
}

void Circle::change_direction(int new_x, int new_y, int dir) {
    double vect_x = new_x - x;
    double vect_y = new_y - y;
    double vect_len = sqrt(vect_x*vect_x + vect_y*vect_y);

    x_dir = dir * vect_x / vect_len;
    y_dir = dir * vect_y / vect_len;
}

void Circle::change_color() {
    r = Uint8 (rand() % 160);
    g = Uint8 (rand() % 160);
    b = Uint8 (rand() % 160);
}

void Circle::next_frame() {
    x += SPEED * x_dir;
    y += SPEED * y_dir;

    if (WINDOW_WIDTH - int(x) < RADIUS || int(x) < RADIUS || WINDOW_HEIGHT - int(y) < RADIUS || int(y) < RADIUS) {
        change_color();
        change_direction(START_X, START_Y, 1);
    }

    draw(int32_t(x), int32_t(y));
}