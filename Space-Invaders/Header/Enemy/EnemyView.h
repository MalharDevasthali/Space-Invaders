#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	
	class EnemyView
	{
	private:
		const float enemy_sprite_width = 60.f;
		const float enemy_sprite_height = 60.f;

		const sf::String subzero_texture_path = "assets/textures/subzero.png";
		const sf::String zapper_texture_path = "assets/textures/zapper.png";
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;
		sf::RenderWindow* game_window = nullptr;
		EnemyController* enemy_controller;

		void initializeEnemySprite(EnemyType type);
		void scaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();
	};
}

