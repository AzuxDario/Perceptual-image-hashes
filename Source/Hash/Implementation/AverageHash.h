#ifndef PIH_AVERAGEHASH_H
#define PIH_AVERAGEHASH_H

#include <vector>
#include <numeric>

#include "../Interface/IHash.h"

namespace Pih
{
    class AverageHash : public IHash
    {
    public:
        AverageHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    private:
        unsigned char calculateAverageColor(const std::vector<unsigned char>& image);
    };
}


#endif