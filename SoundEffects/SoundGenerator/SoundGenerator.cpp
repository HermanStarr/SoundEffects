#include "SoundGenerator.h"

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
	else if (position < ONE_TWELFTH * 2.f)
	{
		return ONE_SIXTH * 2.f;
	}
	else if (position < ONE_TWELFTH * 3.f)
	{
		return ONE_SIXTH * 3.f;
	}
	else if (position < ONE_TWELFTH * 4.f)
	{
		return ONE_SIXTH * 4;
	}
	else if (position < ONE_TWELFTH * 5.f)
	{
		return ONE_SIXTH * 5;
	}
	else if (position < ONE_TWELFTH * 6.f)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 7.f)
	{
		return 0.f;
	}
	else if (position < ONE_TWELFTH * 8.f)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 9.f)
	{
		return 0.f;
	}
	else if (position < ONE_TWELFTH * 10.f)
	{
		return 1.f;
	}
	else if (position < ONE_TWELFTH * 11.f)
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

RAWHolder* SoundGenerator::generateTone(std::shared_ptr<Wave> wave, float duration, float frequency, uint32_t sample_rate, uint8_t number_of_channels, uint8_t bitsPerSample, uint16_t compressionCode)
{
	RAWHolder* holder = new RAWHolder(number_of_channels, sample_rate, duration, bitsPerSample, compressionCode);

	float samples_per_tone = sample_rate * number_of_channels / frequency;
	void* soundValues = dentedTriangleSound(sample_rate * number_of_channels / frequency);
	uint32_t sample_number = holder->getSamplesNumber();

    switch (static_cast<CompressionCodes>(holder->getCompressionCode()))
    {
    case CompressionCodes::UNKNOWN:
        break;
    case CompressionCodes::WAVE_FORMAT_PCM:
        switch (static_cast<IntegerTypes>(holder->getBitsPerSample()))
        {
        case IntegerTypes::UINT8:
			soundValues = wave->execute(static_cast<int32_t>(samples_per_tone));
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((uint8_t*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((uint8_t*)soundValues);
            break;
        case IntegerTypes::INT16:
			soundValues = wave->execute(static_cast<int32_t>(samples_per_tone));
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((int16_t*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((int16_t*)soundValues);
            break;
        case IntegerTypes::INT24:
			soundValues = wave->execute(static_cast<int32_t>(samples_per_tone));
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((int24_t*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((int24_t*)soundValues);
            break;
        case IntegerTypes::INT32:
			soundValues = wave->execute(static_cast<int32_t>(samples_per_tone));
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((int32_t*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((int32_t*)soundValues);
            break;
        default:
            break;
        }
        break;
    case CompressionCodes::MICROSOFT_ADPCM:
        break;
    case CompressionCodes::WAVE_FORMAT_IEEE_FLOAT:
        switch (static_cast<FloatTypes>(holder->getBitsPerSample()))
        {
        case FloatTypes::FLOAT32:
			soundValues = wave->execute(samples_per_tone);
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((float*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((float*)soundValues);
            break;
        case FloatTypes::FLOAT64:
			soundValues = wave->execute(static_cast<double>(samples_per_tone));
			for (uint32_t i = 0; i < sample_number; i++)
				holder->setAt(i, ((double*)soundValues)[i % static_cast<uint32_t>(samples_per_tone)]);
			if (soundValues)
				delete[]((double*)soundValues);
            break;
        default:
            break;
        }
        break;
    case CompressionCodes::WAVE_FORMAT_ALAW:
        break;
    case CompressionCodes::WAVE_FORMAT_MULAW:
        break;
    case CompressionCodes::IMA_ADPCM:
        break;
    case CompressionCodes::ITU_G_723_ADPCM:
        break;
    case CompressionCodes::GSM_6_10:
        break;
    case CompressionCodes::ITU_G_721_ADPCM:
        break;
    case CompressionCodes::MPEG:
        break;
    case CompressionCodes::EXPERIMENTAL:
        break;
    default:
        break;
    }

	return holder;
}

void SoundGenerator::addEnvelope(Holder& holder)
{
	uint32_t sample_number = holder.getSamplesNumber();
	float samples_per_second = sample_number / holder.getDuration();
	for (uint32_t i = 0; i < sample_number; i++)
		holder.setAt(i, (float)holder.at(i) * stairsLikeRaisingEnvelope((i % (int)samples_per_second) / samples_per_second));
}

