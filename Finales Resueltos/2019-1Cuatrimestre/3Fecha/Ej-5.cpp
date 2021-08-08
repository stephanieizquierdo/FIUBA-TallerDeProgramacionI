/*Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo*/

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>

#define WEIGHT 640
#define HEIGHT 480

int main(){
    SDL_Window* window = SDL_CreateWindow("Diagonales", 100, 100, WEIGHT, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);

    SDL_Event exit;
    int quit = 0;
    while(!quit){
        if(SDL_PollEvent(&exit)){
            if(exit.type == SDL_QUIT) quit = 1;
        }
        lineRGBA(render, 0, 0, WEIGHT, HEIGHT, 0xff, 0x00, 0x00, 0xff);
        lineRGBA(render, WEIGHT, 0, 0, HEIGHT, 0xff, 0x00, 0x00, 0xff);
        SDL_RenderPresent(render);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
