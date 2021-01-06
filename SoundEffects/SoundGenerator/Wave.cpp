#include "Wave.h"


////////////////////////////Sine///////////////////////////////////
int32_t* SineWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<int32_t>(sin(2.f * M_PI * static_cast<float>(i) / samples_per_tone));
	return array;
}

float* SineWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<float>(sin(2.f * M_PI * static_cast<float>(i) / samples_per_tone));
	return array;
}

double* SineWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = sin(2. * M_PI * static_cast<double>(i) / samples_per_tone);
	return array;
}


////////////////////////////Triangular//////////////////////////////
int32_t* TriangularWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<int32_t>(abs(abs(4.f * static_cast<float>(i) / samples_per_tone - 1.f) - 2.f) - 1.f);
	return array;
}

float* TriangularWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = abs(abs(4.f * static_cast<float>(i) / samples_per_tone - 1.f) - 2.f) - 1.f;
	return array;
}

double* TriangularWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = abs(abs(4. * static_cast<double>(i) / samples_per_tone - 1.) - 2.) - 1.;
	return array;
}


////////////////////////////Sharkteeth//////////////////////////////
int32_t* SharkteehWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<int32_t>(2.f * static_cast<float>(i) / samples_per_tone - 1.f);
	return array;
}

float* SharkteehWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = 2.f * static_cast<float>(i) / samples_per_tone - 1.f;
	return array;
}

double* SharkteehWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = 2. * static_cast<double>(i) / samples_per_tone - 1.;
	return array;
}


////////////////////////Reversed Sharkteeh//////////////////////////
int32_t* ReversedSharkteehWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<int32_t>(-2.f * static_cast<float>(i) / samples_per_tone + 1.f);
	return array;
}

float* ReversedSharkteehWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = -2.f * static_cast<float>(i) / samples_per_tone + 1.f;
	return array;
}

double* ReversedSharkteehWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = -2. * static_cast<double>(i) / samples_per_tone + 1.;
	return array;
}


////////////////////////Dented Triangular///////////////////////////
int32_t* DentedTriangularWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = static_cast<int32_t>((abs(abs(abs(1.5f * abs(4.f * (static_cast<float>(i) / samples_per_tone) - 1.f) - 0.5f) - 2.5f) - 0.5f) - 1.f));
	return array;
}

float* DentedTriangularWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = (abs(abs(abs(1.5f * abs(4.f * (static_cast<float>(i) / samples_per_tone) - 1.f) - 0.5f) - 2.5f) - 0.5f) - 1.f);
	return array;
}

double* DentedTriangularWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		array[i] = (abs(abs(abs(1.5 * abs(4. * (static_cast<double>(i) / samples_per_tone) - 1.) - 0.5) - 2.5) - 0.5) - 1.);
	return array;
}


//////////////////////////////Square////////////////////////////////
int32_t* SquareWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone < 0.5f)
			array[i] = 1;
		else
			array[i] = -1;
	return array;
}

float* SquareWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone < 0.5f)
			array[i] = 1.f;
		else
			array[i] = -1.f;
	return array;
}

double* SquareWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone < 0.5f)
			array[i] = 1.0;
		else
			array[i] = -1.0;
	return array;
}


////////////////////////////Hexagonal//////////////////////////////
int32_t* HexagonalWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone <= 0.25f)
			array[i] = 1;
		else if (static_cast<float>(i) / samples_per_tone <= 0.5f)
			array[i] = static_cast<int32_t>(-8.f * static_cast<float>(i) / samples_per_tone + 3.f);
		else if (static_cast<float>(i) / samples_per_tone <= 0.75f)
			array[i] = -1;
		else
			array[i] = static_cast<int32_t>(-8.f * static_cast<float>(i) / samples_per_tone - 7.f);
	return array;
}

float* HexagonalWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone <= 0.25f)
			array[i] = 1.f;
		else if (static_cast<float>(i) / samples_per_tone <= 0.5f)
			array[i] = -8.f * static_cast<float>(i) / samples_per_tone + 3.f;
		else if (static_cast<float>(i) / samples_per_tone <= 0.75f)
			array[i] = -1.f;
		else
			array[i] = -8.f * static_cast<float>(i) / samples_per_tone - 7.f;
	return array;
}

double* HexagonalWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone <= 0.25f)
			array[i] = 1.;
		else if (static_cast<float>(i) / samples_per_tone <= 0.5f)
			array[i] = -8. * static_cast<double>(i) / samples_per_tone + 3.;
		else if (static_cast<float>(i) / samples_per_tone <= 0.75f)
			array[i] = -1.;
		else
			array[i] = -8. * static_cast<double>(i) / samples_per_tone - 7.;
	return array;
}


////////////////////////////Octagonal//////////////////////////////
int32_t* OctagonalWave::execute(int32_t samples_per_tone)
{
	int32_t* array = new int32_t[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH)
			array[i] = static_cast<int32_t>(1.5f * static_cast<float>(i) / samples_per_tone + 0.75f);
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 2.f)
			array[i] = static_cast<int32_t>(-1.5f * static_cast<float>(i) / samples_per_tone + 1.25f);
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 3.f)
			array[i] = static_cast<int32_t>(-9.f * static_cast<float>(i) / samples_per_tone + 3.75f);
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 4.f)
			array[i] = static_cast<int32_t>(1.5f * static_cast<float>(i) / samples_per_tone);
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 5.f)
			array[i] = static_cast<int32_t>(1.5f * static_cast<float>(i) / samples_per_tone - 2.f);
		else
			array[i] = static_cast<int32_t>(9.f * static_cast<float>(i) / samples_per_tone - 8.25f);
	return array;
}

float* OctagonalWave::execute(float samples_per_tone)
{
	float* array = new float[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
		if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH)
			array[i] = 1.5f * static_cast<float>(i) / samples_per_tone + 0.75f;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 2.f)
			array[i] = -1.5f * static_cast<float>(i) / samples_per_tone + 1.25f;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 3.f)
			array[i] = -9.f * static_cast<float>(i) / samples_per_tone + 3.75f;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 4.f)
			array[i] = 1.5f * static_cast<float>(i) / samples_per_tone;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 5.f)
			array[i] = 1.5f * static_cast<float>(i) / samples_per_tone - 2.f;
		else
			array[i] = 9.f * static_cast<float>(i) / samples_per_tone - 8.25f;
	return array;
}

double* OctagonalWave::execute(double samples_per_tone)
{
	double* array = new double[static_cast<uint32_t>(samples_per_tone)];
	for (uint32_t i = 0; i < static_cast<uint32_t>(samples_per_tone); i++)
			 if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH)
			array[i] = 1.5 * static_cast<double>(i) / samples_per_tone + 0.75;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 2.f)
			array[i] = -1.5 * static_cast<double>(i) / samples_per_tone + 1.25;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 3.f)
			array[i] = -9. * static_cast<double>(i) / samples_per_tone + 3.75;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 4.f)
			array[i] = 1.5 * static_cast<double>(i) / samples_per_tone;
		else if (static_cast<float>(i) / samples_per_tone <= ONE_SIXTH * 5.f)
			array[i] = 1.5 * static_cast<double>(i) / samples_per_tone - 2.;
		else
			array[i] = 9. * static_cast<double>(i) / samples_per_tone - 8.25;
	return array;
}
