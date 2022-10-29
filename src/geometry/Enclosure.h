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
    sf::CircleShape origin;

    explicit Enclosure(EnclosureDimensions dimensions);

    void draw(sf::RenderWindow *window);
    void UpdateShape();
};

#endif //AEROSIM_ENCLOSURE_H
