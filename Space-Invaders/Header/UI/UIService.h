#pragma once
#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	using namespace Interface;
	class UIService
	{
	private:
		MainMenu::MainMenuController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		IUIController* getCurrentUIController();
		
		void destroy();


	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void showScreen();
		void render();
	};
}
