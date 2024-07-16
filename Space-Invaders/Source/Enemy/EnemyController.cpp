#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
namespace Enemy
{
	Enemy::EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}
	EnemyController::~EnemyController()
	{
		delete(enemy_view);
		delete(enemy_model);

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
