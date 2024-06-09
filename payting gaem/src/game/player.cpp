
#include <SFML/Graphics.hpp>

#include <game/environment.h>
#include <game/player.h>
#include <program/settings.h>

// initialize player
Player::Player() {
	this->playerSprite.setSize(sf::Vector2f(this->WIDTH, this->HEIGHT) );
	this->playerSprite.setPosition(
		sf::Vector2f(Setting::SCREEN_WIDTH / 2, Environment::ABOVE_GROUND - playerSprite.getSize().y) 
	);
	this->playerSprite.setFillColor(sf::Color::Green);
}

// get player dimensions
sf::Vector2i Player::GetPlayerDimensions() {
	sf::Vector2i playerDimensions(WIDTH, HEIGHT );
	return playerDimensions;
}

// get current player position
sf::Vector2f Player::GetPlayerPos() {
	return this->playerSprite.getPosition();
}

// move a player using WAD keys
void Player::MovePlayer(float direction) {
	// set player speed
	direction *= SPEED;

	// obtain player current position
	sf::Vector2f currentPos = this->playerSprite.getPosition();
	
	// update player position
	this->playerSprite.setPosition(currentPos + sf::Vector2f(direction, 0.f) );
}

// allows a player to jump
void Player::JumpPlayer() {
	sf::Vector2f currentPos = this->playerSprite.getPosition();

	this->playerSprite.setPosition(currentPos + sf::Vector2f(0.f, -1 * JUMP_HEIGHT) );
}

// update player pos caused by external and internal forces
void Player::UpdatePlayerPos(sf::Vector2f updatedPos) {
	sf::Vector2f currentPos = playerSprite.getPosition();

	playerSprite.setPosition(currentPos + updatedPos);
}

// draw player
void Player::DrawPlayer(sf::RenderWindow& window) {
	window.draw(this->playerSprite);
}