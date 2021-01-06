#pragma once
#include "Holder.h"

/// <summary>
/// Class containing WAV file and allowing manipulation of it
/// </summary>
class WAVHolder : public Holder{

    /// <summary>
    /// Struct containing header of a WAV file
    /// </summary>
    struct Header {

        uint8_t         ChunkID[4];
        uint32_t        ChunkSize;
        uint8_t         Format[4];
        uint8_t         Subchunk1ID[4];
        uint32_t        Subchunk1Size;
        uint16_t        AudioFormat;
        uint16_t        NumChannels;
        uint32_t        SampleRate;
        uint32_t        ByteRate;
        uint16_t        BlockAlign;
        uint16_t        BitsPerSample;
        uint8_t         Subchunk2ID[4];
        uint32_t        Subchunk2Size;
    };

    /// <summary>
    /// Unique instance of a header for a given WAV instance
    /// </summary>
    Header _Header = Header();

    /// <summary>
    /// Number of every sample in an audio file
    /// </summary>
    uint32_t SamplesNumber;

    /// <summary>
    /// Samples array
    /// </summary>
    usedType* Samples;

public:

    /// <summary>
    /// Constructor reading audio from file
    /// </summary>
    /// <param name="path">A path to an audio file</param>
    WAVHolder(const std::string& path);

    /// <summary>
    /// Copy constructor of this class
    /// </summary>
    /// <param name="other">Copied instance of a class</param>
    WAVHolder(const WAVHolder& other);

    /// <summary>
    /// Copy constructor of this class with resize
    /// </summary>
    /// <param name="other">Copied instance of a class</param>
    /// <param name="resize">Number of samples to be added</param>
    WAVHolder(const WAVHolder& other, uint32_t resize);

    /// <summary>
    /// Destructor
    /// </summary>
    ~WAVHolder();

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
    float getDuration() override;

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