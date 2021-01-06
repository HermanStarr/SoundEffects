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
        SamplesNumber = _Header.Subchunk2Size / sizeof(usedType);
        Samples = new usedType[_Header.Subchunk2Size / sizeof(usedType)];
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

    Samples = new usedType[SamplesNumber];

    for (uint32_t i = 0; i < SamplesNumber; i++)
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
    Samples = new usedType[SamplesNumber];

    for (uint32_t i = 0; i < SamplesNumber; i++)
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
    _Header.ChunkSize = other._Header.ChunkSize + resize * sizeof(usedType);
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
    _Header.Subchunk2Size = other._Header.Subchunk2Size + resize * sizeof(usedType);

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

WAVHolder::~WAVHolder()
{
    if (Samples != nullptr)
        delete[] Samples;
}

uint32_t WAVHolder::getSamplesNumber()
{
    return SamplesNumber;
}

uint32_t WAVHolder::getDelay(float modifier)
{
    return (uint32_t)((float)_Header.SampleRate * modifier * _Header.NumChannels);
}

float WAVHolder::getDuration()
{
    return (float)SamplesNumber / _Header.SampleRate / _Header.NumChannels;
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

const usedType& WAVHolder::operator[](std::uint32_t index) const
{
    return Samples[index % SamplesNumber];
}

const usedType WAVHolder::at(uint32_t index) const
{
    return Samples[index];
}

void WAVHolder::setAt(uint32_t index, usedType value)
{
    Samples[index] = value;
}




