#include "game.h"
#include "simple_block.h"

void Game::init(){
	m_entities.push_back(std::make_shared<SimpleBlock>());
}

void Game::update(uint32_t lastDuration){
	for(auto& entity : m_entities)
		entity->update(lastDuration);
}

void Game::draw(struct SDL_Renderer *renderer){
	for(auto& entity : m_entities)
		entity->draw(renderer);
}
