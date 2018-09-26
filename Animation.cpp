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

	//only process the animation if it is playing
	if (m_playing)
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

				//sould we loop?
				if (m_loop)
				{
					//we sould loop
					//wrap around to the begining
					m_currentFrame = 0;

				}
				else
				{
					//we should not loop

					//set our frame as the last in the list 
					m_currentFrame = m_frames.size() - 1;

					//stop playing
					m_playing = false;
				}
				//TODO: what if  no loop?

				
				
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

	
}

void Animation::Play()
{
	//update our sprite to the current frame immediatly 
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}

	//only start playing and set next frame time IF playback speed is nonzero
	//avoid a divide by zero error
	if (m_playBackSpeed != 0)
	{
		//set play back to true
		m_playing = true;

		//determine time for next frame
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::Pause()
{
	m_playing = false;

}

void Animation::Stop()
{
	//stop playbackand resset to first frame
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::IsPlaying()
{
	//tell the calling code if we are currently playing
	return m_playing;

}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

}

void Animation::SetPlayBackSpeed(float _framesPerSecond)
{
	m_playBackSpeed = _framesPerSecond;

	//if playbackspeed = 0
	//pause to protect from deviding by zero error
	if (m_playBackSpeed == 0)
		Pause();
}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;

}