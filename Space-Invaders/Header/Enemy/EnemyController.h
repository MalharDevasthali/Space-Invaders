#pragma once
#include<SFML/Graphics.hpp>
namespace Enemy
{
	class EnemyView;
	class EnemyModel;
	enum class EnemyType;
	enum class EnemyState;

	class EnemyController
	{
	protected:

		float rate_of_fire = 3.f; //we want to fire the bullet every 3 seconds
		float elapsed_fire_duration = 0.f; //variable to check how long it has been since we last fired


		EnemyView* enemy_view;
		EnemyModel* enemy_model;


		virtual void fireBullet() = 0;
		virtual void move() = 0;

		void updateFireTimer();
		void processBulletFire();

		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		EnemyModel* getEnemyModel();
		EnemyView* getEnemyView();
		
		EnemyType getEnemyType();
		EnemyState getEnemyState();
	};
}
