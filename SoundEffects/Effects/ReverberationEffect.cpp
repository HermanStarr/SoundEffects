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
    
    std::vector<double> taps({ 0.003369,0.002810,0.001758,0.000340,-0.001255,-0.002793,-0.004014,
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
    switch (static_cast<CompressionCodes>(holder.getCompressionCode()))
    {
    case CompressionCodes::UNKNOWN:
        break;
    case CompressionCodes::WAVE_FORMAT_PCM:
        switch (static_cast<IntegerTypes>(holder.getBitsPerSample()))
        {
        case IntegerTypes::UINT8:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                float var = static_cast<float>(circuit.performCircuit(holder.at(i)));
                holder.setAt(i, static_cast<uint8_t>(0.6f * (var + 0.5f * circuit[5880] + 0.25f * circuit[11760] + 0.125f * circuit[17639]) + holder.at(i)));
            }
            break;
        case IntegerTypes::INT16:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                float var = static_cast<float>(circuit.performCircuit(holder.atInt16_t(i)));
                holder.setAt(i, static_cast<int16_t>(0.6f * (var + 0.5f * circuit[5880] + 0.25f * circuit[11760] + 0.125f * circuit[17639]) + holder.at(i)));
            }
            break;
        case IntegerTypes::INT24:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                float var = static_cast<float>(circuit.performCircuit(static_cast<int32_t>(holder.atInt24_t(i))));
                holder.setAt(i, static_cast<int24_t>(0.6f * (var + 0.5f * circuit[5880] + 0.25f * circuit[11760] + 0.125f * circuit[17639]) + holder.at(i)));
            }
            break;
        case IntegerTypes::INT32:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                float var = static_cast<float>(circuit.performCircuit(holder.atInt32_t(i)));
                holder.setAt(i, static_cast<int32_t>(0.6f * (var + 0.5f * circuit[5880] + 0.25f * circuit[11760] + 0.125f * circuit[17639]) + holder.at(i)));
            }
            break;
        default:
            break;
        }
        break;
    case CompressionCodes::MICROSOFT_ADPCM:
        break;
    case CompressionCodes::WAVE_FORMAT_IEEE_FLOAT:
        switch (static_cast<FloatTypes>(holder.getBitsPerSample()))
        {
        case FloatTypes::FLOAT32:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                float var = circuit.performCircuit(holder.atFloat(i));
                holder.setAt(i, static_cast<float>(0.6f * (var + 0.5f * circuit[5880] + 0.25f * circuit[11760] + 0.125f * circuit[17639]) + holder.at(i)));
            }
            break;
        case FloatTypes::FLOAT64:
            for (uint32_t i = 0; i < holder.getSamplesNumber(); i++)
            {
                double var = circuit.performCircuit(holder.atDouble(i));
                holder.setAt(i, 0.6 * (var + 0.5 * circuit[5880] + 0.25 * circuit[11760] + 0.125 * circuit[17639]) + holder.at(i));
            }
            break;
        default:
            break;
        }
        break;
    case CompressionCodes::WAVE_FORMAT_ALAW:
        break;
    case CompressionCodes::WAVE_FORMAT_MULAW:
        break;
    case CompressionCodes::IMA_ADPCM:
        break;
    case CompressionCodes::ITU_G_723_ADPCM:
        break;
    case CompressionCodes::GSM_6_10:
        break;
    case CompressionCodes::ITU_G_721_ADPCM:
        break;
    case CompressionCodes::MPEG:
        break;
    case CompressionCodes::EXPERIMENTAL:
        break;
    default:
        break;
    }
}
