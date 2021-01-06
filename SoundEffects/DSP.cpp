#include "DSP.h"

void makeReverberation(Holder& holder)
{
    ReverberationEffect reverb(holder);
    reverb.init();
}

void mergeTwoSounds(Holder& merger, Holder& mergee, uint32_t offset, float modifier)
{
    uint32_t size = mergee.getSamplesNumber() < merger.getSamplesNumber() - offset ? mergee.getSamplesNumber() : merger.getSamplesNumber() - offset;
    if (offset > merger.getSamplesNumber())
        return;

    for (uint32_t i = 0; i < size; i++)
    {
        merger.setAt(i + offset,  merger.at(i + offset) + (uint16_t)((float)mergee[i] * modifier));
    }
}
void makeEcho(Holder& merger, Holder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
}
void makeTripleEcho(Holder& merger, Holder& mergee, float delay)
{
    mergeTwoSounds(merger, mergee, merger.getDelay(delay));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 2));
    mergeTwoSounds(merger, mergee, merger.getDelay(delay * 3));
}
void makeInfiniteEcho(Holder& merger, Holder& mergee, float delay, float modifier)
{
    for(int i = 1; i <= merger.getDuration() * 2; i++)
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