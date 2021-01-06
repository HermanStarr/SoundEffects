#include "FIRFilter.h"

FIRFilter::FIRFilter(std::vector<double> taps) : delayElement(static_cast<uint32_t>(taps.size() * 2))
{
	this->taps = taps;
}

int32_t FIRFilter::execute(int32_t input)
{
	delayElement.execute(input);
	float output = 0;
	unsigned i = 0;
	for (double tap : taps)
	{
		output += static_cast<float>(tap * delayElement[2 * i]);
		i++;
	}
	return static_cast<uint32_t>(output);
}

float FIRFilter::execute(float input)
{
	delayElement.execute(input);
	float output = 0;
	unsigned i = 0;
	for (double tap : taps)
	{
		output += static_cast<float>(tap * delayElement[2 * i]);
		i++;
	}
	return output;
}

double FIRFilter::execute(double input)
{
	delayElement.execute(input);
	double output = 0;
	unsigned i = 0;
	for (double tap : taps)
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

const std::vector<double>& FIRFilter::getTaps() const
{
	return taps;
}

void FIRFilter::reset()
{
	delayElement.reset();
}
