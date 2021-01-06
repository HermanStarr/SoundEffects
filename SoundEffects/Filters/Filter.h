#pragma once
#include "../Headers.h"
class Filter {
public:
	virtual ~Filter() = 0;
	virtual usedType filter(usedType input) = 0;
};