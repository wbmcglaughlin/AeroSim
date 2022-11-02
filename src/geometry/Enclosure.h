//
// Created by wbmcg on 28/10/2022.
//

#ifndef AEROSIM_ENCLOSURE_H
#define AEROSIM_ENCLOSURE_H

#include "SFML/Graphics.hpp"


class Enclosure {
public:
    sf::Vector2<float> position;
    float dimensions[4];
    sf::Vector2<float> vertices[4];
    sf::Vector2<int> lines[4];

    sf::RectangleShape shape;
    sf::CircleShape origin;

    Enclosure(float pos_x, float neg_x, float pos_y, float neg_y);

    void draw(sf::RenderWindow *window);
    void UpdateShape();
private:
    void UpdateVertices();
};

#endif //AEROSIM_ENCLOSURE_H
