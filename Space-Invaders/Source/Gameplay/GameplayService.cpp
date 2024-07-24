#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Main;
	using namespace Global;
	using namespace Player;
	using namespace Enemy;
	using namespace Element;
	using namespace Bullet;

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
	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		//ServiceLocator::getInstance()->getEnemyService()->reset();
		ServiceLocator::getInstance()->getBulletService()->reset();
		//ServiceLocator::getInstance()->getElementService()->reset();
	}
}