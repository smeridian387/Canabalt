#pragma once
//library includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class AssetManager
{

public:

	//public interface / behaviours
	//constructor
	AssetManager();
	//get a texture based on a file name
	static sf::Texture& GetTexture(std::string _filename);
	//get a sound buffer based on a file name
	static sf::SoundBuffer& GetSoundBuffer(std::string _filename);
	//get a font based on a file name
	static sf::Font& GetFont(std::string _filename);

private:

	//private data for the is calss

	//a pointer to the class itself
	//for the singleton design pattern
	//the oneand only instance of this class
	static AssetManager* s_instance;

	//list of textures
	std::map<std::string, sf::Texture> m_textures;
	//list of SoundBuffers
	std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
	//list of fonts
	std::map<std::string, sf::Font> m_fonts;
};