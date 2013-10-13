#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <glm/glm.hpp>

class Entity{
	public:
		virtual void init() = 0;
		virtual void update(uint32_t lastDuration) = 0;
		virtual void draw(struct SDL_Renderer *renderer) = 0;
	protected:
		glm::vec2 m_position;
	private:
};

#endif
