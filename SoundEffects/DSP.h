#pragma once
#include "Holders/RAWHolder.h"
#include "Holders/WAVHolder.h"


/// <summary>
/// Function merges two WAV files with a given offset and volume modifier
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="offset">Index being offset of samples</param>
/// <param name="modifier">Volume modifier</param>
void mergeTwoSounds(WAVHolder& merger, WAVHolder& mergee, uint32_t offset, float modifier = 1.f);

/// <summary>
/// Function makes an echo with a given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeEcho(WAVHolder& merger, WAVHolder& mergee, float delay);

/// <summary>
/// Functions makes triple echoe with given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeTripleEcho(WAVHolder& merger, WAVHolder& mergee, float delay);

/// <summary>
/// Function makes "Infinite Echo" with a given delay and volume loss
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
/// <param name="modifier">Volume modifier of an effect</param>
void makeInfiniteEcho(WAVHolder& merger, WAVHolder& mergee, float delay, float modifier = 1.f);

/// <summary>
/// Function merges two RAW audio files with a given offset and volume modifier
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="offset">Index being offset of samples</param>
/// <param name="modifier">Volume modifier</param>
void mergeTwoSounds(RAWHolder& merger, RAWHolder& mergee, uint32_t offset, float modifier = 1.f);

/// <summary>
/// Function makes an echo with a given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeEcho(RAWHolder& merger, RAWHolder& mergee, float delay);

/// <summary>
/// Functions makes triple echoe with given delay
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
void makeTripleEcho(RAWHolder& merger, RAWHolder& mergee, float delay);

/// <summary>
/// Function makes "Infinite Echo" with a given delay and volume loss
/// </summary>
/// <param name="merger">A target audio class</param>
/// <param name="mergee">A source audio class</param>
/// <param name="delay">Delay of an effect in seconds</param>
/// <param name="modifier">Volume modifier of an effect</param>
void makeInfiniteEcho(RAWHolder& merger, RAWHolder& mergee, float delay, float modifier = 1.f);

///	<summary>
/// Function checks an extension of a file
/// </summary>
/// <param name="path">Path to the given file</param>
/// <returns>Flag corresponding to the extension found</returns>
int checkExtension(const std::string& path);