#pragma once
#include "Holder.h"
#include "RAWHolder.h"
#include "../Exceptions/HolderConstructionException.h"

class RAWHolder;

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
    unsigned char* Samples;

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
    /// Constructor taking RAW type of file
    /// </summary>
    /// <param name="other">RAW sound file to be copied</param>
    WAVHolder(RAWHolder& other, uint16_t bytesPerSample = 2, uint16_t audioFormat = 1);

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
    float getDuration() override;

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

