#ifndef COLORS_H
#define COLORS_H

#include <SFML/Graphics.hpp>

namespace FireColor
{
    inline std::vector<sf::Color> palette = {
        sf::Color(0x070707FF),    // black
        sf::Color(0x1F0707FF),
        sf::Color(0x2F0F07FF),
        sf::Color(0x470F07FF),
        sf::Color(0x571707FF),
        sf::Color(0x671F07FF),
        sf::Color(0x771F07FF),
        sf::Color(0x8F2707FF),
        sf::Color(0x9F2F07FF),
        sf::Color(0xAF3F07FF),
        sf::Color(0xBF4707FF),
        sf::Color(0xC74707FF),
        sf::Color(0xDF4F07FF),
        sf::Color(0xDF5707FF),
        sf::Color(0xDF5707FF),
        sf::Color(0xD75F07FF),
        sf::Color(0xD7670FFF),
        sf::Color(0xCF6F0FFF),
        sf::Color(0xCF770FFF),
        sf::Color(0xCF7F0FFF),
        sf::Color(0xCF8717FF),
        sf::Color(0xC78717FF),
        sf::Color(0xC78F17FF),
        sf::Color(0xC7971FFF),
        sf::Color(0xBF9F1FFF),
        sf::Color(0xBF9F1FFF),
        sf::Color(0xBFA727FF),
        sf::Color(0xBFA727FF),
        sf::Color(0xBFAF2FFF),
        sf::Color(0xB7AF2FFF),
        sf::Color(0xB7B72FFF),
        sf::Color(0xB7B737FF),
        sf::Color(0xCFCF6FFF),
        sf::Color(0xDFDF9FFF),
        sf::Color(0xEFEFC7FF),
        sf::Color(0xFFFFFFFF)     // white
    };

    inline int getColorIndex(sf::Color original)
    {
        int index = 0;
        for(const sf::Color& c : palette){
            if(original == c){
                return index;
            }
            index++;
        }

        return 0;
    }
}


#endif
