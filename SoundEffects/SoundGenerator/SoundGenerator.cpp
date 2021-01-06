#include "SoundGenerator.h"

namespace waveShape 
{
	float* sineWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			array[i] = sin(2.f * M_PI * static_cast<float>(i) / samples_per_tone);
		return array;
	}
	float* triangularWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			array[i] = abs(abs(4.f * static_cast<float>(i) / samples_per_tone - 1.f) - 2.f) - 1.f;
		return array;
	}
	float* squareWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		{
			if (static_cast<float>(i) / samples_per_tone < 0.5f)
				array[i] = 1.f;
			else
				array[i] = -1.f;
		}
	}
	float* hexagonWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		{
			if ((float)i / samples_per_tone <= 0.25f)
				array[i] = 1.f;
			else if ((float)i / samples_per_tone <= 0.5f)
				array[i] = -8.f * static_cast<float>(i) / samples_per_tone + 3.f;
			else if ((float)i / samples_per_tone <= 0.75f)
				array[i] = -1.f;
			else
				array[i] = -8.f * static_cast<float>(i) / samples_per_tone - 7.f;
		}
	}
	float* octagonWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		{
			if ((float)i / samples_per_tone <= ONE_SIXTH)
				array[i] = 1.5f * static_cast<float>(i) / samples_per_tone + 0.75f;
			else if ((float)i / samples_per_tone <= ONE_SIXTH * 2)
				array[i] = -1.5f * static_cast<float>(i) / samples_per_tone + 1.25f;
			else if ((float)i / samples_per_tone <= ONE_SIXTH * 3)
				array[i] = -9.f * static_cast<float>(i) / samples_per_tone + 3.75f;
			else if ((float)i / samples_per_tone <= ONE_SIXTH * 4)
				array[i] = 1.5f * static_cast<float>(i) / samples_per_tone;
			else if ((float)i / samples_per_tone <= ONE_SIXTH * 5)
				array[i] = 1.5f * static_cast<float>(i) / samples_per_tone - 2.f;
			else
				array[i] = 9.f * static_cast<float>(i) / samples_per_tone - 8.25f;
		}
	}
	float* sharkTeethWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			array[i] = 2.f * static_cast<float>(i) / samples_per_tone - 1.f;
	}
	float* sharkTeethReversedWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			array[i] = -2.f * static_cast<float>(i) / samples_per_tone + 1.f;
	}
	float* dentedTriangleWave(float samples_per_tone)
	{
		float* array = new float[static_cast<uint32_t>(samples_per_tone)];
		for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			array[i] = (abs(abs(abs(1.5f * abs(4.f * (static_cast<float>(i) / samples_per_tone) - 1.f) - 0.5f) - 2.5f) - 0.5f) - 1.f);
		return array;
	}
}


float SoundGenerator::dentedTriangleSound(uint32_t position, float samples_per_tone)
{
	return 10920.f * (abs(abs(abs(1.5f * abs(4.f * ((float)position / samples_per_tone) - 1.f) - 0.5f) - 2.5f) - 0.5f) - 1.f);
}


float* SoundGenerator::dentedTriangleSound(float samples_per_tone)
{
	float* array = new float[(uint32_t)samples_per_tone];
	for (uint32_t i = 0; i < (uint32_t)samples_per_tone; i++)
	{
		array[i] = (abs(abs(abs(1.5f * abs(4.f * ((float)i / samples_per_tone) - 1.f) - 0.5f) - 2.5f) - 0.5f) - 1.f);
	}
	return array;
}

float SoundGenerator::stairsLikeRaisingEnvelope(float position)
{
	if (position < ONE_TWELFTH)
	{
		return ONE_SIXTH;
	}
	else if (position < ONE_TWELFTH * 2)
	{
		return ONE_SIXTH * 2;
	}
	else if (position < ONE_TWELFTH * 3)
	{
		return ONE_SIXTH * 3;
	}
	else if (position < ONE_TWELFTH * 4)
	{
		return ONE_SIXTH * 4;
	}
	else if (position < ONE_TWELFTH * 5)
	{
		return ONE_SIXTH * 5;
	}
	else if (position < ONE_TWELFTH * 6)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 7)
	{
		return 0.f;
	}
	else if (position < ONE_TWELFTH * 8)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 9)
	{
		return 0.f;
	}
	else if (position < ONE_TWELFTH * 10)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 11)
	{
		return 0.f;
	}
	else
	{
		return 1.f;
	}
}

SoundGenerator::SoundGenerator()
{

}

SoundGenerator::~SoundGenerator()
{
	
}

RAWHolder* SoundGenerator::generateTone(float duration, float frequency, uint32_t sample_rate, uint8_t number_of_channels)
{
	RAWHolder* rawHolder = new RAWHolder(number_of_channels, sample_rate, duration);

	uint32_t samples_per_tone = sample_rate * number_of_channels / frequency;

	float* soundValues = dentedTriangleSound(sample_rate * number_of_channels / frequency);

	uint32_t sample_number = rawHolder->getSamplesNumber();

	for (uint32_t i = 0; i < sample_number; i++)
		rawHolder->setAt(i, soundValues[i % samples_per_tone]);

	if(soundValues)
		delete[] soundValues;

	return rawHolder;
}

void SoundGenerator::addEnvelope(Holder& holder)
{
	uint32_t sample_number = holder.getSamplesNumber();
	float samples_per_second = sample_number / holder.getDuration();
	for (uint32_t i = 0; i < sample_number; i++)
		holder.setAt(i, (float)holder.at(i) * stairsLikeRaisingEnvelope((i % (int)samples_per_second) / samples_per_second));
}

