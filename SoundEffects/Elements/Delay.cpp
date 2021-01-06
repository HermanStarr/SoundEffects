#include "Delay.h"

Delay::Delay(uint32_t delay) : delay(std::deque<double>(delay, 0.f)), delaySize(delay)
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

int32_t Delay::execute(int32_t new_sample)
{
	float tmp = static_cast<float>(delay.back());
	delay.pop_back();
	delay.push_front(static_cast<double>(new_sample));
	return static_cast<int32_t>(tmp);
}

float Delay::execute(float new_sample)
{
	float tmp = static_cast<float>(delay.back());
	delay.pop_back();
	delay.push_front(static_cast<double>(new_sample));
	return tmp;
}

double Delay::execute(double new_sample)
{
	double tmp = delay.back();
	delay.pop_back();
	delay.push_front(new_sample);
	return tmp;
}

double Delay::getFront()
{
	return delay.front();
}

double Delay::getBack()
{
	return delay.back();
}

void Delay::reset()
{
	delay = std::deque<double>(delaySize, 0.f);
}

double Delay::operator[](uint32_t index) const
{
	return delay.at(index);
}
