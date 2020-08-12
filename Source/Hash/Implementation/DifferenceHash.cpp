#include "DifferenceHash.h"

namespace Pih
{
    std::vector<unsigned char> DifferenceHash::calculateHash(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> result;
        result.reserve(size * size);
        for(unsigned int i = 0; i < size; ++i)
        {
            for(unsigned int j = 0; j < size; ++j)
            {
                if(j < size - 1)
                {
                    image[i * size + j] > image[i * size + j + 1] ? result.push_back(1) : result.push_back(0);
                }
                else
                {
                    image[i * size + j] > image[i * size] ? result.push_back(1) : result.push_back(0);
                }
                
            }
        }
        
        return result;
    }
}