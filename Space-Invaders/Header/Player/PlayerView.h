#pragma once
#include<SFML/Graphics.hpp>
namespace Player
{
	class PlayerController;

	class PlayerView
	{

	private:
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;

		sf::String player_texture_path = "assets/textures/player_ship.png";
		sf::Texture player_texture;
		sf::Sprite player_sprite;
		sf::RenderWindow* game_window = nullptr;
		PlayerController* player_controller;

		void initializePlayerSprite();
		void scalePlayerSprite();


	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

	};
}