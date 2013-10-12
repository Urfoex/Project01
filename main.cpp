#include <iostream>
#include <SDL.h>

int main(){
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
		return -1;
	}

	SDL_Quit();

	return 0;
}
