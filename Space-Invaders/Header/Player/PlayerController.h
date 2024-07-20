#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Player/PlayerModel.h"

namespace Player
{
	
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;

	class PlayerController : public Collision::ICollider
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freez_duration;

		Entity::EntityType owner_type;
		void processPlayerInput();
		void moveLeft();
		void moveRight();

		bool processBulletCollision(ICollider* other_collider);
		bool processPowerupCollision(ICollider* other_collider);
		bool processEnemyCollision(ICollider* other_collider);

		
		void updateFireDuration();
		void updateFreezDuration();

		void processBulletFire();
		void FireBullet(bool b_tripple_laser = false);
		void FireBullet(sf::Vector2f position);

		void updatePowerupDuration();
		void disableShield();
		void disableRapidFire();
		void disableTrippleLaser();
		void freezPlayer();

	public:
		PlayerController(Entity::EntityType owner_type);
		~PlayerController();

		void initialize();
		void update();
		void render();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;

		sf::Vector2f getPlayerPosition();
		PlayerModel* getPlayerModel();
		PlayerView* getPlayerView();
		Entity::EntityType getOwnerEntityType();

		void reset();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

	};
}