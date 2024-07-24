#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../header/Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;


	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		destroy();
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
		
		destroyFlaggedEnemies();
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
			return new ZapperController(Enemy::EnemyType::ZAPPER, owner_type);
		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO,owner_type);
		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(enemy_controller));
		enemy_list.push_back(enemy_controller);
		return enemy_controller;
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete (enemy_list[i]);
		}
		enemy_list.clear();
	}
	
	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}

	void EnemyService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	

	EnemyType EnemyService::getRandomEnemyType()
	{	
		int randomType = std::rand() % 3;
		return static_cast<Enemy::EnemyType>(randomType); 
	}

}