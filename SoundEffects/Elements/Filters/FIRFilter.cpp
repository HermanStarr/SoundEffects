#include "FIRFilter.h"

FIRFilter::FIRFilter(std::vector<float> taps) : delayElement(taps.size() * 2)
{
	this->taps = taps;
}

usedType FIRFilter::execute(usedType input)
{
	delayElement.execute(input);
	float output = 0;
	unsigned i = 0;
	for (float tap : taps)
	{
		output += tap * delayElement[2 * i];
		i++;
	}
	return output;
}

float FIRFilter::execute(float input)
{
	delayElement.execute(input);
	float output = 0;
	unsigned i = 0;
	for (float tap : taps)
	{
		output += tap * delayElement[2 * i];
		i++;
	}
	return output;
}

uint32_t FIRFilter::getDelay() const
{
	return delayElement.getDelay();
}

void FIRFilter::setDelay(uint32_t delay)
{
	delayElement.setDelay(delay);
}

const std::vector<float>& FIRFilter::getTaps() const
{
	return taps;
}

void FIRFilter::reset()
{
	delayElement.reset();
}
