#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
namespace Enemy
{
	
	EnemyService::EnemyService()
	{
		enemy_controller = new EnemyController();
	}
	
	EnemyService::~EnemyService()
	{
		delete(enemy_controller);
	}
	void EnemyService::initialize()
	{
		enemy_controller->initialize();
	}
	void EnemyService::update()
	{
		enemy_controller->update();
	}
	void EnemyService::render()
	{
		enemy_controller->render();
	}


	EnemyController* EnemyService::spawnEnemy()
	{
		return enemy_controller;
	}
}