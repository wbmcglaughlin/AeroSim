//
// Created by wbmcg on 28/10/2022.
//

#include "Enclosure.h"

Enclosure::Enclosure(EnclosureDimensions dimensions) : dimensions(dimensions) {
    position = sf::Vector2(0.0f, 0.0f);

    shape = sf::RectangleShape(sf::Vector2(dimensions.pos_x + dimensions.neg_x, dimensions.pos_y + dimensions.neg_y));
    shape.setOrigin((dimensions.pos_x + dimensions.neg_x) / 2.0f, (dimensions.pos_y + dimensions.neg_y) / 2.0f);
    shape.setPosition(position.x, position.y);
    shape.setOutlineThickness(1.0f);
    shape.setFillColor(sf::Color(20, 20, 20, 100));


}

void Enclosure::draw(sf::RenderWindow *window) {
    sf::View view{ window->getView() };
    view.setCenter(position.x, position.y);
    window->setView(view);

    window->draw(shape);
}
