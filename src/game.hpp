#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Thor/Input.hpp>

#include "utils.hpp"

struct Screen {
	sf::RenderWindow m_window;
	
	sf::IntRect m_rect;   // playable area
	sf::Vector2i m_mousePos;
	
	float m_margin;
	float m_width;
	float m_height;
	
	sf::Color m_clearColor;
	
	Screen(float width=800.0f, float height=600.0f, float margin=0.0f) : m_margin(margin), m_width(width), m_height(height), m_clearColor(sf::Color::Black) {
		calculateRect();
	}
	
	float top() { return m_margin; }
	float bottom() { return (m_height - m_margin); }
	
	float left() { return m_margin; }
	float right() { return (m_width - m_margin); }
	
	float innerWidth() { return m_rect.width; }
	float innerHeight() { return m_rect.height; }
	
	void calculateRect() { m_rect = sf::IntRect(top(), left(), right(), bottom()); }
	void calculateMousePosition() { m_mousePos = sf::Mouse::getPosition(m_window); }
	
	void update(float df) {
		calculateMousePosition();
	}
	
	void clear() { m_window.clear(m_clearColor); }
	void draw(sf::Drawable& drawable) { m_window.draw(drawable); }
	void display() { m_window.display(); }
	
	void createWindow() {
		//utils::debugMessage("Creating window: "+ std::to_string(m_width) +"x"+ std::to_string(m_height));
		
		m_window.create(sf::VideoMode(m_width, m_height), "Window", sf::Style::Titlebar | sf::Style::Close);
	}
	
	void setTitle(std::string title) {
		m_window.setTitle(title);
	}
	
	bool isOpen() { return m_window.isOpen(); }
	bool intersects(sf::IntRect rect) { return m_rect.intersects(rect); }
	bool intersects(sf::FloatRect rect) { return m_rect.intersects(sf::IntRect(rect)); }
};

struct Game {
	Screen m_screen;
	
	sf::Clock m_clock;
	sf::Time m_time;
	float m_df;
	
	thor::ActionMap<std::string> m_actionMap;
	
	bool m_animating = true;
	
	sf::Vector2f m_worldPosition;
	
	Game(float width = 800.0f, float height = 600.0f, std::string title = "") {
		m_screen.m_width = width;
		m_screen.m_height = height;
		
		m_screen.createWindow();
		
		if("" != title) {
			m_screen.setTitle(title);
		}
		
		m_worldPosition = sf::Vector2f(
			(m_screen.m_width * 0.5f),
			(m_screen.m_height * 0.5f)
		);
		
		registerEvents();
	}
	
	void tick() {
		m_time = m_clock.restart();
		m_df = m_time.asSeconds();
		
		handleEvents();
		
		m_screen.update(m_df);
	}
	
	void registerEvents() {
		thor::Action window_close(sf::Event::Closed);
		thor::Action press_escape(sf::Keyboard::Escape, thor::Action::PressOnce);
		thor::Action lose_focus(sf::Event::LostFocus);
		thor::Action gain_focus(sf::Event::GainedFocus);
		
		//thor::Action click(sf::Mouse::Left, thor::Action::PressOnce);
		
		m_actionMap["quit"] = window_close || press_escape;
		m_actionMap["lost_focus"] = lose_focus;
		m_actionMap["gained_focus"] = gain_focus;
		//m_actionMap["click"] = click;
	}
	
	std::string registerEvent(std::string action_key, thor::Action action) {
		m_actionMap[ action_key ] = action;
		
		return action_key;
	}
	
	void unregisterEvent(std::string action_key) {
		m_actionMap.removeAction(action_key);
	}
	
	bool eventOccurred(std::string action_key) {
		return m_actionMap.isActive(action_key);
	}
	
	void handleEvents() {
		m_actionMap.update(m_screen.m_window);
		
		if(m_actionMap.isActive("quit")) {
			m_animating = false;
			m_screen.m_window.close();
			
			return;
		}
		
		if(m_actionMap.isActive("gained_focus")) {
			m_animating = true;
		} else if(m_actionMap.isActive("lost_focus")) {
			m_animating = false;
		}
	}
	
	void clear() {
		m_screen.clear();
	}
	
	void draw() {
		
	}
	
	void draw(sf::Drawable& drawable) {
		m_screen.draw(drawable);
	}
	
	void render() {
		m_screen.display();
	}
	
	bool isRunning() { return m_screen.isOpen(); }
	bool isAnimating() { return m_animating; }
	sf::Vector2f getWorldPosition() { return m_worldPosition; }
	
	// @todo:
	//sf::Vector2f worldToScreenPosition(float x, float y)
	//sf::Vector2f screenToWorldPosition(float x, float y)
};