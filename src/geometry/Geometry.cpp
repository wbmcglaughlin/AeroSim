//
// Created by wbmcg on 27/10/2022.
//

#include "Geometry.h"

void Geometry::draw(sf::RenderWindow *window) {
    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2(enclosure_w, enclosure_h));
    rect.setPosition(enclosure_x, enclosure_y);

    window->draw(rect);
}
