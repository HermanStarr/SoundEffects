#include "WAVHolder.h"

WAVHolder::WAVHolder(const std::string& path)
{
    std::ifstream input;
    input.open(path, std::ios::binary);
    if (input.is_open())
    {
        input.read((char*)_Header.ChunkID, 4);
        input.read((char*)&_Header.ChunkSize, 4);
        input.read((char*)_Header.Format, 4);
        input.read((char*)_Header.Subchunk1ID, 4);
        input.read((char*)&_Header.Subchunk1Size, 4);
        input.read((char*)&_Header.AudioFormat, 2);
        input.read((char*)&_Header.NumChannels, 2);
        input.read((char*)&_Header.SampleRate, 4);
        input.read((char*)&_Header.ByteRate, 4);
        input.read((char*)&_Header.BlockAlign, 2);
        input.read((char*)&_Header.BitsPerSample, 2);
        input.read((char*)_Header.Subchunk2ID, 4);
        input.read((char*)&_Header.Subchunk2Size, 4);

        SamplesNumber = _Header.Subchunk2Size / (_Header.BitsPerSample >> 3);
        Samples = new unsigned char[_Header.Subchunk2Size];
        input.read((char*)Samples, _Header.Subchunk2Size);
        input.close();
    }
    else
    {
        throw(HolderConstructionException("Input file at: " + path  + " could not be opened"));
    }
}

WAVHolder::WAVHolder(const WAVHolder& other)
{
    _Header.ChunkID[0] = other._Header.ChunkID[0];
    _Header.ChunkID[1] = other._Header.ChunkID[1];
    _Header.ChunkID[2] = other._Header.ChunkID[2];
    _Header.ChunkID[3] = other._Header.ChunkID[3];
    _Header.ChunkSize = other._Header.ChunkSize;
    _Header.Format[0] = other._Header.Format[0];
    _Header.Format[1] = other._Header.Format[1];
    _Header.Format[2] = other._Header.Format[2];
    _Header.Format[3] = other._Header.Format[3];
    _Header.Subchunk1ID[0] = other._Header.Subchunk1ID[0];
    _Header.Subchunk1ID[1] = other._Header.Subchunk1ID[1];
    _Header.Subchunk1ID[2] = other._Header.Subchunk1ID[2];
    _Header.Subchunk1ID[3] = other._Header.Subchunk1ID[3];
    _Header.Subchunk1Size = other._Header.Subchunk1Size;
    _Header.AudioFormat = other._Header.AudioFormat;
    _Header.NumChannels = other._Header.NumChannels;
    _Header.SampleRate = other._Header.SampleRate;
    _Header.ByteRate = other._Header.ByteRate;
    _Header.BlockAlign = other._Header.BlockAlign;
    _Header.BitsPerSample = other._Header.BitsPerSample;
    _Header.Subchunk2ID[0] = other._Header.Subchunk2ID[0];
    _Header.Subchunk2ID[1] = other._Header.Subchunk2ID[1];
    _Header.Subchunk2ID[2] = other._Header.Subchunk2ID[2];
    _Header.Subchunk2ID[3] = other._Header.Subchunk2ID[3];
    _Header.Subchunk2Size = other._Header.Subchunk2Size;

    SamplesNumber = other.SamplesNumber;

    Samples = new unsigned char[_Header.Subchunk2Size];

    for (uint32_t i = 0; i < _Header.Subchunk2Size; i++)
    {
        Samples[i] = other.Samples[i];
    }
}

WAVHolder::WAVHolder(RAWHolder& other, uint16_t bytesPerSample, uint16_t audioFormat)
{
    _Header.ChunkID[0] = 'R';
    _Header.ChunkID[1] = 'I';
    _Header.ChunkID[2] = 'F';
    _Header.ChunkID[3] = 'F';
    _Header.ChunkSize = (uint32_t)36 + other.getSamplesNumber() * static_cast<uint32_t>(other.getNumChannels()) * bytesPerSample;
    _Header.Format[0] = 'W';
    _Header.Format[1] = 'A';
    _Header.Format[2] = 'V';
    _Header.Format[3] = 'E';
    _Header.Subchunk1ID[0] = 'f';
    _Header.Subchunk1ID[1] = 'm';
    _Header.Subchunk1ID[2] = 't';
    _Header.Subchunk1ID[3] = ' ';
    _Header.Subchunk1Size = 16;
    _Header.AudioFormat = audioFormat;
    _Header.NumChannels = other.getNumChannels();;
    _Header.SampleRate = other.getSampleRate();
    _Header.ByteRate = _Header.SampleRate * _Header.NumChannels * bytesPerSample;
    _Header.BlockAlign = _Header.NumChannels * bytesPerSample;
    _Header.BitsPerSample = bytesPerSample << 3;
    _Header.Subchunk2ID[0] = 'd';
    _Header.Subchunk2ID[1] = 'a';
    _Header.Subchunk2ID[2] = 't';
    _Header.Subchunk2ID[3] = 'a';
    _Header.Subchunk2Size = _Header.ChunkSize - 36;

    SamplesNumber = other.getSamplesNumber();
    Samples = new unsigned char[_Header.Subchunk2Size];

    for (uint32_t i = 0; i < _Header.Subchunk2Size; i++)
    {
        Samples[i] = other.at(i);
    }
}


WAVHolder::WAVHolder(const WAVHolder& other, uint32_t resize)
{
    _Header.ChunkID[0] = other._Header.ChunkID[0];
    _Header.ChunkID[1] = other._Header.ChunkID[1];
    _Header.ChunkID[2] = other._Header.ChunkID[2];
    _Header.ChunkID[3] = other._Header.ChunkID[3];
    _Header.ChunkSize = other._Header.ChunkSize + resize * (other._Header.BitsPerSample >> 3);
    _Header.Format[0] = other._Header.Format[0];
    _Header.Format[1] = other._Header.Format[1];
    _Header.Format[2] = other._Header.Format[2];
    _Header.Format[3] = other._Header.Format[3];
    _Header.Subchunk1ID[0] = other._Header.Subchunk1ID[0];
    _Header.Subchunk1ID[1] = other._Header.Subchunk1ID[1];
    _Header.Subchunk1ID[2] = other._Header.Subchunk1ID[2];
    _Header.Subchunk1ID[3] = other._Header.Subchunk1ID[3];
    _Header.Subchunk1Size = other._Header.Subchunk1Size;
    _Header.AudioFormat = other._Header.AudioFormat;
    _Header.NumChannels = other._Header.NumChannels;
    _Header.SampleRate = other._Header.SampleRate;
    _Header.ByteRate = other._Header.ByteRate;
    _Header.BlockAlign = other._Header.BlockAlign;
    _Header.BitsPerSample = other._Header.BitsPerSample;
    _Header.Subchunk2ID[0] = other._Header.Subchunk2ID[0];
    _Header.Subchunk2ID[1] = other._Header.Subchunk2ID[1];
    _Header.Subchunk2ID[2] = other._Header.Subchunk2ID[2];
    _Header.Subchunk2ID[3] = other._Header.Subchunk2ID[3];
    _Header.Subchunk2Size = other._Header.Subchunk2Size + resize * (other._Header.BitsPerSample >> 3);

    SamplesNumber = other.SamplesNumber + resize;

    Samples = new unsigned char[_Header.Subchunk2Size];
    uint32_t i = 0;
    for (; i < other._Header.Subchunk2Size; i++)
    {
        Samples[i] = other.Samples[i];
    }
    for (; i < _Header.Subchunk2Size; i++)
    {
        Samples[i] = 0;
    }
}

WAVHolder::~WAVHolder()
{
    if (Samples != nullptr)
        delete[] Samples;
}

const uint32_t WAVHolder::getSamplesNumber() const
{
    return SamplesNumber;
}

const uint16_t WAVHolder::getBitsPerSample() const
{
    return _Header.BitsPerSample;
}

uint32_t WAVHolder::getDelay(float modifier)
{
    return static_cast<uint32_t>(_Header.SampleRate * modifier * static_cast<float>(_Header.NumChannels));
}

const uint16_t WAVHolder::getCompressionCode() const
{
    return _Header.AudioFormat;
}

float WAVHolder::getDuration()
{
    return static_cast<float>(SamplesNumber) / _Header.SampleRate / _Header.NumChannels;
}

bool WAVHolder::writeToFile(const std::string& path)
{
    std::ofstream output;
    output.open(path, std::ios::binary);
    if (output.is_open())
    {
        output.write((char*)_Header.ChunkID, 4);
        output.write((char*)&_Header.ChunkSize, 4);
        output.write((char*)_Header.Format, 4);
        output.write((char*)_Header.Subchunk1ID, 4);
        output.write((char*)&_Header.Subchunk1Size, 4);
        output.write((char*)&_Header.AudioFormat, 2);
        output.write((char*)&_Header.NumChannels, 2);
        output.write((char*)&_Header.SampleRate, 4);
        output.write((char*)&_Header.ByteRate, 4);
        output.write((char*)&_Header.BlockAlign, 2);
        output.write((char*)&_Header.BitsPerSample, 2);
        output.write((char*)_Header.Subchunk2ID, 4);
        output.write((char*)&_Header.Subchunk2Size, 4);
        output.write((char*)Samples, _Header.Subchunk2Size);

        output.close();
        return true;
    }
    return false;
}

const unsigned char WAVHolder::at(uint32_t index) const
{
    return Samples[index];
}

const uint8_t WAVHolder::atUint8_t(uint32_t index) const
{
    return at(index);
}

const int16_t WAVHolder::atInt16_t(uint32_t index) const
{
    return ((unsigned short)Samples[index * 2] << 8) | Samples[index * 2 + 1];
}

const int24_t WAVHolder::atInt24_t(uint32_t index) const
{
    return ((unsigned)Samples[index * 3] << 16) | ((unsigned short)Samples[index * 3 + 1] << 8) | Samples[index * 3 + 2];
}

const int32_t WAVHolder::atInt32_t(uint32_t index) const
{
    return ((unsigned)Samples[index * 4] << 24) | ((unsigned)Samples[index * 4 + 1] << 16) | ((unsigned short)Samples[index * 4 + 2] << 8) | Samples[index * 4 + 3];
}

const float WAVHolder::atFloat(uint32_t index) const
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

const double WAVHolder::atDouble(uint32_t index) const
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

void WAVHolder::setAt(uint32_t index, uint8_t value)
{
    Samples[index] = value & 0b11111111;
}

void WAVHolder::setAt(uint32_t index, int16_t value)
{
    Samples[index * 2] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 1] = value & 0b11111111;
}

void WAVHolder::setAt(uint32_t index, int24_t value)
{
    Samples[index * 2] = (value >> 16) & 0b11111111;
    Samples[index * 2 + 1] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 1] = value & 0b11111111;
}

void WAVHolder::setAt(uint32_t index, int32_t value)
{
    Samples[index * 2] = (value >> 24) & 0b11111111;
    Samples[index * 2 + 1] = (value >> 16) & 0b11111111;
    Samples[index * 2 + 2] = (value >> 8) & 0b11111111;
    Samples[index * 2 + 3] = value & 0b11111111;
}

void WAVHolder::setAt(uint32_t index, float value)
{
    char* bytes = reinterpret_cast<char*>(&value);
    Samples[index * 4] = bytes[4];
    Samples[index * 4 + 1] = bytes[5];
    Samples[index * 4 + 2] = bytes[6];
    Samples[index * 4 + 3] = bytes[7];
}

void WAVHolder::setAt(uint32_t index, double value)
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