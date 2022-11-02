//
// Created by wbmcg on 27/10/2022.
//

#ifndef AEROSIM_GEOMETRY_H
#define AEROSIM_GEOMETRY_H

#include "imgui.h"
#include "SFML/Graphics.hpp"
#include "Enclosure.h"

class Geometry {
public:
    sf::Vector2<float> geometry_origin{};
    Enclosure enclosure{100.0f, 100.0f, 100.0f, 100.0f};

    std::vector<sf::Vector2<float>> vertices;

    void draw(sf::RenderWindow *window);

    Geometry();
private:
};

#endif //AEROSIM_GEOMETRY_H
