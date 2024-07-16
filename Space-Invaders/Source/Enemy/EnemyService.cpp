#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	
	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		delete(enemy);
	}
	void EnemyService::initialize()
	{
		spawnEnemy();
	}
	void EnemyService::update()
	{
		enemy->update();
	}
	void EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		//creates and intis an enemy controller
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}
}