#pragma once
#include "../../Header/Bullet/BulletController.h"
#include"../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBulletController : public BulletController
        {
        private:
            const float frost_movement_speed = 500.f;

        public:
            FrostBulletController(BulletType type,Entity::EntityType owner_type);
            ~FrostBulletController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}
