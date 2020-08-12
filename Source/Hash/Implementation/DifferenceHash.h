#ifndef PIH_DIFFERENCEHASH_H
#define PIH_DIFFERENCEHASH_H

#include <vector>
#include <numeric>

#include "../Interface/IHash.h"

namespace Pih
{
    class DifferenceHash : public IHash
    {
    public:
        DifferenceHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    };
}


#endif