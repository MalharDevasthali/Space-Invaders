#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Main;

	GameplayService::GameplayService() {gameplay_controller = new GameplayController();}

	GameplayService::~GameplayService() { delete(gameplay_controller); }

	void GameplayService::initialize() { gameplay_controller->initialize(); }

	void GameplayService::update() 
	{ 
		switch (GameService::getGameState())
		{
		case GameState::GAMEPLAY:
			return gameplay_controller->update();
			break;
		}
	}

	void GameplayService::render() 
	{ 
		switch (GameService::getGameState())
		{
		case GameState::GAMEPLAY:
			return gameplay_controller->render();
			break;
		}
	}
}