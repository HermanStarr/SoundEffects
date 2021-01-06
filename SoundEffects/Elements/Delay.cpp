#include "Delay.h"

Delay::Delay(uint32_t delay) : delay(std::deque<float>(delay, 0.f)), delaySize(delay)
{
}

Delay::~Delay()
{
}

uint32_t Delay::getDelay() const
{
	return delaySize;
}

void Delay::setDelay(uint32_t size)
{
	delaySize = size;
	delay.resize(size);
}


float Delay::execute(float new_sample)
{
	float tmp = delay.back();
	delay.pop_back();
	delay.push_front(new_sample);
	return tmp;
}

usedType Delay::execute(usedType new_sample)
{
	float tmp = delay.back();
	delay.pop_back();
	delay.push_front(new_sample);
	return tmp;
}

float Delay::getFront()
{
	return delay.front();
}

float Delay::getBack()
{
	return delay.back();
}

void Delay::reset()
{
	delay = std::deque<float>(delaySize, 0.f);
}

float Delay::operator[](uint32_t index) const
{
	return delay.at(index);
}
