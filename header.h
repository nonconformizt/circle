#include <iostream>
#include <cmath>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#undef main

using namespace std;

#define WINDOW_WIDTH (960)
#define WINDOW_HEIGHT (720)

#define SPEED 10

void SDL_DrawCircle(SDL_Renderer *Renderer, int32_t _x, int32_t _y, int32_t radius);

bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);