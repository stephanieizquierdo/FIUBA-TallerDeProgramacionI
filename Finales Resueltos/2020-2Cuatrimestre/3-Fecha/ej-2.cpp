int main(){
    SDL_Window* window = SDL_CreateWindow("Rombo", 100, 100, ANCHO, ALTURA, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = sld_CreateRender(window, -1, SDL_RENDERER_ACELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Event exit;
    bool salir = false;
    const short rombo_x[] = {ANCHO/2, ANCHO, ANCHO/2, 0};
    const short rombo_y[] = {0, ALTURA/2, ALTURA, ALTURA/2};
    const int points = sizeof(rombo_x) / sizeof(rombo_x[0]);
    while(!salir){
        if(SDL_PollEvent(&exit)){
            if(exit==SLD_QUIT){
                salir = true;
            }
        }
        polygonRGBA(render, rombo_x, rombo_y, rombo_points, 0x00, 0x00, 0xff, 0xff);
        SDL_RenderPresent(render);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);

    SDL_Quit();
    return 0;
}
