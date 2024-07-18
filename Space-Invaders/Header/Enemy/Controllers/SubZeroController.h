#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;
            float subZero_fire_rate = 1.f;

            void move()override;
            void fireBullet()override;
            void moveDown();

        public:
            SubzeroController(EnemyType);
            ~SubzeroController()override;

            void initialize()override;
        };
    }
}