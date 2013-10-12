#include "window.h"
#include <SDL.h>
#include <iostream>

Window::Window() {}

Window::~Window(){
	if( m_window != nullptr){
	}
}

void Window::init(){
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
		throw std::string(SDL_GetError());
	}
}


