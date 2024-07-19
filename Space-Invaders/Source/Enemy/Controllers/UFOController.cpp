#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController() { }

		void UFOController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::RIGHT);
		}

		void UFOController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;
			}
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void UFOController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();


			currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
			
		}

		void UFOController::fireBullet()
		{
			// UFO Dont fire Bullets, its peacefull... :
		}
		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB));
			return static_cast<Powerup::PowerupType>(random_value);
		}
	}
}