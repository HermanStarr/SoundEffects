#pragma once
#include "Effect.h"
#include "../Holders/Holders.h"
#include "../Circuit/Circuit.h"

/// <summary>
/// Class for performing an instant reverberation effect
/// </summary>
class ReverberationEffect : public Effect
{
	/// <summary>
	/// Sounf file reference
	/// </summary>
	Holder& holder;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="holder">Reference to sound file</param>
	ReverberationEffect(Holder& holder);
	
	~ReverberationEffect();

	/// <summary>
	/// Adds reverberation effect to the sound file
	/// </summary>
	void init();
};

