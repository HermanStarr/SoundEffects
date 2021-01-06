#pragma once
#include "../Element.h"
#include "../Delay.h"

/// <summary>
/// Class implementing a simulated FIRfilter
/// </summary>
class FIRFilter : public Element
{
	/// <summary>
	/// FIR filter taps
	/// </summary>
	std::vector<float> taps;

	/// <summary>
	/// Delay element of the filter
	/// </summary>
	Delay delayElement;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="taps">Taps vector</param>
	FIRFilter(std::vector<float> taps);
	~FIRFilter() = default;

	/// <summary>
	/// Perform filtration on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Filtered value</returns>
	usedType execute(usedType input) override;

	/// <summary>
	/// Perform filtration on given sample
	/// </summary>
	/// <param name="input">Sample being passed</param>
	/// <returns>Filtered value</returns>
	float execute(float input) override;

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

	/// <summary>
	/// Get taps vector reference
	/// </summary>
	/// <returns>Taps vector reference</returns>
	const std::vector<float>& getTaps() const;

	/// <summary>
	/// reset delay element
	/// </summary>
	void reset() override;
};

