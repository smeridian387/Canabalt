// --------------------------------------
// Includes
// --------------------------------------
// Libraries
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Animation.h"
#include "AnimationSystem.h"


int main()
{
	// --------------------------------------
	// Game Setup
	// --------------------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Canabalt",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	AssetManager asset;


	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerjump.png"));

	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/jump.WAV"));
	testSound.play();

	sf::Text testText;
	testText.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testText.setString("abcdefghijklmnopqrstuvwxyz 1234567890");

	//Testing animation
	AnimationSystem testAnimationSystem;
	testAnimationSystem.SetSprite(testSprite);

	
	Animation& testAnimation = testAnimationSystem.CreateAnimation("run");
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));

	testAnimation.Play();
	testAnimation.SetLoop(true);
	testAnimation.SetPlayBackSpeed(4.0f);

	Animation& jumpAnimation = testAnimationSystem.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerjump.png"));
	testAnimationSystem.Play("run");

	// end game setup
	// --------------------------------------


	// --------------------------------------
	// Game Loop
	// --------------------------------------
	while (gameWindow.isOpen())
	{
		// --------------------------------------
		// Input
		// --------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			} // End if (closed)
		} // end event polling loop

		// end input
		// --------------------------------------


		// --------------------------------------
		// Update
		// --------------------------------------
		sf::Time frameTime = gameClock.restart();

		testAnimation.Update(frameTime);
		// end update
		// --------------------------------------



		// --------------------------------------
		// Draw
		// --------------------------------------

		// Clear the window to a single colour
		gameWindow.clear();

		// Draw Everything
		gameWindow.draw(testSprite);
		gameWindow.draw(testText);
		// Display the window contents to the screen
		gameWindow.display();

		// end draw
		// --------------------------------------

	} // end of the game while loop

	// end game loop
	// --------------------------------------

	// exit point for the program
	return 0;

} // end of the main() function
