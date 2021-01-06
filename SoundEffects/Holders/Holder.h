#pragma once
#include "../Headers.h"

enum class CompressionCodes : uint16_t{
	UNKNOWN = 0,
	WAVE_FORMAT_PCM = 1,
	MICROSOFT_ADPCM = 2,
	WAVE_FORMAT_IEEE_FLOAT = 3,
	WAVE_FORMAT_ALAW = 6,
	WAVE_FORMAT_MULAW = 7,
	IMA_ADPCM = 17,
	ITU_G_723_ADPCM = 20,
	GSM_6_10 = 49,
	ITU_G_721_ADPCM = 64,
	MPEG = 80,
	WAVE_FORMAT_EXTENSIBLE = 0xFFFE,
	EXPERIMENTAL = 0xFFFF
};

/// <summary>
/// Enum of integer types with values equal to their bit sizes
/// </summary>
enum class IntegerTypes {
	UINT8 = 8,
	INT16 = 16,
	INT24 = 24,
	INT32 = 32,
};

/// <summary>
/// Enum of floating point types with values equal to their bit sizes
/// </summary>
enum class FloatTypes {
	FLOAT32 = 32,
	FLOAT64 = 64
};

/// <summary>
/// Abstract class of each type of sound file
/// </summary>
class Holder {
public:

	/// <summary>
	/// Gets number of samples
	/// </summary>
	/// <returns>Number of samples</returns>
	virtual const uint32_t getSamplesNumber() const = 0;

	/// <summary>
	/// Gets compression mode of the file
	/// </summary>
	/// <returns>Compression mode</returns>
	virtual const uint16_t getCompressionCode() const = 0;

	/// <summary>
	/// Gets bits per sample
	/// </summary>
	/// <returns>Number of bits per single sample</returns>
	virtual const uint16_t getBitsPerSample() const = 0;

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
	/// Gets byte from Samples at give index
	/// </summary>
	/// <param name="index">Index of position</param>
	/// <returns>Byte at given index</returns>
	virtual const unsigned char at(uint32_t index) const = 0;

	/// <summary>
	/// Gets integer type
	/// </summary>
	/// <param name="index">Position relative to size of type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const uint8_t atUint8_t(uint32_t index) const = 0;

	/// <summary>
	/// Gets integer type
	/// </summary>
	/// <param name="index">Position relative to size of type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const int16_t atInt16_t(uint32_t index) const = 0;

	/// <summary>
	/// Gets integer type
	/// </summary>
	/// <param name="index">Position relative to size of type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const int24_t atInt24_t(uint32_t index) const = 0;

	/// <summary>
	/// Gets integer type
	/// </summary>
	/// <param name="index">Position relative to size of type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const int32_t atInt32_t(uint32_t index) const = 0;

	/// <summary>
	/// Gets float value from given sample index. Translates from byte array
	/// </summary>
	/// <param name="index">Position relative to the size of the type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const float atFloat(uint32_t index) const = 0;

	/// <summary>
	/// Gets float value from given sample index. Translates from byte array
	/// </summary>
	/// <param name="index">Position relative to the size of the type</param>
	/// <returns>Typefull of bytes at given realtive index</returns>
	virtual const double atDouble(uint32_t index) const = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, uint8_t value) = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, int16_t value) = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, int24_t value) = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, int32_t value) = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, float value) = 0;

	/// <summary>
	/// Sets sample at
	/// </summary>
	/// <param name="index">Position relative of the sample</param>
	/// <param name="value">New value of the sample</param>
	virtual void setAt(uint32_t index, double value) = 0;
};