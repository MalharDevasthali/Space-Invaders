#include <SFML/Graphics.hpp>
#include <iostream>

class Player {

private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    void takeDamage()
    {

    }
    void move()
    {

    }
    void shootBullets()
    {

    }


};

int main() {

    Player player;

    return 0;
}