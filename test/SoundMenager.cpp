#include "SoundMenager.h"

namespace AppleGame
{
	sf::Sound ChooseSound(const SoundType& type, Sounds& sound)
	{
		switch (type)
		{
		case SoundType::eat:
		{
			return sound.eat;
			break;
		}
		case SoundType::death:
		{
			return sound.death;
			break;
		}

		}
	}
	void PlaySound(const SoundType& type, Sounds& sound)
	{
		bool IsSoundPlaying = false;
		int SoundsNum = static_cast<int>(SoundType::Count);

		for (int i = 0; i < SoundsNum; ++i)
		{
			if (ChooseSound(type, sound).getStatus() != sf::Sound::Stopped)
			{
				IsSoundPlaying = true;
				break;
				return;
			}
		}
		if (!IsSoundPlaying)
		{
			ChooseSound(type, sound).play();

		}
	}
}