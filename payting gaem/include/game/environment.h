#pragma once

#include <SFML/Graphics.hpp>

#include <program/settings.h>

class Environment {
private:
	sf::RectangleShape ground;

public:
	static const int GROUND_DEPTH = 100;
	static const int ABOVE_GROUND = Setting::SCREEN_HEIGHT - GROUND_DEPTH;

	Environment();

	void RenderEnvironment(sf::RenderWindow&);
};