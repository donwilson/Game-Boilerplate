#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Thor/Input.hpp>
#include <Thor/Vectors.hpp>

#include "game.hpp"

struct Level {
	Game* p_game;
	
	// event keys
	std::map<std::string, std::string> m_eventKeys;
	
	// player
	sf::RectangleShape m_player;
	
	Level(Game* game) {
		p_game = game;
		
		// register events
		thor::Action click = thor::Action(sf::Mouse::Left, thor::Action::PressOnce);
		
		m_eventKeys["click"] = p_game->registerEvent("click", click);
		
		// create a player
		m_player.setFillColor(sf::Color::Blue);
		m_player.setSize(sf::Vector2f(16.0f, 16.0f));
		m_player.setOrigin((m_player.getSize() * 0.5f));
		m_player.setPosition(sf::Vector2f(
			(p_game->m_screen.m_width * 0.5f),
			(p_game->m_screen.m_height * 0.5f)
		));
	}
	
	void update() {
		// find rotation of player
		float playerAngleDegrees = thor::polarAngle( (sf::Vector2f(p_game->m_screen.m_mousePos) - m_player.getPosition()) );
		m_player.setRotation(playerAngleDegrees);
	}
	
	void draw() {
		// player
		p_game->draw(m_player);
	}
};