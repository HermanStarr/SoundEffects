#pragma once
#include "../Headers.h"
#include "../Holders/Holders.h"
#include "Wave.h"

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
	/// <param name="frequency">Tone frequency in Hz</param>
	/// <param name="sample_rate">Sample rate of the audio</param>
	/// <param name="number_of_channels">Number of channels in the audio</param>
	/// <returns>Pointer to audio file</returns>
	/// <param name="bitsPerSample">Number of bits per sample</param>
	/// <param name="compressionCode">Code of compression for the file</param>
	/// <returns>Raw holder containing generated sound</returns>
	RAWHolder* generateTone(std::shared_ptr<Wave> wave, float duration, float frequency, uint32_t sample_rate = 44100, uint8_t number_of_channels = 2, uint8_t bitsPerSample = 16, uint16_t compressionCode = 1);

	/// <summary>
	/// Adds an envelope to the audio holder of any type
	/// </summary>
	/// <param name="holder">Audio file holder</param>
	void addEnvelope(Holder& holder);
};

