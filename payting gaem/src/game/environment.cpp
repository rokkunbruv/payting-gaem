
#include <SFML/Graphics.hpp>

#include <game/environment.h>
#include <program/settings.h>

// initialize environment objects
Environment::Environment() {
	// initialize ground object
	
	this->ground.setSize(sf::Vector2f(Setting::SCREEN_WIDTH, GROUND_DEPTH) );
	this->ground.setPosition(sf::Vector2f(0, Setting::SCREEN_HEIGHT - this->ground.getSize().y) );
	this->ground.setFillColor(sf::Color::White);
}

// draw and render environment
void Environment::RenderEnvironment(sf::RenderWindow& window) {
	// draw ground
	window.draw(this->ground);
}