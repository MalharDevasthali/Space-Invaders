#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
    enum class EnemyState
    {
        ALIVE,
        DEAD,
    };

    class EnemyModel
    {
    private:

        const sf::Vector2f initial_enemy_position = sf::Vector2f(750.0f, 750.0f);
        sf::Vector2f enemy_position;
        EnemyState enemy_state;

    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

        const float enemy_movement_speed = 350.0f;

        EnemyModel();
        ~EnemyModel();

        void initialize();
        void reset();

        sf::Vector2f getEnemyPosition();
        void setEnemyPosition(sf::Vector2f position);

        EnemyState getEnemyState();
        void setEnemyState(EnemyState state);

    };
}
