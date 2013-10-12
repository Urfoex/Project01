#ifndef WINDOW_H
#define WINDOW_H

class SDL_window;
class SDL_render;

class Window{
	public:
		Window();
		void init();
	protected:
	private:
        SDL_window *m_window = nullptr;
		SDL_render *m_render = nullptr;

};

#endif
