/*
Copyright (c) 2025 Haydar Can Karabacak
All rights reserved.
*/


#include<SDL3/SDL.h>


int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_CreateWindowAndRenderer("RPG Game",1080,720,0,&window,&renderer);

    bool gameState = true;

    while (gameState)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT) gameState = false;
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,0x87,0xCE,0xEB,0xFF);
        SDL_RenderPresent(renderer);
        
    }
    

    SDL_Quit();
    return 0;
}