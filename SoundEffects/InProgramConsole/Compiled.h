#pragma once
#include <any>

class Compiled
{
protected:
	std::any _input;
public:
	virtual std::any function(std::any input) const = 0;
	void init(std::any input) { _input = input; }
	virtual ~Compiled() {}
};

