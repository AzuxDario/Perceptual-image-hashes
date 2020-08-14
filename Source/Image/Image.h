#ifndef PIH_IMAGE_H
#define PIH_IMAGE_H

#include <vector>
#include <utility>

namespace Pih
{
    class Image
    {
    public:
        Image() {};
        static unsigned int getPosition(unsigned int x, unsigned int y, unsigned int size);
        static std::pair<unsigned int, unsigned int> getPosition(unsigned int pos, unsigned int size);
    };
}


#endif