#include "header.h"


int main(int argc, char ** argv) {
    SDL_Window * win;
    SDL_Renderer * rend;

    SDL_Start( &win, &rend );

    SDL_Event e;
    bool close = false,
         pause = false;
    double x = START_X,
           y = START_Y,
           x_vel = 0,
           y_vel = 0;

    while (!close) {
        auto begin = chrono::high_resolution_clock::now();
        while (SDL_PollEvent(&e))
            if ( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
                close = true;
            else if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p )
                pause = true;


        SDL_SetRenderDrawColor( rend, 0, 0, 0, 0 );
        SDL_RenderClear( rend );

        x += x_vel;
        y += y_vel;

        SDL_SetRenderDrawColor( rend, 255, 255, 255, 0 );
        SDL_DrawCircle( rend, int(x), int(y), RADIUS );
        SDL_RenderPresent( rend );

        

        auto end = chrono::high_resolution_clock::now();
        auto dur = end - begin;
        auto dur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        SDL_Delay( 16 - Uint32(dur_ms) );
    }

}