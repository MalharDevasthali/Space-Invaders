#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuController
		{
		private:

			sf::RenderWindow* game_window;

		public:
			MainMenuController();

			void initialize();
			void update();
			void render();

		};
	}
}