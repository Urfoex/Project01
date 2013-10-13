#include "extensions.h"
#include "window.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

Window::Window() {
}

Window::~Window(){
	TTF_Quit();
	SDL_Quit();
}

void Window::init(){
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0){
		throw std::string(SDL_GetError());
	}

	m_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
				m_title, 
				SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED, 
				m_windowWidth, 
				m_windowHeight, 
				SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
				),
			[](SDL_Window *ptr){SDL_DestroyWindow(ptr);}
			);
	if( m_window == nullptr){
		throw std::string(SDL_GetError());
	}

	m_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(
				m_window.get(), 
				-1, 
				SDL_RENDERER_ACCELERATED
				| SDL_RENDERER_PRESENTVSYNC
				| SDL_RENDERER_TARGETTEXTURE
				),
			[](SDL_Renderer *ptr){ SDL_DestroyRenderer(ptr); }
			);
	if( m_renderer == nullptr){
		throw std::string(SDL_GetError());
	}

	if( TTF_Init() != 0){
		throw std::string(TTF_GetError());
	}

	m_font_mono_12 = std::shared_ptr<TTF_Font>(
			TTF_OpenFont("font/LiberationMono-Regular.ttf", 12),
			[](TTF_Font *ptr){ TTF_CloseFont(ptr);}
			);

	if( m_font_mono_12 == nullptr){
		throw std::string(TTF_GetError());
	}

	m_event = std::make_shared<SDL_Event>();
	m_fpsColor = ext::make_shared<SDL_Color>({0, 255, 0, 255});
	m_fpsPosition = ext::make_shared<SDL_Rect>({4,4,0,0});
}

void Window::run(){
	m_running = true;
	while(m_running){
		updateTicks();
		checkEvents();
		draw();

	}
}

void Window::checkEvents(){
	while(SDL_PollEvent(m_event.get())){
		switch(m_event->type){
			case SDL_QUIT:
				{
					m_running = false;
					break;
				}
		}
	}
}

void Window::updateTicks(){
	auto currentTicks = SDL_GetTicks();
	m_diffTicks = currentTicks - m_lastTicks;
	m_lastTicks = currentTicks;
	m_till_1000_ticks += m_diffTicks;
	if( m_till_1000_ticks >= 1000){
		updateFPS();
		m_till_1000_ticks = 0;
	}
}

void Window::updateFPS(){
	//std::clog << "FPS: " << m_fpsCounter << std::endl;
	auto fpsCounterText = TTF_RenderText_Solid(
			m_font_mono_12.get(), 
			std::to_string(m_fpsCounter).c_str(), 
			*m_fpsColor
			);
	if( fpsCounterText == nullptr){
		std::cerr << TTF_GetError() << std::endl;
		return;
	}
	m_fpsCounterTexture = std::shared_ptr<SDL_Texture>(
			SDL_CreateTextureFromSurface(
				m_renderer.get(), 
				fpsCounterText
				),
			[](SDL_Texture *ptr){ SDL_DestroyTexture(ptr);}
			);
	m_fpsCounter = 0;
	m_fpsPosition->w = fpsCounterText->w;
	m_fpsPosition->h = fpsCounterText->h;
	SDL_FreeSurface(fpsCounterText);
}

void Window::draw(){
	SDL_RenderClear(m_renderer.get());
	SDL_RenderCopy(m_renderer.get(), m_fpsCounterTexture.get(), nullptr, m_fpsPosition.get());

	SDL_SetRenderDrawColor(m_renderer.get(), 255, 0, 0, 255);
	SDL_RenderDrawLine(m_renderer.get(), 0, 393, 1024, 393); 
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer.get());

	++m_fpsCounter;
}
