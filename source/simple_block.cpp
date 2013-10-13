#include "simple_block.h"
#include "physics.h"
#include <btBulletDynamicsCommon.h>
#include <BulletCollision/CollisionShapes/btBox2dShape.h>
#include <SDL.h>
#include <iostream>

void SimpleBlock::init(){}

void SimpleBlock::init(Physics &physics){
	btVector3 halfExtend{1,1,0};
	m_collisionShape = std::make_shared<btBox2dShape>(halfExtend);
	m_motionState = std::make_shared<btDefaultMotionState>(btTransform({0,0,0,1}, {16,16,0}));

	btVector3 fallIn{0,0,0};
	m_collisionShape->calculateLocalInertia(1, fallIn);
	btRigidBody::btRigidBodyConstructionInfo info(1, m_motionState.get(), m_collisionShape.get(), fallIn);
	m_rigidBody = std::make_shared<btRigidBody>(info);
	physics.add(m_rigidBody);
	//m_world->addRigidBody(m_rigidBody.get());
	//m_bodies.push_back(body2);

}

void SimpleBlock::update(uint32_t lastDuration){
	auto t = m_rigidBody->getWorldTransform();
	std::clog << t.getOrigin().x() << " " << t.getOrigin().y() << std::endl;
}

void SimpleBlock::draw(struct SDL_Renderer *renderer){
	// TODO Create and use a texture.
	uint8_t rgba[4];
	SDL_GetRenderDrawColor(renderer, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_Rect rect{10,10,100,100};
    SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

}
