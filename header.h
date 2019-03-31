/* Libraries */
#include <iostream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Classes */
#include "circle.class/circle.h"

#undef main

using namespace std;

#define WINDOW_WIDTH (960)
#define WINDOW_HEIGHT (720)

#define START_X (WINDOW_WIDTH / 2)
#define START_Y (WINDOW_HEIGHT / 2)
#define RADIUS 40
#define SPEED 7.0

bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);