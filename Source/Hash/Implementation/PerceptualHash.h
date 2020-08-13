#ifndef PIH_PERCEPTURALHASH_H
#define PIH_PERCEPTURALHASH_H

#include <vector>
#include <numeric>

#include "../Interface/IHash.h"

namespace Pih
{
    class PercepturalHash : public IHash
    {
    public:
        PercepturalHash() {};
        std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& image) override;
    };
}


#endif