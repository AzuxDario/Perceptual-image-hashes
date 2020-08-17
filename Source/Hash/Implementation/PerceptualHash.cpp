#include "PerceptualHash.h"

namespace Pih
{
    std::vector<unsigned char> PerceptualHash::calculateHash(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> resized = resizeImage(image);
        std::vector<unsigned char> transformed = calculateDCT(resized);
        std::vector<unsigned char> topPixels = extractTopPixels(transformed);        

        std::vector<unsigned char> result;
        result.reserve(size * size);
        unsigned char medianColor = calculateMedianColor(topPixels);

        for(auto pixel : topPixels)
        {
            pixel > medianColor ? result.push_back(1) : result.push_back(0);
        }
        return result;
    }

    std::vector<unsigned char> PerceptualHash::resizeImage(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> newImage;
        newImage.reserve(newImageSize * newImageSize);

        double factor = static_cast<double>(size - 1) / (newImageSize - 1); 
        for(unsigned int x = 0; x < newImageSize; ++x)
        {
            for(unsigned int y = 0; y < newImageSize; ++y)
            {
                // Get position in old image
                unsigned int oldX = x * factor;
                unsigned int oldY = y * factor;

                // Get position of surrounding points
                std::pair<double, double> Q11 = std::make_pair(floor(oldX), floor(oldY));
                std::pair<double, double> Q12 = std::make_pair(ceil(oldX), floor(oldY));
                std::pair<double, double> Q21 = std::make_pair(floor(oldX), ceil(oldY));
                std::pair<double, double> Q22 = std::make_pair(ceil(oldX), ceil(oldY));

                // Interpolate new points
                unsigned char f1 = ((Q12.first - oldX) / (Q12.first - Q11.first)) * image.at(Image::getPosition(Q11.first, Q11.second, size)) +
                                   ((oldX - Q11.first) / (Q12.first - Q11.first)) * image.at(Image::getPosition(Q12.first, Q12.second, size));
                unsigned char f2 = ((Q22.first - oldX) / (Q22.first - Q21.first)) * image.at(Image::getPosition(Q21.first, Q21.second, size)) +
                                   ((oldX - Q21.first) / (Q22.first - Q21.first)) * image.at(Image::getPosition(Q22.first, Q22.second, size));
                
                unsigned char f3 = ((Q22.second - oldY) / (Q22.second - Q21.second)) * f1 +
                                   ((oldY - Q21.second) / (Q22.second - Q21.second)) * f2;
                
                newImage.at(Image::getPosition(x, y, newImageSize)) = f3;
            }
        }

        return newImage;
    }

    std::vector<unsigned char> PerceptualHash::calculateDCT(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> transformed;
        transformed.reserve(newImageSize * newImageSize);
        // Horizontal lines
        for(unsigned int i = 0; i < newImageSize; ++i)
        {
            auto newLine = std::vector<unsigned char>(image.begin() + i * newImageSize, image.begin() + (i + 1) * newImageSize);
            transformed.insert(transformed.end(), newLine.begin(), newLine.end());
        }
        // Vertical lines
        std::vector<unsigned char> toTransform;
        for(unsigned int i = 0; i < newImageSize; ++i)
        {
            for(unsigned int j = 0; j < newImageSize; ++j)
            {
                toTransform.push_back(transformed.at(j * newImageSize + i));
            }

            auto newColumn = calculateDCTLine(toTransform);

            for(unsigned int j = 0; j < newImageSize; ++j)
            {
                transformed.at(j * newImageSize + i) = newColumn.at(j);
            }
        }

        return transformed;
    }

    std::vector<unsigned char> PerceptualHash::calculateDCTLine(const std::vector<unsigned char>& line)
    {
        std::vector<unsigned char> transformed;
        transformed.reserve(newImageSize);
        double factor = Pi / newImageSize;

        for(unsigned int i = 0; i < newImageSize; ++i)
        {
            double sum = 0;
            for(unsigned int j = 0; j < newImageSize; ++j)
            {
                sum += line.at(j) * std::cos((j + 0.5) * i * factor);
            }
            transformed.push_back(static_cast<unsigned char>(sum));
        }

        return transformed;
    }

    std::vector<unsigned char> PerceptualHash::extractTopPixels(const std::vector<unsigned char>& image)
    {
        std::vector<unsigned char> newImage;
        newImage.reserve(size * size);
        for(unsigned int i = 0; i < size; ++i)
        {
            for(unsigned int j = 0; j < size; ++j)
            {
                newImage.push_back(image.at(Image::getPosition(i, j, size)));
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