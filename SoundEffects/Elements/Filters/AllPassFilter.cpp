#include "AllPassFilter.h"

AllPassFilter::AllPassFilter(uint32_t delay, float gain) : gain(gain), delayElement(delay)
{

}

usedType AllPassFilter::execute(usedType input)
{
	float tmp = delayElement.execute(input + gain * delayElement.getBack());
	return -gain * delayElement.getFront() + tmp;
}

float AllPassFilter::execute(float input)
{
	float tmp = delayElement.execute(input + gain * delayElement.getBack());
	return -gain * delayElement.getFront() + tmp;
}

const float& AllPassFilter::getGain() const
{
	return gain;
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
