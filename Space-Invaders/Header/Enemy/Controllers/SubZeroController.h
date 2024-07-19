#pragma once
#include "../../header/Enemy/EnemyController.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;
            float subZero_fire_rate = 1.f;
            Entity::EntityType owner_type;

            void move()override;
            void fireBullet()override;
            void moveDown();

        public:
            SubzeroController(EnemyType, Entity::EntityType);
            ~SubzeroController()override;

            void initialize()override;
            Entity::EntityType getOwnerEntityType();

        };
    }
}