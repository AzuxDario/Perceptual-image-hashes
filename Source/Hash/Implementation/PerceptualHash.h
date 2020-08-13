#ifndef PIH_PERCEPTURALHASH_H
#define PIH_PERCEPTURALHASH_H

#include <vector>
#include <numeric>
#include <algorithm>

#include "../Interface/IHash.h"

namespace Pih
{
    class PerceptualHash : public IHash
    {
    public:
        PerceptualHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    private:
        unsigned char calculateMedianColor(const std::vector<unsigned char>& image);
    };
}


#endif