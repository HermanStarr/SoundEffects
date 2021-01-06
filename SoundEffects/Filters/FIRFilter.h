#pragma once
#include "Filter.h"

class FIRFilter : public Filter
{
	std::vector<float> taps;
	uint32_t delay;

public:
	FIRFilter();
	~FIRFilter() = default;

	usedType filter(usedType value) override;

};

