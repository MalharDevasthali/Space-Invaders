#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
namespace Enemy
{
	Enemy::EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
	}
	EnemyController::~EnemyController()
	{
		delete(enemy_view);
	}
	void EnemyController::initialize()
	{
	}
	void EnemyController::update()
	{
	}
	void EnemyController::render()
	{
	}
}
