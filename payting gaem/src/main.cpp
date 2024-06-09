// SFML PREPROCESSORS
#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <vector>

#include <game/environment.h>
#include <game/physics.h>
#include <game/player.h>
#include <program/settings.h>

int main() {

#pragma region INITIALIZE

    sf::RenderWindow mainWindow(
        sf::VideoMode(Setting::SCREEN_WIDTH, Setting::SCREEN_HEIGHT), Setting::SCREEN_TITLE
    );

    Environment combatEnv;

    Player defaultPlayer;

    sf::Clock clock;

#pragma endregion


#pragma region GAME LOOP

    while (mainWindow.isOpen()) {
        // calculate delta time
        float deltaTime = clock.restart().asSeconds();
        
        sf::Event event;

        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mainWindow.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // toggle player jump
                // ensures that the player can only jump when the player is on the ground
                if (defaultPlayer.GetPlayerPos().y >= Environment::ABOVE_GROUND - defaultPlayer.GetPlayerDimensions().y) {
                    defaultPlayer.JumpPlayer();
                }
            }
        }

#pragma region PLAYER EVENTS

        // initialize player direction vector
        sf::Vector2f playerDirection = {};

        // update player direction based on user input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
            playerDirection.x = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            playerDirection.x = 1;
        }
        
        defaultPlayer.MovePlayer(playerDirection.x);

        if (defaultPlayer.GetPlayerPos().y < Environment::ABOVE_GROUND - defaultPlayer.GetPlayerDimensions().y) {
            defaultPlayer.UpdatePlayerPos(GRAVITY);
        }



#pragma endregion

#pragma region DRAW AND RENDER

        mainWindow.clear(sf::Color::Black);

        combatEnv.RenderEnvironment(mainWindow);

        defaultPlayer.DrawPlayer(mainWindow);

        mainWindow.display();

#pragma endregion

    }

#pragma endregion



    return 0;
}
