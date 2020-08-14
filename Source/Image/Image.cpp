#include "Image.h"

namespace Pih
{
    unsigned int Image::getPosition(unsigned int x, unsigned int y, unsigned int size)
    {
        return y * size + x;
    }
    std::pair<unsigned int, unsigned int> Image::getPosition(unsigned int pos, unsigned int size)
    {
        return std::make_pair(size % pos, size / pos);
    }
}