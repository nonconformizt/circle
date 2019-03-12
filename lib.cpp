#include "header.h"

void SDL_DrawCircle(SDL_Renderer *Renderer, int32_t _x, int32_t _y, int32_t radius)
{
    int32_t x = radius - 1;
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err = tx - (radius << 1); // shifting bits left by 1 effectively
    // doubles the value. == tx - diameter
    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(Renderer, _x + x, _y - y);
        SDL_RenderDrawPoint(Renderer, _x + x, _y + y);
        SDL_RenderDrawPoint(Renderer, _x - x, _y - y);
        SDL_RenderDrawPoint(Renderer, _x - x, _y + y);
        SDL_RenderDrawPoint(Renderer, _x + y, _y - x);
        SDL_RenderDrawPoint(Renderer, _x + y, _y + x);
        SDL_RenderDrawPoint(Renderer, _x - y, _y - x);
        SDL_RenderDrawPoint(Renderer, _x - y, _y + x);

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

bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer)
{
    if ( SDL_Init( SDL_INIT_VIDEO ) != 0) {
        cout << "Initialization failed! \n";
        return false;
    }
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    *window = SDL_CreateWindow("Snow",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH,
                               WINDOW_HEIGHT,
                               SDL_WINDOW_ALLOW_HIGHDPI);
    if ( *window == nullptr) {
        cout << "Cannot create window\n";
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer( *window, -1, SDL_RENDERER_ACCELERATED );
    if ( *renderer == nullptr ) {
        cout << "Cannot create renderer\n";
        SDL_DestroyWindow( *window );
        SDL_Quit();
        return false;
    }
    SDL_RenderClear( *renderer );
    SDL_RenderPresent( *renderer );
    return true;
}

