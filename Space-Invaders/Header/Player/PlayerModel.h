#pragma once
#include <SFML/Graphics.hpp>
namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        DEAD,
    };

    class PlayerModel
    {
    private:

        const sf::Vector2f initial_player_position = sf::Vector2f(500.f, 500.f);
        sf::Vector2f player_position;
        PlayerState player_state;
        int player_score;

    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 0.f);
        const sf::Vector2f right_most_position = sf::Vector2f(700.f, 0.f);

        const float player_movement_speed = 200.0f;

        PlayerModel();
        ~PlayerModel();

        void initialize();
        void reset();

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        PlayerState getPlayerState();
        void setPlayerState(PlayerState state);

    };
}