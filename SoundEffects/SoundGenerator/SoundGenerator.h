#pragma once
#include "../Headers.h"
#include "../Holders/Holders.h"

/// <summary>
/// Class for generating tones and sounds
/// </summary>
class SoundGenerator
{

private:

	/// <summary>
	/// Method creates audio output as given by the laboratory supervisor e).
	/// Link to wave function: https://www.desmos.com/calculator/repcmjk4gn
	/// </summary>
	/// <param name="position">Position of sample relative to tone</param>
	/// <param name="samples_per_tone">Number of samples per tone</param>
	/// <returns>Value of sample at given position</returns>
	float dentedTriangleSound(uint32_t position, float samples_per_tone);

	/// <summary>
	/// Method creates audio output as given by the laboratory supervisor e).
	/// Link to wave function: https://www.desmos.com/calculator/repcmjk4gn
	/// </summary>
	/// <param name="position">Position of sample relative to tone</param>
	/// <param name="samples_per_tone">Number of samples per tone</param>
	/// <returns>Value of sample at given position</returns>
	float* dentedTriangleSound(float samples_per_tone);

	/// <summary>
	/// Method creates an audio envelope as given by the laboratory supervisor b)
	/// </summary>
	/// <param name="position"></param>
	/// <returns></returns>
	float stairsLikeRaisingEnvelope(float position);


public:

	/// <summary>
	/// Default constructor
	/// </summary>
	SoundGenerator();

	~SoundGenerator();

	/// <summary>
	/// Method generates tone
	/// </summary>
	/// <param name="duration">Duration of the sound file</param>
	/// <param name="frequency">Tone frequency</param>
	/// <param name="sample_rate">Sample rate of the audio</param>
	/// <param name="number_of_channels">Number of channels in the audio</param>
	/// <returns>Pointer to audio file</returns>
	RAWHolder* generateTone(float duration, float frequency, uint32_t sample_rate, uint8_t number_of_channels = 1);

	/// <summary>
	/// Adds an envelope to the audio holder of any type
	/// </summary>
	/// <param name="holder">Audio file holder</param>
	void addEnvelope(Holder& holder);
};

