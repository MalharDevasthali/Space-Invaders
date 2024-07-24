#pragma once
#include <vector>
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	
	private:
		const float spawn_interval = 2.f;

		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*> flagged_enemy_list;
		float spawn_timer;
		Entity::EntityType owner_type = Entity::EntityType::ENEMY;

		void updateSpawnTimer();
		void processEnemySpawn();
		EnemyType getRandomEnemyType();

		EnemyController* createEnemy(EnemyType enemy_type);
		void destroy();
		
		void destroyFlaggedEnemies();

	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();
	
		void reset();
		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	
	};
}
