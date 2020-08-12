#include "AverageHash.h"

namespace Pih
{
    std::vector<unsigned char> AverageHash::calculateHash(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> result;
        result.reserve(size * size);
        unsigned char averageColor = calculateAverageColor(image);

        for(auto pixel : image)
        {
            pixel > averageColor ? result.push_back(1) : result.push_back(0);
        }
        return result;
    }

    unsigned char AverageHash::calculateAverageColor(const std::vector<unsigned char>& image)
    {
        unsigned int sumOfColors = std::accumulate(image.begin(), image.end(), 0);

        return static_cast<unsigned char>(sumOfColors / size * size);
    }
}