//
// Created by wbmcg on 29/10/2022.
//

#include "add_shapes.h"

void add_rectangle(Geometry *geometry, float width, float height) {
    sf::Vector2<float> origin = geometry->geometry_origin;

    geometry->vertices.insert(geometry->vertices.end(), sf::Vector2<float>(origin.x - width / 2, origin.y - height / 2));
    geometry->vertices.insert(geometry->vertices.end(), sf::Vector2<float>(origin.x + width / 2, origin.y - height / 2));
    geometry->vertices.insert(geometry->vertices.end(), sf::Vector2<float>(origin.x + width / 2, origin.y + height / 2));
    geometry->vertices.insert(geometry->vertices.end(), sf::Vector2<float>(origin.x - width / 2, origin.y + height / 2));
}