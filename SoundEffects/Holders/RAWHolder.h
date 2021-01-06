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

    /// <summary>
    /// Sound samples
    /// </summary>
    usedType* Samples;
public:

    /// <summary>
    /// Constructor reading audio from file
    /// </summary>
    /// <param name="path">A path to an audio file</param>
    /// <param name="number_of_channels">Number of channels present in a file</param>
    /// <param name="sample_rate">Sample rate of given audio file</param>
    RAWHolder(const std::string& path, int number_of_channels, uint32_t sample_rate);

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
    RAWHolder(int number_of_channels, uint32_t sample_rate, float duration);

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
    uint32_t getSamplesNumber() override;

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
    /// Overloads [] operator
    /// </summary>
    /// <param name="index">Index of a sample in an array</param>
    /// <returns>A reference to a sample in the Sample array</returns>
    const usedType& operator [](std::uint32_t index) const override;

    /// <summary>
    /// Gets sample at
    /// </summary>
    /// <param name="index">Position of the sample</param>
    /// <returns>Sample at the position</returns>
    const usedType at(uint32_t index) const override;

    /// <summary>
    /// Sets sample at
    /// </summary>
    /// <param name="index">Position of the sample</param>
    /// <param name="value">New value of the sample</param>
    void setAt(uint32_t index, usedType value) override;
};