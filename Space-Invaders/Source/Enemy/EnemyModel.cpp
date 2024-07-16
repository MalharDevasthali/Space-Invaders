#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy
{
	EnemyModel::EnemyModel()
	{
	}
	EnemyModel::~EnemyModel()
	{
	}
	void EnemyModel::initialize(){reset();}
	void EnemyModel::reset()
	{
		enemy_state = EnemyState::DEAD;
		enemy_position = initial_enemy_position;
	}
	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}
	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}
	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}
	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}
}