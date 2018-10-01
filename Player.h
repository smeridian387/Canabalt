#pragma once

//library includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//project include
#include "AnimationSystem.h"
class Player
{
public:

	Player();

	void Input(sf::Event _gameEvent);
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);

private:

	//Assets
	sf::Sprite m_sprite;
	sf::Sound m_jumpSound;
	sf::Sound m_deathSound;
	sf::Sound m_landSound;
	AnimationSystem m_animation;
	//state
	sf::Vector2 m_velocity
};