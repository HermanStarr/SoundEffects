#pragma once
#include "../Headers.h"

/// <summary>
/// Abstract class of all the elements
/// </summary>
class Element {
public:

	/// <summary>
	/// Perform action on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Refactored value</returns>
	virtual usedType execute(usedType input) = 0;

	/// <summary>
	/// Perform action on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Refactored value</returns>
	virtual float execute(float input) = 0;

	/// <summary>
	/// Gets delay value
	/// </summary>
	/// <returns>Delay value in samples</returns>
	virtual uint32_t getDelay() const = 0;

	/// <summary>
	/// Sets a value for the delay
	/// </summary>
	/// <param name="delay">Delay value in samples</param>
	virtual void setDelay(uint32_t delay) = 0;

	/// <summary>
	/// Resets element
	/// </summary>
	virtual void reset() = 0;
};

