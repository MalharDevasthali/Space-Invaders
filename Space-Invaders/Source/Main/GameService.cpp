#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"

namespace Main
{
	using namespace Global;
	GameService::GameService() {
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService() {
		destroy();
	}

	void GameService::ignite() {
		service_locator = ServiceLocator::getInstance();
		initialize();
	}


	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy()
	{

	}

	void GameService::update() {

		service_locator->getEventService()->processEvents();
		service_locator->update();
	}


	void GameService::render() {
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning() {

		return service_locator->getGraphicService()->isGameWindowOpen();
	}

}