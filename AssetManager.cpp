//library includes 
#include <assert.h>
//project includes
#include "AssetManager.h"

//initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

//constructor
AssetManager::AssetManager()
	: m_textures()
	, m_fonts()
	, m_SoundBuffers()
{
	//throw and errot and stop exicution (in debug mode) if a copy
	//of this class has already been created 
	assert(s_instance == nullptr);

	//assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;

}

sf::Texture& AssetManager::GetTexture(std::string _filename)
{
	//create an iterator to hold a key and value pair
	//and search for the required key
	// using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_filename);
	// "auto" in this case is equivelent to  writing 
	// std::map<std::string,sf::Texture>

	if (keyValuePair != s_instance ->m_textures.end())
	{
		//yes! we found it
		return keyValuePair->second;
	}
	else
	{
		//NO! we didnt find it 

		//lets create it then 

		sf::Texture& texture = s_instance->m_textures[_filename];

		texture.loadFromFile(_filename);
		return texture;
	}
}