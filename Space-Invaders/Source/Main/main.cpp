#include <SFML/Graphics.hpp>
#include"../../Header/Main/GameService.h"
#include <iostream>

using namespace Main;
    int main()
    {
        GameService* gameService = new GameService();

        gameService->ignite();
        while (gameService->isRunning())
        {
            gameService->update();
            gameService->render();
        }
        return 0;

    }
