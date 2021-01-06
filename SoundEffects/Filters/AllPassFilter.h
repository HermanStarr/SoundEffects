#pragma once
#include "Filter.h"

class AllPassFilter : public Filter
{
public:
	AllPassFilter(uint32_t delay, float gain);
	~AllPassFilter() = default;


	usedType filter(usedType value) override;


private:
	float gain;
public:
	void setgain(float new_gain);
	float getGain() const;



private:
	uint32_t delay;
public:
	uint32_t getDelay() const;
	void setDelay(uint32_t new_delay);



private:
	usedType previousInput = 0;
	usedType previousOutput = 0;
public:
	void reset();

};

