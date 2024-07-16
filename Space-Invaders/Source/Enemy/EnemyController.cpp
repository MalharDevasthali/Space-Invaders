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
		enemy_view->initialize(this);
		enemy_model->initialize();
	}
	void EnemyController::update()
	{
		enemy_view->update();
	}
	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyModel* EnemyController::getEnemyModel()
	{
		return enemy_model;
	}

	EnemyView* EnemyController::getEnemyView()
	{
		return enemy_view;
	}


}
