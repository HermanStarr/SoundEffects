#pragma once
#include "../Headers.h"
#include "Element.h"

/// <summary>
/// Class implementing delay and deque holding previous values of samples
/// </summary>
class Delay : public Element
{
	/// <summary>
	/// deque of previous values
	/// </summary>
	std::deque<double> delay;
	/// <summary>
	/// Size of the delay in samples
	/// </summary>
	uint32_t delaySize;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="delay">Size of the delay in samples</param>
	Delay(uint32_t delay);
	~Delay();

	/// <summary>
	/// Get delay value
	/// </summary>
	/// <returns>delay value in samples</returns>
	uint32_t getDelay() const override;

	/// <summary>
	/// Set delay value
	/// </summary>
	/// <param name="delay">Delay value in samples</param>
	void setDelay(uint32_t delay) override;

	/// <summary>
	/// Adds a new sample in the beginning of the deck and discards sample in the back of the deque
	/// </summary>
	/// <param name="new_sample">A new sample to be inserted in the beginning</param>
	/// <returns>Last, discarded value of the deque</returns>
	int32_t execute(int32_t new_sample) override;

	/// <summary>
	/// Adds a new sample in the beginning of the deck and discards sample in the back of the deque
	/// </summary>
	/// <param name="new_sample">A new sample to be inserted in the beginning</param>
	/// <returns>Last, discarded value of the deque</returns>
	float execute(float new_sample) override;

	/// <summary>
	/// Perform action on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Refactored value</returns>
	double execute(double input) override;

	/// <summary>
	/// Gets value in the front of the deque
	/// </summary>
	/// <returns>Sample in the front of the deque</returns>
	double getFront();
	/// <summary>
	/// Gets value in the back of the deque
	/// </summary>
	/// <returns>Sample in the back of the deque</returns>
	double getBack();

	/// <summary>
	/// reset all the values in the deque
	/// </summary>
	void reset();

	/// <summary>
	/// Get value from the deque at index
	/// </summary>
	/// <param name="index">Position of the sample in the deque</param>
	/// <returns>Sample in the given position</returns>
	double operator [](uint32_t index) const;

};

