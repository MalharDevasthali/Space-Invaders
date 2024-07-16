#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	
	class EnemyView
	{
	private:
		const float enemy_sprite_width = 60.f;
		const float enemy_sprite_height = 60.f;

		sf::String enemy_texture_path = ""; // TODO
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;
		sf::RenderWindow* game_window = nullptr;
		EnemyController* enemy_controller;

		void initializeEnemySprite();
		void scaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();
	};
}

