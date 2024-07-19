#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
            float horizontal_movement_speed = 50.f;
         
            void move()override;
            void moveLeft();
            void moveRight();
            
            void fireBullet()override;
            Powerup::PowerupType getRandomPowerupType();

        public:
            UFOController(EnemyType);
            ~UFOController();

            void initialize()override;
        };
    }
}
