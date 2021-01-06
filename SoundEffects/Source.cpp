#include "DSP.h"
#include "SoundGenerator/SoundGenerator.h"

/// <summary>
/// Main function of a program
/// </summary>
/// <param name="argc">Number of arguments</param>
/// <param name="argv">
/// Arguments:
/// argv[0] - file path to a new file, extension of either raw or wav needs to be added
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
            {
                SoundGenerator soundGenerator = SoundGenerator();

                //Add d1
                RAWHolder* newRawHolder = soundGenerator.generateTone(20.f, 293.66f, 44100, 1);
                WAVHolder generatedSound = WAVHolder(*newRawHolder);
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_d1" + path.substr(path.find_last_of(".")));
                delete newRawHolder;

                //Add fis1
                newRawHolder = soundGenerator.generateTone(20.f, 369.99, 44100, 1);
                mergeTwoSounds(generatedSound, *newRawHolder, 0);
                {
                    WAVHolder wvhldr = WAVHolder(*newRawHolder);
                    wvhldr.writeToFile(path.substr(0, path.find_last_of(".")) + "_f#1" + path.substr(path.find_last_of(".")));
                }
                delete newRawHolder;

                //Add a1
                newRawHolder = soundGenerator.generateTone(20.f, 440, 44100, 1);
                mergeTwoSounds(generatedSound, *newRawHolder, 0);
                {
                    WAVHolder wvhldr = WAVHolder(*newRawHolder);
                    wvhldr.writeToFile(path.substr(0, path.find_last_of(".")) + "_a1" + path.substr(path.find_last_of(".")));
                }
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_accord" + path.substr(path.find_last_of(".")));
                delete newRawHolder;

                //Add envelope
                soundGenerator.addEnvelope(generatedSound);
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_enveloped" + path.substr(path.find_last_of(".")));
            }
        }
        break;
        case 1:
        {

            {
                SoundGenerator soundGenerator = SoundGenerator();

                //Add d1
                RAWHolder* newRawHolder = soundGenerator.generateTone(20.f, 293.66f, 44100, 1);
                RAWHolder generatedSound = RAWHolder(*newRawHolder);
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_d1" + path.substr(path.find_last_of(".")));
                delete newRawHolder;

                //Add fis1
                newRawHolder = soundGenerator.generateTone(20.f, 369.99, 44100, 1);
                mergeTwoSounds(generatedSound, *newRawHolder, 0);
                {
                    RAWHolder rwhldr = RAWHolder(*newRawHolder);
                    rwhldr.writeToFile(path.substr(0, path.find_last_of(".")) + "_f#1" + path.substr(path.find_last_of(".")));
                }
                delete newRawHolder;

                //Add a1
                newRawHolder = soundGenerator.generateTone(20.f, 440, 44100, 1);
                mergeTwoSounds(generatedSound, *newRawHolder, 0);
                {
                    RAWHolder rwhldr = RAWHolder(*newRawHolder);
                    rwhldr.writeToFile(path.substr(0, path.find_last_of(".")) + "_a1" + path.substr(path.find_last_of(".")));
                }
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_accord" + path.substr(path.find_last_of(".")));
                delete newRawHolder;

                //Add envelope
                soundGenerator.addEnvelope(generatedSound);
                generatedSound.writeToFile(path.substr(0, path.find_last_of(".")) + "_enveloped" + path.substr(path.find_last_of(".")));
            }
        }
        break;
        default:
            return -1;
            break;
        }
    }
    else
    {
        std::cout << "No file path given" << std::endl;
        return 1;
    }
    return 0;
}