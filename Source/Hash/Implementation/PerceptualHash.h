#ifndef PIH_PERCEPTURALHASH_H
#define PIH_PERCEPTURALHASH_H

#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

#include "../Interface/IHash.h"
#include "../../Image/Image.h"

namespace Pih
{
    class PerceptualHash : public IHash
    {
    public:
        PerceptualHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    private:
        std::vector<unsigned char> resizeImage(const std::vector<unsigned char>& image);
        unsigned char calculateMedianColor(const std::vector<unsigned char>& image);
    };
}


#endif