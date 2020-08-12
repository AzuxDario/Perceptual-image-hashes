#ifndef PIH_IHASH_H
#define PIH_IHASH_H

#include <vector>

namespace Pih
{
    class IHash
    {
    protected:
        unsigned int size = 8;
    public:
        IHash() {};
        virtual std::vector<unsigned char>  calculateHash(const std::vector<unsigned char>& image) = 0;
    };
}


#endif