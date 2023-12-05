//
// Created by 42077 on 12/5/2023.
//

#ifndef CMAKESFMLPROJECT_BIOMEHANDLER_H
#define CMAKESFMLPROJECT_BIOMEHANDLER_H


#include "SFML/Graphics/Color.hpp"
#include "enums.cpp"
class BiomeHandler {
public:
    static sf::Color ConvertToColor(float height, enums::Biome biome = enums::Biome::GRASSLAND)
    {
        return sf::Color(0,255-height,0);
    }
};


#endif //CMAKESFMLPROJECT_BIOMEHANDLER_H
