#include "window.h"
#include <SDL.h>
#include <iostream>

Window::Window() {}

Window::~Window(){
	if( m_event != nullptr){
		delete m_event;
	}
	if( m_window != nullptr){
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	if( m_renderer != nullptr){
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void Window::init(){
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
		throw std::string(SDL_GetError());
	}

	m_window = SDL_CreateWindow(
			m_title, 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			m_windowWidth, 
			m_windowHeight, 
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
			);
	if( m_window == nullptr){
		throw std::string(SDL_GetError());
	}

	m_renderer = SDL_CreateRenderer(
			m_window, 
			-1, 
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE
			);
	if( m_renderer == nullptr){
		throw std::string(SDL_GetError());
	}

	m_event = new SDL_Event();
}

void Window::run(){
	m_running = true;
	while(m_running){
		checkEvents();

	}
}

void Window::checkEvents(){
	while(SDL_PollEvent(m_event)){
		switch(m_event->type){
			case SDL_QUIT:
				{
					m_running = false;
					break;
				}
		}
	}
}

