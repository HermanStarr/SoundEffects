#include "RAWHolder.h"

RAWHolder::RAWHolder(const std::string& path, int number_of_channels, uint32_t sample_rate, uint8_t bitsPerSample, uint16_t compressionCode) :
    NumChannels(number_of_channels), SampleRate(sample_rate), BitsPerSample(bitsPerSample), CompressionCode(compressionCode)
{
    struct stat stat_buf;
    int rc = stat(path.c_str(), &stat_buf);
    if (rc == 0)
    {
        FileSize = stat_buf.st_size;
        SamplesNumber = FileSize / (BitsPerSample >> 3);
        std::ifstream input;
        input.open(path, std::ios::binary);
        if (input.is_open())
        {
            Samples = new unsigned char[FileSize];
            input.read((char*)Samples, FileSize);
            input.close();
        }
        else
        {
            Samples = nullptr;
        }
    }
    else
    {
        Samples = nullptr;
    }
}

RAWHolder::RAWHolder(const RAWHolder& other) :
    NumChannels(other.NumChannels), FileSize(other.FileSize), SampleRate(other.SampleRate),
    SamplesNumber(other.SamplesNumber), BitsPerSample(other.BitsPerSample), CompressionCode(other.CompressionCode)
{
    Samples = new unsigned char[FileSize];

    for (uint32_t i = 0; i < FileSize; i++)
    {
        Samples[i] = other.Samples[i];
    }
}


RAWHolder::RAWHolder(int number_of_channels, uint32_t sample_rate, float duration, uint8_t bitsPerSample, uint16_t compressionCode) :
    NumChannels(number_of_channels), SampleRate(sample_rate), BitsPerSample(bitsPerSample), CompressionCode(compressionCode)
{
    FileSize = static_cast<uint32_t>(SampleRate * NumChannels * (BitsPerSample >> 3) * duration);
    SamplesNumber = FileSize / (BitsPerSample >> 3);
    Samples = new unsigned char[FileSize];
}

RAWHolder::RAWHolder(const RAWHolder& other, uint32_t resize) :
    NumChannels(other.NumChannels), SampleRate(other.SampleRate), BitsPerSample(other.BitsPerSample), CompressionCode(other.CompressionCode)
{
    FileSize = other.FileSize + resize * (BitsPerSample >> 3);
    SamplesNumber = other.SamplesNumber + resize;
    Samples = new unsigned char[FileSize];

    uint32_t i = 0;
    for (; i < other.FileSize; i++)
    {
        Samples[i] = other.Samples[i];
    }
    for (; i < FileSize; i++)
    {
        Samples[i] = 0;
    }
}

RAWHolder::~RAWHolder()
{
    if (Samples != nullptr)
        delete[] Samples;
}

const uint32_t RAWHolder::getSamplesNumber() const
{
    return SamplesNumber;
}

const uint16_t RAWHolder::getBitsPerSample() const
{
    return BitsPerSample;
}

uint32_t RAWHolder::getDelay(float modifier)
{
    return (uint32_t)(SampleRate * modifier * static_cast<float>(NumChannels));
}

const uint16_t RAWHolder::getCompressionCode() const
{
    return CompressionCode;
}

float RAWHolder::getDuration()
{
    return static_cast<float>(SamplesNumber) / SampleRate / NumChannels;
}

uint16_t RAWHolder::getNumChannels()
{
    return NumChannels;
}

uint32_t RAWHolder::getSampleRate()
{
    return SampleRate;
}

bool RAWHolder::writeToFile(const std::string& path)
{
    std::ofstream output;
    output.open(path, std::ios::binary);
    if (output.is_open())
    {
        output.write((char*)Samples, FileSize);
        output.close();
        return true;
    }
    return false;
}

const unsigned char RAWHolder::at(uint32_t index) const
{
    return Samples[index];
}

const uint8_t RAWHolder::atUint8_t(uint32_t index) const
{
    return at(index);
}

const int16_t RAWHolder::atInt16_t(uint32_t index) const
{
    return ((unsigned short)Samples[index * 2] << 8) | Samples[index * 2 + 1];
}

const int24_t RAWHolder::atInt24_t(uint32_t index) const
{
    return ((unsigned)Samples[index * 3] << 16) | ((unsigned short)Samples[index * 3 + 1] << 8) | Samples[index * 3 + 2];
}

const int32_t RAWHolder::atInt32_t(uint32_t index) const
{
    return ((unsigned)Samples[index * 4] << 24) | ((unsigned)Samples[index * 4 + 1] << 16) | ((unsigned short)Samples[index * 4 + 2] << 8) | Samples[index * 4 + 3];
}

const float RAWHolder::atFloat(uint32_t index) const
{
    unsigned char typeBytes[4];
    typeBytes[0] = Samples[index * 4];
    typeBytes[1] = Samples[index * 4 + 1];
    typeBytes[2] = Samples[index * 4 + 2];
    typeBytes[3] = Samples[index * 4 + 3];
    float value;
    std::memcpy(&value, typeBytes, 4);
    return value;
}

const double RAWHolder::atDouble(uint32_t index) const
{
    unsigned char typeBytes[8];
    typeBytes[0] = Samples[index * 4];
    typeBytes[1] = Samples[index * 4 + 1];
    typeBytes[2] = Samples[index * 4 + 2];
    typeBytes[3] = Samples[index * 4 + 3];
    typeBytes[4] = Samples[index * 4 + 4];
    typeBytes[5] = Samples[index * 4 + 5];
    typeBytes[6] = Samples[index * 4 + 6];
    typeBytes[7] = Samples[index * 4 + 7];
    double value;
    std::memcpy(&value, typeBytes, 8);
    return value;
}

void RAWHolder::setAt(uint32_t index, uint8_t value)
{
    Samples[index] = value & 0b11111111;
}

void RAWHolder::setAt(uint32_t index, int16_t value)
{
    Samples[index * 2] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 1] = value & 0b11111111;
}

void RAWHolder::setAt(uint32_t index, int24_t value)
{
    Samples[index * 2] = (value >> 16) & 0b11111111;
    Samples[index * 2 + 1] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 1] = value & 0b11111111;
}

void RAWHolder::setAt(uint32_t index, int32_t value)
{
    Samples[index * 2] = (value >> 24) & 0b11111111;
    Samples[index * 2 + 1] = (value >> 16) & 0b11111111;
    Samples[index * 2 + 2] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 3] = value & 0b11111111;
}

void RAWHolder::setAt(uint32_t index, float value)
{
    char* bytes = reinterpret_cast<char*>(&value);
    Samples[index * 4] = bytes[4];
    Samples[index * 4 + 1] = bytes[5];
    Samples[index * 4 + 2] = bytes[6];
    Samples[index * 4 + 3] = bytes[7];
}

void RAWHolder::setAt(uint32_t index, double value)
{
    char* bytes = reinterpret_cast<char*>(&value);
    Samples[index * 8] = bytes[0];
    Samples[index * 8 + 1] = bytes[1];
    Samples[index * 8 + 2] = bytes[2];
    Samples[index * 8 + 3] = bytes[3];
    Samples[index * 8 + 4] = bytes[4];
    Samples[index * 8 + 5] = bytes[5];
    Samples[index * 8 + 6] = bytes[6];
    Samples[index * 8 + 7] = bytes[7];
}


