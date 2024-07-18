#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace MainMenu 
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;

        MainMenuController::MainMenuController() { game_window = nullptr; }

        void MainMenuController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeButtons();
        }

        void MainMenuController::update()
        {
            processButtonInteractions();
        }

        void MainMenuController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(play_button_sprite);
            game_window->draw(instructions_button_sprite);
            game_window->draw(quit_button_sprite);
        }

        void MainMenuController::initializeBackgroundImage()
        { 
            if (background_texture.loadFromFile(Config::background_texture_path))
            {   
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuController::scaleBackgroundImage()
        { 
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuController::initializeButtons()
        {
        
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool MainMenuController::loadButtonTexturesFromFile()
        {
            return play_button_texture.loadFromFile(Config::play_button_texture_path) &&
                instructions_button_texture.loadFromFile(Config::instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(Config::quit_button_texture_path);
        }

        void MainMenuController::setButtonSprites()
        {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }


        void MainMenuController::scaleAllButttons()
        {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            play_button_sprite.setPosition({ x_position, 500.f });
            instructions_button_sprite.setPosition({ x_position, 700.f });
            quit_button_sprite.setPosition({ x_position, 900.f });
        }

        void MainMenuController::processButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&play_button_sprite, mouse_position))
            {
                GameService::setGameState(GameState::GAMEPLAY);
            }

            if (clickedButton(&instructions_button_sprite, mouse_position))
            {
                printf("Clicked Instruction Button\n");
            }

            if (clickedButton(&quit_button_sprite, mouse_position))
                game_window->close();
        }

       
        bool MainMenuController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }

    }
}