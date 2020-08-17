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
    protected:
        const double Pi =  3.1415926535;
        unsigned int newImageSize = size * 4;
    public:
        PerceptualHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    private:
        std::vector<unsigned char> resizeImage(const std::vector<unsigned char>& image);
        std::vector<unsigned char> calculateDCT(const std::vector<unsigned char>& image);
        std::vector<unsigned char> calculateDCTLine(const std::vector<unsigned char>& line);
        unsigned char calculateMedianColor(const std::vector<unsigned char>& image);
    };
}


#endif