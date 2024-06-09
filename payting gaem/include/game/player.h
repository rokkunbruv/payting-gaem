#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Player {
private:
	// player details
	const int WIDTH = 60;
	const int HEIGHT = 90;

	const float SPEED = 0.5f;
	const float JUMP_HEIGHT = 300.f;

	// player traits
	const std::string NAME;

	// player sprite
	sf::RectangleShape playerSprite;

public:
	Player();

	// GETTERS

	sf::Vector2i GetPlayerDimensions();
	sf::Vector2f GetPlayerPos();

	// PLAYER MOVEMENT FROM USER INPUT

	void MovePlayer(float direction);
	void JumpPlayer();

	// PLAYER MOVEMENT FROM EXTERNAL AND INTERNAL STATES

	void UpdatePlayerPos(sf::Vector2f);

	void DrawPlayer(sf::RenderWindow&);

};