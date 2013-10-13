#include "game.h"
#include "physics.h"
#include "simple_block.h"

void Game::init(){
	m_physics = std::make_shared<Physics>();
	m_physics->init();
	
	m_entities.push_back(std::make_shared<SimpleBlock>());

}

void Game::update(uint32_t lastDuration){
	m_physics->update(lastDuration);
	for(auto& entity : m_entities)
		entity->update(lastDuration);
}

void Game::draw(struct SDL_Renderer *renderer){
	for(auto& entity : m_entities)
		entity->draw(renderer);
}
