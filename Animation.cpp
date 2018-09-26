//project includes
#include "Animation.h"

//constructor
Animation::Animation()
	: m_frames()
	, m_sprite(nullptr)
	, m_playBackSpeed(15.0f)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)
{


}

void Animation::Update(sf::Time _frameTime)
{
	//is it time to change to a new frame?
	m_nextFrameChange -= _frameTime;
	if (m_nextFrameChange.asSeconds() <= 0)
	{
		//its time to change the frame

		//change to the next frame
		++m_currentFrame;

		//did we reach the end?
		if (m_currentFrame >= m_frames.size())
		{
			//we did reach the end

			//TODO: what if  no loop?

			//wrap around to the begining
			m_currentFrame = 0;
		}
		//update sprites texture to match new frame
		//does our sprite exist
		if (m_sprite) // is not = 0 null aka null
		{
			m_sprite->setTexture(*m_frames[m_currentFrame]);
		}
		//determine time for next frame
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

}