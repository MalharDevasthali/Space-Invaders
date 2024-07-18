#pragma once
#include "../../header/Enemy/EnemyController.h"


namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float zapper_fire_rate = 2.f;

            void move()override;
            void fireBullet()override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController(EnemyType type);
            ~ZapperController()override;

            void initialize() override;
        };
    }
}