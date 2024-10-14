#pragma once
#include "SFML/Audio.hpp"


namespace AppleGame
{
			struct Sounds
			{
				sf::Sound eat;
				sf::Sound death;
			};
			struct SoundBuffers 
			{
				sf::SoundBuffer eat;
				sf::SoundBuffer death;
			};
			struct Audio
			{
				Sounds Sounds;
				SoundBuffers Buffers;
			};
			enum SoundType
			{
				eat,
				death,
				Count
			};

			sf::Sound ChooseSound(const SoundType& type, Sounds& sound);
			void PlaySound(const SoundType& type, Sounds& sound);
}