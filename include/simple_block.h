#ifndef SIMPLE_BLOCK_H
#define SIMPLE_BLOCK_H

#include "entity.h"

class SimpleBlock : public Entity {
	public:
		void update(uint32_t lastDuration) override;
		void draw(struct SDL_Renderer *renderer) override;
	protected:
	private:
};

#endif
