#include "PerceptualHash.h"

namespace Pih
{
    std::vector<unsigned char> PerceptualHash::calculateHash(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> result;
        result.reserve(size * size);
        
        return result;
    }

    unsigned char PerceptualHash::calculateMedianColor(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> im = image;
        std::sort(im.begin(), im.end());
        unsigned int median = (static_cast<unsigned int>(im.at(size * size / 2 - 1)) + static_cast<unsigned int>(im.at(size * size / 2))) / 2;
        return median;
    }
}