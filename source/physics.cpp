#include "physics.h"
#include "extensions.h"

#include <btBulletDynamicsCommon.h>
#include <BulletCollision/CollisionShapes/btBox2dShape.h>

#include <iostream>

void Physics::init(){

	m_solver = std::make_shared<btSequentialImpulseConstraintSolver>();
	m_broadphase = std::make_shared<btDbvtBroadphase>();
	m_configuration = std::make_shared<btDefaultCollisionConfiguration>();
	m_displatcher = std::make_shared<btCollisionDispatcher>( m_configuration.get());
	m_world = std::make_shared<btDiscreteDynamicsWorld>(
			m_displatcher.get(),
			m_broadphase.get(),
			m_solver.get(),
			m_configuration.get()
			);
	m_world->setGravity({0,-9.81,0});

	btVector3 v3{1,1,0};
	auto shape = std::make_shared<btBox2dShape>(v3);
	btVector3 v3_2{32,1,0};
	auto shape2 = std::make_shared<btBox2dShape>(v3_2);
                                                              
	auto motionState = std::make_shared<btDefaultMotionState>(btTransform({0,0,0,1}, {0,0,0}));
	m_motionStates.push_back(motionState);
	m_shapes.push_back(shape2);
	btRigidBody::btRigidBodyConstructionInfo info(0, motionState.get(),shape2.get(), {0,0,0} );
	auto body = std::make_shared<btRigidBody>(info);
	m_world->addRigidBody(body.get());
	m_bodies.push_back(body);


	auto motionState2 = std::make_shared<btDefaultMotionState>(btTransform({0,0,0,1}, {16,16,0}));
	m_motionStates.push_back(motionState2);
	m_shapes.push_back(shape);

	btVector3 fallIn{0,0,0};
	shape->calculateLocalInertia(1, fallIn);
	btRigidBody::btRigidBodyConstructionInfo info2(1, motionState2.get(),shape.get(), fallIn);
	auto body2 = std::make_shared<btRigidBody>(info2);
	m_world->addRigidBody(body2.get());
	m_bodies.push_back(body2);
}

void Physics::add(std::shared_ptr<class btRigidBody> rigidBody){
	m_world->addRigidBody(rigidBody.get());
}

void Physics::update(uint32_t lastDuration){
	// TODO Be sure game always runs 60FPS or higher
	// -> (lastDuration/1000) < maxTimeStep * 1/60
	m_world->stepSimulation(lastDuration/1000.0);

	//for( auto& body : m_bodies){
		//auto t = body->getWorldTransform();
		//std::clog << t.getOrigin().x() << " " << t.getOrigin().y() << std::endl;
	//}
}
