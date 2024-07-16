#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;

        MainMenuController::MainMenuController() { game_window = nullptr; }

        void MainMenuController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        }

        void MainMenuController::update()
        {
        }

        void MainMenuController::render()
        {
        }

    }
}