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
    sf::Vector2f getPosition()
    {
        return position;
    }

};

int main()
{

    Player player;

    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    sf::RenderWindow window(videoMode, "SFML Window");

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move();
        }

        window.clear(sf::Color::Black);
        player.player_sprite.setPosition(player.getPosition()); 
        window.draw(player.player_sprite);   
        window.display(); 
    }
    return 0;
}