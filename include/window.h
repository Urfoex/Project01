#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>

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

		uint32_t m_lastTicks = 0;
		uint32_t m_diffTicks = 0;
		uint32_t m_till_1000_ticks = 0;
		uint32_t m_fpsCounter = 0;

		struct SDL_Texture *m_fpsCounterTexture = nullptr;
		struct SDL_Color *m_fpsColor = nullptr;
		struct SDL_Rect *m_fpsPosition = nullptr;
		struct _TTF_Font *m_font_mono_12 = nullptr;


		void checkEvents();
		void draw();
		void updateTicks();
		void updateFPS();
};

#endif
