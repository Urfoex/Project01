#include "window.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

//void Window::Deleter_TTF_Font(TTF_Font *font){
	//TTF_CloseFont(font);
//}

Window::Window() {

}

Window::~Window(){
	if( m_fpsCounterTexture != nullptr){
		SDL_DestroyTexture(m_fpsCounterTexture);
		m_fpsCounterTexture = nullptr;
	}
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

	TTF_Quit();
	SDL_Quit();
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
			SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC
			| SDL_RENDERER_TARGETTEXTURE
			);
	if( m_renderer == nullptr){
		throw std::string(SDL_GetError());
	}

	if( TTF_Init() != 0){
		throw std::string(TTF_GetError());
	}
                   
	//auto f = std::make_shared<TTF_Font>( TTF_OpenFont("font/LiberationMono-Regular.ttf", 12), Window::Deleter_TTF_Font);
	// TODO Create "SavePointer"
	// Take * pointer
	// hold it till destructor
	// delete with delete or custom method
	//m_font_mono_12 = 
	//
	//
	
    m_font_mono_12 = std::shared_ptr<TTF_Font>(
			TTF_OpenFont("font/LiberationMono-Regular.ttf", 12),
			[](TTF_Font *ptr){ TTF_CloseFont(ptr);}
			);

	//m_test = ext::save_ptr<TTF_Font>([](){ 
			//return TTF_OpenFont("font/LiberationMono-Regular.ttf", 12);
			//}, [](TTF_Font *ptr){ TTF_CloseFont(ptr);});
	if( m_font_mono_12 == nullptr){
		throw std::string(TTF_GetError());
	}

	m_event = new SDL_Event();
	m_fpsColor = std::make_shared<SDL_Color>();
	*m_fpsColor = {0, 255, 0, 255};

	m_fpsPosition = std::make_shared<SDL_Rect>();
	*m_fpsPosition = {4,4,0,0};

	//throw std::string("nothing");
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
	if( m_fpsCounterTexture != nullptr){
		SDL_DestroyTexture(m_fpsCounterTexture);
		m_fpsCounterTexture = nullptr;
	}
	m_fpsCounterTexture = SDL_CreateTextureFromSurface(
			m_renderer, 
			fpsCounterText
			);
	m_fpsCounter = 0;
	m_fpsPosition->w = fpsCounterText->w;
	m_fpsPosition->h = fpsCounterText->h;
	SDL_FreeSurface(fpsCounterText);
}

void Window::draw(){
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_fpsCounterTexture, nullptr, m_fpsPosition.get());

	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(m_renderer, 0, 393, 1024, 393); 
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(m_renderer);

	++m_fpsCounter;
}
