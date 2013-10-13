#include "simple_block.h"
#include <SDL.h>
#include <iostream>

void SimpleBlock::update(uint32_t lastDuration){
}

void SimpleBlock::draw(struct SDL_Renderer *renderer){
	// TODO Create and use a texture.
	uint8_t rgba[4];
	SDL_GetRenderDrawColor(renderer, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_Rect rect{10,10,100,100};
    SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

}
