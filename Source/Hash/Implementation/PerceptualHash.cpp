#include "PerceptualHash.h"

namespace Pih
{
    std::vector<unsigned char> PerceptualHash::calculateHash(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> result;
        result.reserve(size * size);
        
        return result;
    }

    std::vector<unsigned char> PerceptualHash::resizeImage(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> newImage;
        unsigned int newImageSize = size * 4;
        unsigned int newImageSizeSquare = newImageSize * newImageSize;
        newImage.reserve(newImageSizeSquare);

        double factor = static_cast<double>(size - 1) / (newImage - 1); 
        for(unsigned int x = 0; x < newImageSizeSquare; ++x)
        {
            for(unsigned int y = 0; y < newImageSizeSquare; ++y)
            {
                // Get position in old image
                unsigned int oldX = x * factor;
                unsigned int oldY = y * factor;

                // Get position of surrounding points;
                std::pair<double, double> Q11 = std::make_pair(floor(oldX), floor(oldY));
                std::pair<double, double> Q12 = std::make_pair(ceil(oldX), floor(oldY));
                std::pair<double, double> Q21 = std::make_pair(floor(oldX), ceil(oldY));
                std::pair<double, double> Q22 = std::make_pair(ceil(oldX), ceil(oldY));

                // Interpolate new points
                unsigned char f1 = ((Q12.first - oldX) / (Q12.first - Q11.first)) * image.at(Image::getPosition(Q11.first, Q11.second)) +
                                   ((oldX - Q11.first) / (Q12.first - Q11.first)) * image.at(Image::getPosition(Q12.first, Q12.second));
                unsigned char f2 = ((Q22.first - oldX) / (Q22.first - Q21.first)) * image.at(Image::getPosition(Q21.first, Q21.second)) +
                                   ((oldX - Q21.first) / (Q22.first - Q21.first)) * image.at(Image::getPosition(Q22.first, Q22.second));
                
                unsigned char f3 = ((Q22.second - oldY) / (Q22.second - Q21.second)) * f1 +
                                   ((oldY - Q21.second) / (Q22.firsecondst - Q21.second)) * f2;
                
                newImage.at[Image::getPosition(x, y, newImageSize)] = f3;
            }
        }

        return newImage;
    }

    unsigned char PerceptualHash::calculateMedianColor(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> im = image;
        std::sort(im.begin(), im.end());
        unsigned int median = (static_cast<unsigned int>(im.at(size * size / 2 - 1)) + static_cast<unsigned int>(im.at(size * size / 2))) / 2;
        return median;
    }
}