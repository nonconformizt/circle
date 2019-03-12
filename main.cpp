#include "header.h"


int main(int argc, char ** argv) {

    SDL_Window * win;
    SDL_Renderer * rend;

    SDL_Start( &win, &rend );

    SDL_RenderClear( rend );
    SDL_SetRenderDrawColor( rend, 255, 255, 255, 0 );
    SDL_DrawCircle( rend, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 30 );
    SDL_RenderPresent( rend );
    SDL_Delay( 5000 );
}