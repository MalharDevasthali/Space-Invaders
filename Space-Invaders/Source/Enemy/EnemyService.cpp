#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Enemy;
	using namespace Controller;

	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]);
	}
	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
		spawnEnemy();
	}
	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++)
			enemy_list[i]->update();
	}
	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) 
			enemy_list[i]->render();
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy(); 
			spawn_timer = 0.0f; 
		}
	}
	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);
		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);
		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());

		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	EnemyType EnemyService::getRandomEnemyType()
	{	
		int randomType = std::rand() % 3;
		return static_cast<Enemy::EnemyType>(randomType); 
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete(enemy_controller);
	}
}