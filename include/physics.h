#ifndef PHYSICS_H
#define PHYSICS_H

#include <memory>
#include <cstdint>
#include <vector>

class Physics {
	public:
		void init();
		void update( uint32_t lastDuration);
	protected:
	private:
		std::shared_ptr<class btSequentialImpulseConstraintSolver> m_solver = nullptr;
		std::shared_ptr<class btDbvtBroadphase> m_broadphase = nullptr;
		std::shared_ptr<class btDefaultCollisionConfiguration> m_configuration = nullptr;
		std::shared_ptr<class btCollisionDispatcher> m_displatcher = nullptr;
		std::shared_ptr<class btDiscreteDynamicsWorld> m_world = nullptr;
		std::vector<std::shared_ptr<class btDefaultMotionState>> m_motionStates;
		std::vector<std::shared_ptr<class btCollisionShape>> m_shapes;
		std::vector<std::shared_ptr<class btRigidBody>> m_bodies;

};

#endif
