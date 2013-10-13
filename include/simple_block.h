#ifndef SIMPLE_BLOCK_H
#define SIMPLE_BLOCK_H

#include "entity.h"
#include <memory>

class SimpleBlock : public Entity {
	public:
		void init(class Physics &physics);
		void init() override;
		void update(uint32_t lastDuration) override;
		void draw(struct SDL_Renderer *renderer) override;
	protected:
	private:
		std::shared_ptr<class btDefaultMotionState> m_motionState = nullptr;
		std::shared_ptr<class btRigidBody> m_rigidBody = nullptr;
		std::shared_ptr<class btCollisionShape> m_collisionShape = nullptr;
};

#endif
