#include "ReverberationEffect.h"

ReverberationEffect::ReverberationEffect(Holder& holder) : holder(holder)
{

}

ReverberationEffect::~ReverberationEffect()
{
}

void ReverberationEffect::init()
{
	Circuit circuit(0.7f);
	circuit.addElement<AllPassFilter>(4410u, 0.6f);
	circuit.addElement<AllPassFilter>(1470u, -0.6f);
	circuit.addElement<AllPassFilter>(490u, 0.6f);
	circuit.addElement<AllPassFilter>(163u, -0.6f);
    
    std::vector<float> taps({ 0.003369,0.002810,0.001758,0.000340,-0.001255,-0.002793,-0.004014,
    -0.004659,-0.004516,-0.003464,-0.001514,0.001148,0.004157,0.006986,0.009003,
    0.009571,0.008173,0.004560,-0.001120,-0.008222,-0.015581,-0.021579,-0.024323,
    -0.021933,-0.012904,0.003500,0.026890,0.055537,0.086377,0.115331,0.137960,
    0.150407,0.150407,0.137960,0.115331,0.086377,0.055537,0.026890,0.003500,
    -0.012904,-0.021933,-0.024323,-0.021579,-0.015581,-0.008222,-0.001120,
    0.004560,0.008173,0.009571,0.009003,0.006986,0.004157,0.001148,-0.001514,
    -0.003464,-0.004516,-0.004659,-0.004014,-0.002793,-0.001255,0.000340,
    0.001758,0.002810,0.003369 });

    circuit.addElement<FIRFilter>(taps);

    circuit.setDelay(17640);

    float x = 0.f;

    auto size = holder.getSamplesNumber();

    for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
    {
        if((100 * i) / size != (100 * (i-1)) / size)
            std::cout << (100 * i) / size << "%" << std::endl;
        float var = circuit.performCircuit(holder.at(i));
        holder.setAt(i, 0.6 * (var + 0.5 * circuit[5880] + 0.25 * circuit[11760] + 0.125 * circuit[17639]) + holder.at(i));
    }
}
