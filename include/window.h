#ifndef WINDOW_H
#define WINDOW_H

class Window{
	public:
		Window();
		~Window();

		void init();
		void run();
	protected:
	private:
        struct SDL_Window *m_window = nullptr;
		struct SDL_Renderer *m_renderer = nullptr;
		const char *m_title = "Project01";
		const int m_windowWidth = 1024;
		const int m_windowHeight = 768;

		bool m_running = false;
		union SDL_Event *m_event = nullptr;

		void checkEvents();
};

#endif
