#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"
namespace Enemy
{
	class EnemyController;
	enum class EnemyType;
	
	class EnemyView
	{
	private:
		const float enemy_sprite_width = 60.f;
		const float enemy_sprite_height = 60.f;

		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		EnemyController* enemy_controller;
		UI::UIElement::ImageView* enemy_image;


	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		void createUIElements();
		const sf::Sprite& getEnemySprite();
		sf::String getEnemyTexturePath();
	};
}

