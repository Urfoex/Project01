#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <memory>

class Window{
	public:
		Window();
		~Window();

		void init();
		void run();

	protected:
	private:
		std::shared_ptr<struct SDL_Window> m_window = nullptr;
		struct SDL_Renderer *m_renderer = nullptr;
		const char *m_title = "Project01";
		const int m_windowWidth = 1024;
		const int m_windowHeight = 768;

		bool m_running = false;
		std::shared_ptr<union SDL_Event> m_event = nullptr;

		uint32_t m_lastTicks = 0;
		uint32_t m_diffTicks = 0;
		uint32_t m_till_1000_ticks = 0;
		uint32_t m_fpsCounter = 0;

		std::shared_ptr<struct SDL_Texture> m_fpsCounterTexture = nullptr;
		std::shared_ptr<struct SDL_Color> m_fpsColor = nullptr;
		std::shared_ptr<struct SDL_Rect> m_fpsPosition = nullptr;

		std::shared_ptr<struct _TTF_Font> m_font_mono_12 =  nullptr;


		void checkEvents();
		void draw();
		void updateTicks();
		void updateFPS();
};

#endif
