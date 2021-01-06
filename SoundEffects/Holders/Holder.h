#pragma once
#include "../Headers.h"

/// <summary>
/// Abstract class of each type of sound file
/// </summary>
class Holder {
public:

	/// <summary>
	/// Gets number of samples
	/// </summary>
	/// <returns>Number of samples</returns>
	virtual uint32_t getSamplesNumber() = 0;

	/// <summary>
	/// Gets delay value
	/// </summary>
	/// <param name="modifier">Delay value in seconds</param>
	/// <returns>Delay value in samples</returns>
	virtual uint32_t getDelay(float modifier) = 0;

	/// <summary>
	/// Gets duration of the file
	/// </summary>
	/// <returns>Duration time in seconds</returns>
	virtual float getDuration() = 0;

	/// <summary>
	/// Write buffered data to file
	/// </summary>
	/// <param name="path">Path to the file</param>
	/// <returns>Success of the operation</returns>
	virtual bool writeToFile(const std::string& path) = 0;

	/// <summary>
	/// Gets and sets sample at
	/// </summary>
	/// <param name="index">Position of the sample</param>
	/// <returns>Sample at the position</returns>
	virtual const usedType& operator[](std::uint32_t index) const = 0;

	/// <summary>
	/// Gets sample at
	/// </summary>
	/// <param name="index">Position of the sample</param>
	/// <returns>Sample at the position</returns>
	virtual const usedType at(uint32_t index) const = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, usedType value) = 0;
};