#include "DSP.h"
#include "SoundGenerator/SoundGenerator.h"

///	<summary>
/// Function checks an extension of a file
/// </summary>
/// <param name="path">Path to the given file</param>
/// <returns>Flag corresponding to the extension found</returns>
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

int main(int argc, char** argv)
{
    return 0;
}