#include "AllPassFilter.h"

AllPassFilter::AllPassFilter(uint32_t delay, float gain) : gain(gain), delayElement(delay)
{

}

int32_t AllPassFilter::execute(int32_t input)
{
	float tmp = static_cast<float>(delayElement.execute(input + gain * delayElement.getBack()));
	return static_cast<int32_t>(-gain * static_cast<float>(delayElement.getFront()) + tmp);
}

float AllPassFilter::execute(float input)
{
	float tmp = static_cast<float>(delayElement.execute(input + gain * delayElement.getBack()));
	return -gain * static_cast<float>(delayElement.getFront()) + tmp;
}

double AllPassFilter::execute(double input)
{
	double tmp = delayElement.execute(input + gain * delayElement.getBack());
	return -gain * delayElement.getFront() + tmp;
}

const float AllPassFilter::getGain() const
{
	return gain;
}

void AllPassFilter::setGain(float newGain)
{
	gain = newGain;
}

uint32_t AllPassFilter::getDelay() const
{
	return delayElement.getDelay();
}

void AllPassFilter::setDelay(uint32_t delay)
{
	delayElement.setDelay(delay);
}

void AllPassFilter::reset()
{
	delayElement.reset();
}
