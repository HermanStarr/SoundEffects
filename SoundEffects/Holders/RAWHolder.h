#pragma once
#include "Holder.h"

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
    usedType& operator [](std::uint32_t index) const override;
};