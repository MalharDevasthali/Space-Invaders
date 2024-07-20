#include <SFML/Graphics.hpp>
#include <iostream>
#include"../../Header/Entity/EntityConfig.h"
#pragma once
namespace Player
{
    class PlayerController;

    class PlayerService 
    {
    private:
        PlayerController* player_controller;
        Entity::EntityType owner_type = Entity::EntityType::PLAYER;

    public:

        PlayerService();
        ~PlayerService();

        void initialize();
        void update();
        void render();

        void enableShield();
        void enableRapidFire();
        void enableTrippleLaser();

        void reset();
    };
}