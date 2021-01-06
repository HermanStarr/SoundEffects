#pragma once
#include "Holders/RAWHolder.h"
#include "Holders/WAVHolder.h"
#include "Effects/ReverberationEffect.h"


/// <summary>
/// Function merges two audio files with a given offset and volume modifier
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="offset">Index being offset of samples</param>
/// <param name="modifier">Volume modifier</param>
void mergeTwoSounds(Holder& merger, Holder& mergee, uint32_t offset, float modifier = 1.f);

/// <summary>
/// Function makes an echo with a given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeEcho(Holder& merger, Holder& mergee, float delay);

/// <summary>
/// Functions makes triple echoe with given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeTripleEcho(Holder& merger, Holder& mergee, float delay);

/// <summary>
/// Function makes "Infinite Echo" with a given delay and volume loss
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
/// <param name="modifier">Volume modifier of an effect</param>
void makeInfiniteEcho(Holder& merger, Holder& mergee, float delay, float modifier = 1.f);


/// <summary>
/// Makes reverberation effect on given wav or raw file
/// </summary>
/// <param name="holder"></param>
void makeReverberation(Holder& holder);