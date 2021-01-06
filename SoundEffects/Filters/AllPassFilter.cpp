#include "AllPassFilter.h"

AllPassFilter::AllPassFilter(uint32_t delay, float gain) : delay(delay * 2), gain(gain)
{

}

usedType AllPassFilter::filter(usedType input)
{
	usedType output = gain * (previousOutput - input) + previousInput;
	previousInput = input;
	previousOutput = output;
	return output;
}

float AllPassFilter::getGain() const
{
	return gain;
}

uint32_t AllPassFilter::getDelay() const
{
	return delay;
}

void AllPassFilter::setgain(float new_gain)
{
	gain = std::move(new_gain);
}

void AllPassFilter::setDelay(uint32_t new_delay)
{
	delay = std::move(new_delay);
}

void AllPassFilter::reset()
{
	previousInput = 0;
	previousOutput = 0;
}
