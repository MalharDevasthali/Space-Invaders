#include <SFML/Graphics.hpp>
#include <iostream>

class PlayerController;

#pragma once
class PlayerService {

private:
    PlayerController* player_controller;

public:

    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();

};