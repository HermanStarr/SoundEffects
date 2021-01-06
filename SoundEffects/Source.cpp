#include "DSP.h"

/// <summary>
/// Main function of a program
/// </summary>
/// <param name="argc">Number of arguments</param>
/// <param name="argv">
/// Arguments:
///     argv[1] isRAW ? path to the file                :   path to the file
///     argv[2] isRAW ? NumChannels                     :   exists ? delay : 1 second 
///     argv[3] isRAW ? SampleRate                      :   exists ? infiniteModifier : 0.4
///     argv[4] isRAW ? exists ? delay : 1 second       :   ------
///     argv[5] isRAW ? exists ? infiniteModifier : 0.4 :   ------
/// </param>
/// <returns>On exit</returns>
int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::string path = argv[1];
        switch (checkExtension(path))
        {
        case 0:
        {
            WAVHolder wavHolder(path);
            float delay = argc > 2 ? atof(argv[2]) : 1.f;
            float infiniteModifier = argc > 3 ? atof(argv[3]) : 0.4f;
            {
                WAVHolder wavHolderCopy(wavHolder, wavHolder.getDelay(delay));
                makeEcho(wavHolderCopy, wavHolder, delay);
                wavHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_Echo" + path.substr(path.find_last_of(".")));
            }
            {
                WAVHolder wavHolderCopy(wavHolder, wavHolder.getDelay(delay) * 3);
                makeTripleEcho(wavHolderCopy, wavHolder, delay);
                wavHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_TripleEcho" + path.substr(path.find_last_of(".")));
            }
            {
                WAVHolder wavHolderCopy(wavHolder, wavHolder.getDelay(delay) * wavHolder.getDuration());
                makeInfiniteEcho(wavHolderCopy, wavHolder, delay * infiniteModifier, 1.f);
                wavHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_InfiniteEcho" + path.substr(path.find_last_of(".")));
            }
        }
        break;
        case 1:
        {
            if (argc > 3)
            {
                RAWHolder rawHolder(path, atoi(argv[2]), atoi(argv[3]));
                float delay = argc > 4 ? atof(argv[4]) : 1.f;
                float infiniteModifier = argc > 5 ? atof(argv[5]) : 0.4f;
                {
                    RAWHolder rawHolderCopy(rawHolder, rawHolder.getDelay(delay));
                    makeEcho(rawHolderCopy, rawHolder, delay);
                    rawHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_Echo" + path.substr(path.find_last_of(".")));
                }
                {
                    RAWHolder rawHolderCopy(rawHolder, rawHolder.getDelay(delay) * 3);
                    makeTripleEcho(rawHolderCopy, rawHolder, delay);
                    rawHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_TripleEcho" + path.substr(path.find_last_of(".")));
                }
                {
                    RAWHolder rawHolderCopy(rawHolder, rawHolder.getDelay(delay) * rawHolder.getDuration());
                    makeInfiniteEcho(rawHolderCopy, rawHolder, delay * infiniteModifier, 1.f);
                    rawHolderCopy.writeToFile(path.substr(0, path.find_last_of(".")) + "_InfiniteEcho" + path.substr(path.find_last_of(".")));
                }
            }
            else
                return -1;
        }
        break;
        default:
            return -1;
            break;
        }
    }
    return 0;
}