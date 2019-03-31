#include "header.h"


int main(int argc, char ** argv) {
    SDL_Window * win;
    SDL_Renderer * rend;

    SDL_Start( &win, &rend );

    SDL_Event e;
    bool close = false;
    double x = START_X,
           y = START_Y,
           x_vel = 0,
           y_vel = 0;

    auto begin = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto dur_ms = chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    Circle circle(rend);

    while (!close) {
        begin = chrono::high_resolution_clock::now();
        while (SDL_PollEvent(&e))
            if ( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
                close = true;
            else if ( e.type == SDL_MOUSEBUTTONDOWN && e.button.state == SDL_PRESSED ) {
                if ( e.button.button == SDL_BUTTON_LEFT ) {
                    cout << "left click! \n";
                    circle.change_direction(e.button.x, e.button.y, 1);
                }
                else if ( e.button.button == SDL_BUTTON_RIGHT ) {
                    cout << "right click! \n";
                    circle.change_direction(e.button.x, e.button.y, -1);
                }
            }


        SDL_SetRenderDrawColor( rend, 0, 0, 0, 0 );
        SDL_RenderClear( rend );

        circle.next_frame();
        SDL_RenderPresent( rend );

        end = chrono::high_resolution_clock::now();
        dur = end - begin;
        dur_ms = chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        SDL_Delay( 16 - (int) dur_ms < 0 ? 0 : 16 - (int) dur_ms );
    }

}