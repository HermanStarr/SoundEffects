#pragma once
#include "../Element.h"
#include "../Delay.h"

/// <summary>
/// Class simulating all-pass filter
/// </summary>
class AllPassFilter : public Element
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="delay">Size of collection of previous samples to be taken by the filter</param>
	/// <param name="gain">Filter gain</param>
	AllPassFilter(uint32_t delay, float gain);
	~AllPassFilter() = default;

	/// <summary>
	/// Perform filtration on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Filtered value</returns>
	int32_t execute(int32_t input) override;

	/// <summary>
	/// Perform filtration on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Filtered value</returns>
	float execute(float input) override;

	/// <summary>
	/// Perform filtration on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Filtered value</returns>
	double execute(double input) override;


private:
	/// <summary>
	/// Gain of the filter
	/// </summary>
	float gain;
public:
	/// <summary>
	/// Gets and sets gain of the filter
	/// </summary>
	/// <returns>Gain value</returns>
	const float getGain() const;

	/// <summary>
	/// Sets gain
	/// </summary>
	/// <param name="newGain">New value of gain</param>
	void setGain(float newGain);

public:
	/// <summary>
	/// Gets delay value
	/// </summary>
	/// <returns>Delay value in samples</returns>
	uint32_t getDelay() const override;

	/// <summary>
	/// Sets a value for the delay
	/// </summary>
	/// <param name="delay">Delay value in samples</param>
	void setDelay(uint32_t delay) override;



private:
	/// <summary>
	/// Delay element of the circuit
	/// </summary>
	Delay delayElement;
public:
	/// <summary>
	/// Resets delay element
	/// </summary>
	void reset() override;

};

