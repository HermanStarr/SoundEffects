#include "DSP.h"


void mergeTwoSounds(WAVHolder& merger, WAVHolder& mergee, uint32_t offset, float modifier)
{
    uint32_t size = mergee.getSamplesNumber() < merger.getSamplesNumber() - offset ? mergee.getSamplesNumber() : merger.getSamplesNumber() - offset;
    if (offset > merger.getSamplesNumber())
        return;

    for (uint32_t i = 0; i < size; i++)
    {
        merger[i + offset] += (uint16_t)((float)mergee[i] * modifier);
    }
}
void makeEcho(WAVHolder& merger, WAVHolder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
}
void makeTripleEcho(WAVHolder& merger, WAVHolder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 2));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 3));
}
void makeInfiniteEcho(WAVHolder& merger, WAVHolder& mergee, float delay, float modifier)
{
    for(int i = 1; i <= merger.getDuration() * 2; i++)
        mergeTwoSounds(merger, mergee, merger.getDelay(delay * i), modifier / (i + 1));
}


void mergeTwoSounds(RAWHolder& merger, RAWHolder& mergee, uint32_t offset, float modifier)
{
    uint32_t size = mergee.getSamplesNumber() < merger.getSamplesNumber() - offset ? mergee.getSamplesNumber() : merger.getSamplesNumber() - offset;
    if (offset > merger.getSamplesNumber())
        return;

    for (uint32_t i = 0; i < size; i++)
    {
        merger[i + offset] += (uint16_t)((float)mergee[i] * modifier);
    }

}
void makeEcho(RAWHolder& merger, RAWHolder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
}
void makeTripleEcho(RAWHolder& merger, RAWHolder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 2));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 3));
}
void makeInfiniteEcho(RAWHolder& merger, RAWHolder& mergee, float delay, float modifier)
{
    for (int i = 1; i <= merger.getDuration() * 2; i++)
        mergeTwoSounds(merger, mergee, merger.getDelay(delay * i), modifier / (i + 1));
}

int checkExtension(const std::string& path)
{
    std::string extension = path.substr(path.find_last_of(".") + 1);
    if (extension == "wav")
    {
        return 0;
    }
    else if (extension == "raw")
    {
        return 1;
    }
    else
    {
        return -1;
    }
}