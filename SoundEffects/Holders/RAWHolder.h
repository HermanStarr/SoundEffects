#pragma once
#include "Holder.h"
#include "WAVHolder.h"

/// <summary>
/// Class containing RAW audio file and allowing manipulation of it
/// </summary>
class RAWHolder : public Holder{

    /// <summary>
    /// Number of channels
    /// </summary>
    uint16_t NumChannels;

    /// <summary>
    /// Samples per second
    /// </summary>
    uint32_t SampleRate;

    /// <summary>
    /// Number of all samples in an audio file
    /// </summary>
    uint32_t SamplesNumber = 0;
    /// <summary>
    /// Size of file in bytes
    /// </summary>
    uint32_t FileSize = 0;

    uint8_t BitsPerSample = 16;

    uint16_t CompressionCode;

    /// <summary>
    /// Sound samples
    /// </summary>
    unsigned char* Samples;
public:

    /// <summary>
    /// Constructor reading audio from file
    /// </summary>
    /// <param name="path">A path to an audio file</param>
    /// <param name="number_of_channels">Number of channels present in a file</param>
    /// <param name="sample_rate">Sample rate of given audio file</param>
    RAWHolder(const std::string& path, int number_of_channels, uint32_t sample_rate, uint8_t bitsPerSample, uint16_t compressionCode);

    /// <summary>
    /// Copy constructor of this class
    /// </summary>
    /// <param name="other">Copied instance of a class</param>
    RAWHolder(const RAWHolder& other);

    /// <summary>
    /// Constructor for newly created sound file
    /// </summary>
    /// <param name="number_of_channels">Number of channels</param>
    /// <param name="sample_rate">Sample rate of the file</param>
    /// <param name="duration"Duration of file in seconds></param>
    RAWHolder(int number_of_channels, uint32_t sample_rate, float duration, uint8_t bitsPerSample, uint16_t compressionCode);

    /// <summary>
    /// Copy constructor of this class with resize
    /// </summary>
    /// <param name="other">Copied instance of a class</param>
    /// <param name="resize">Number of samples to be added</param>
    RAWHolder(const RAWHolder& other, uint32_t resize);

    /// <summary>
    /// Destructor
    /// </summary>
    ~RAWHolder();

    /// <summary>
    /// Samples NUmber getter
    /// </summary>
    /// <returns>SamplesNumber</returns>
    const uint32_t getSamplesNumber() const override;

    /// <summary>
    /// Gets bits per sample
    /// </summary>
    /// <returns>Number of bits per single sample</returns>
    const uint16_t getBitsPerSample() const override;

    /// <summary>
    /// Gets compression mode of the file
    /// </summary>
    /// <returns>Compression mode</returns>
    const uint16_t getCompressionCode() const override;

    /// <summary>
    /// Gets delay in number of samples
    /// </summary>
    /// <param name="modifier">Number of seconds to be processed</param>
    /// <returns>Get number of samples responding to a given number of seconds</returns>
    uint32_t getDelay(float modifier) override;

    /// <summary>
    /// Get audio length in seconds
    /// </summary>
    /// <returns>Audio length in seconds</returns>
    float getDuration();

    /// <summary>
    /// Gets number of channels
    /// </summary>
    /// <returns>Number of channels</returns>
    uint16_t getNumChannels();

    /// <summary>
    /// Gets sample rate
    /// </summary>
    /// <returns>Sample Rate of the file</returns>
    uint32_t getSampleRate();

    /// <summary>
    /// Write to an audio file the contents of this class
    /// </summary>
    /// <param name="path">Path to an audio file</param>
    /// <returns>True if done correctly</returns>
    bool writeToFile(const std::string& path) override;

    /// <summary>
    /// Gets byte from Samples at give index
    /// </summary>
    /// <param name="index">Index of position</param>
    /// <returns>Byte at given index</returns>
    const unsigned char at(uint32_t index) const override;

    /// <summary>
    /// Gets integer type
    /// </summary>
    /// <param name="index">Position relative to size of type</param>
    /// <param name="type">Integer type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const uint8_t atUint8_t(uint32_t index) const override;

    /// <summary>
    /// Gets integer type
    /// </summary>
    /// <param name="index">Position relative to size of type</param>
    /// <param name="type">Integer type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const int16_t atInt16_t(uint32_t index) const override;

    /// <summary>
    /// Gets integer type
    /// </summary>
    /// <param name="index">Position relative to size of type</param>
    /// <param name="type">Integer type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const int24_t atInt24_t(uint32_t index) const override;

    /// <summary>
    /// Gets integer type
    /// </summary>
    /// <param name="index">Position relative to size of type</param>
    /// <param name="type">Integer type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const int32_t atInt32_t(uint32_t index) const override;

    /// <summary>
    /// Gets float value from given sample index. Translates from byte array
    /// </summary>
    /// <param name="index">Position relative to the size of the type</param>
    /// <param name="type">Floating point type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const float atFloat(uint32_t index) const override;

    /// <summary>
    /// Gets float value from given sample index. Translates from byte array
    /// </summary>
    /// <param name="index">Position relative to the size of the type</param>
    /// <param name="type">Floating point type of the sample</param>
    /// <returns>Typefull of bytes at given realtive index</returns>
    const double atDouble(uint32_t index) const override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, uint8_t value) override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, int16_t value) override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, int24_t value) override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, int32_t value) override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, float value) override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position relative of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, double value) override;
};