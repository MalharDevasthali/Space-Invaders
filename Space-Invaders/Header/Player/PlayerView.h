#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"
namespace Player
{
	class PlayerController;

	class PlayerView
	{

	private:
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;


		sf::Texture player_texture;
		sf::Sprite player_sprite;
	
		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;
	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void createUIElements();
		void initializeImage();
		void update();
		void render();

		const sf::Sprite& getPlayerSprite();

	};
}