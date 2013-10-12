#ifndef WINDOW_H
#define WINDOW_H

class Window{
	public:
		Window();
		~Window();

		void init();
	protected:
	private:
        class SDL_Window *m_window = nullptr;
		class SDL_Renderer *m_renderer = nullptr;
		const char *m_title = "Project01";
		const int m_windowWidth = 1024;
		const int m_windowHeight = 768;

};

#endif
