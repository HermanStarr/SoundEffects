#pragma once
#include "../Headers.h"

class Holder {
public:
	virtual ~Holder() = 0;
	virtual uint32_t getSamplesNumber() = 0;
	virtual uint32_t getDelay(float modifier) = 0;
	virtual float getDuration() = 0;
	virtual bool writeToFile(const std::string& path) = 0;
	virtual usedType& operator[](std::uint32_t index) const = 0;
};