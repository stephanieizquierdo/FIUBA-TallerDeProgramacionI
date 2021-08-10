/*
Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>


#define WIDTH 640
#define HEIGHT 480

int main(){
    SDL_Window* window = SDL_CreateWindow("Rombo",100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    const short rombo_x[] = {WIDTH/2, WIDTH, WIDTH/2, 0};
    const short rombo_y[] = {0, HEIGHT/2, HEIGHT, HEIGHT/2};

    const int rombo_points = sizeof(rombo_x)/ sizeof(rombo_x[0]);

    SDL_Event exit;
    int quit = 0;
    while(!quit){
        if(SDL_PollEvent(&exit)){
            if(exit.type==SDL_QUIT) quit = 1;
        }
        polygonRGBA(render, rombo_x, rombo_y, rombo_points, 0x00, 0xff, 0x00, 0xff);
        SDL_RenderPresent(render);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
