#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <vector>
#include <memory>

class Game{
	public:
		void init();
		void update(uint32_t lastDuration);
		void draw(struct SDL_Renderer *renderer);
	protected:
	private:
		std::shared_ptr<class Physics> m_physics = nullptr;
		std::vector<std::shared_ptr<class Entity>> m_entities;

};

#endif
