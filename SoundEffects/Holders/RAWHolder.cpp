#include "RAWHolder.h"

RAWHolder::RAWHolder(const std::string& path, int number_of_channels, uint32_t sample_rate)
{
    NumChannels = number_of_channels;
    SampleRate = sample_rate;
    struct stat stat_buf;
    int rc = stat(path.c_str(), &stat_buf);
    if (rc == 0)
    {
        FileSize = stat_buf.st_size;
        SamplesNumber = FileSize / sizeof(usedType);
        std::ifstream input;
        input.open(path, std::ios::binary);
        if (input.is_open())
        {
            Samples = new usedType[SamplesNumber];
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

RAWHolder::RAWHolder(const RAWHolder& other)
{
    NumChannels = other.NumChannels;
    FileSize = other.FileSize;
    SampleRate = other.SampleRate;
    SamplesNumber = other.SamplesNumber;
    Samples = new usedType[SamplesNumber];

    for (int i = 0; i < SamplesNumber; i++)
    {
        Samples[i] = other.Samples[i];
    }
}

RAWHolder::RAWHolder(const RAWHolder& other, uint32_t resize)
{
    NumChannels = other.NumChannels;
    FileSize = other.FileSize + resize * sizeof(usedType);
    SampleRate = other.SampleRate;
    SamplesNumber = other.SamplesNumber + resize;
    Samples = new usedType[SamplesNumber];
    uint32_t i = 0;
    for (; i < other.SamplesNumber; i++)
    {
        Samples[i] = other.Samples[i];
    }
    for (; i < SamplesNumber; i++)
    {
        Samples[i] = (usedType)0;
    }
}

RAWHolder::~RAWHolder()
{
    if (Samples != nullptr)
        delete Samples;
}

uint32_t RAWHolder::getSamplesNumber()
{
    return SamplesNumber;
}

uint32_t RAWHolder::getDelay(float modifier)
{
    return (uint32_t)((float)SampleRate * modifier * NumChannels);
}

float RAWHolder::getDuration()
{
    return (float)SamplesNumber / SampleRate / NumChannels;
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

usedType& RAWHolder::operator[](std::uint32_t index) const
{
    return Samples[index % SamplesNumber];
}
