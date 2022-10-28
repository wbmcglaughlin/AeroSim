//
// Created by wbmcg on 28/10/2022.
//

#ifndef AEROSIM_ENCLOSURE_H
#define AEROSIM_ENCLOSURE_H

#include "SFML/Graphics.hpp"
#include "EnclosureDimensions.h"


class Enclosure {
public:
    sf::Vector2<float> position;
    EnclosureDimensions dimensions;
    sf::RectangleShape shape;

    explicit Enclosure(EnclosureDimensions dimensions);

    void draw(sf::RenderWindow *window);
};

#endif //AEROSIM_ENCLOSURE_H
