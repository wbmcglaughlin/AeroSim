//
// Created by wbmcg on 27/10/2022.
//

#ifndef AEROSIM_GEOMETRY_H
#define AEROSIM_GEOMETRY_H

#include "imgui.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Geometry {
public:
    float enclosure_x;
    float enclosure_y;
    float enclosure_w;
    float enclosure_h;
    float origin_x;
    float origin_y;

    void draw(sf::RenderWindow *window);

    Geometry(float e_x, float e_y, float e_w, float e_h) {
        enclosure_x = e_x;
        enclosure_y = e_y;
        enclosure_w = e_w;
        enclosure_h = e_h;
        origin_x = 0;
        origin_y = 0;
    }
};


#endif //AEROSIM_GEOMETRY_H
