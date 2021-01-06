#pragma once
#include "../Headers.h"

class Wave
{
public:
	virtual int32_t* execute(int32_t samples_per_tone) = 0;
	virtual float* execute(float samples_per_tone) = 0;
	virtual double* execute(double samples_per_tone) = 0;
	virtual ~Wave() {};
};

class SineWave :
	public Wave
{
	/// <summary>
	/// Method creates audio output as given by the laboratory supervisor e).
	/// Link to wave function: https://www.desmos.com/calculator/repcmjk4gn
	/// </summary>
	/// <param name="samples_per_tone">Number of samples per tone</param>
	/// <returns>Value of sample at given position</returns>
	int32_t* execute(int32_t samples_per_tone) override;

	/// <summary>
	/// Method creates audio output as given by the laboratory supervisor e).
	/// Link to wave function: https://www.desmos.com/calculator/repcmjk4gn
	/// </summary>
	/// <param name="samples_per_tone">Number of samples per tone</param>
	/// <returns>Value of sample at given position</returns>
	float* execute(float samples_per_tone) override;

	/// <summary>
	/// Method creates audio output as given by the laboratory supervisor e).
	/// Link to wave function: https://www.desmos.com/calculator/repcmjk4gn
	/// </summary>
	/// <param name="samples_per_tone">Number of samples per tone</param>
	/// <returns>Value of sample at given position</returns>
	double* execute(double samples_per_tone) override;
};

class TriangularWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class SharkteehWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class ReversedSharkteehWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class DentedTriangularWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class SquareWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class HexagonalWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};

class OctagonalWave :
	public Wave
{
	int32_t* execute(int32_t samples_per_tone) override;
	float* execute(float samples_per_tone) override;
	double* execute(double samples_per_tone) override;
};