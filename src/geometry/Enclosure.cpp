//
// Created by wbmcg on 28/10/2022.
//

#include "Enclosure.h"

Enclosure::Enclosure(float pos_x, float neg_x, float pos_y, float neg_y){
    position = sf::Vector2(0.0f, 0.0f);

    // Adding dimensions to array
    dimensions[0] = pos_x;
    dimensions[1] = neg_x;
    dimensions[2] = pos_y;
    dimensions[3] = neg_y;

    // Adding vertices to array
    vertices[0] = sf::Vector2(position.x + dimensions[0], position.y + dimensions[2]); // ++
    vertices[1] = sf::Vector2(position.x - dimensions[1], position.y + dimensions[2]); // -+
    vertices[2] = sf::Vector2(position.x - dimensions[1], position.y - dimensions[3]); // --
    vertices[3] = sf::Vector2(position.x + dimensions[0], position.y - dimensions[3]); // +-

    // Adding lines to array
    lines[0] = sf::Vector2(0, 1);
    lines[1] = sf::Vector2(1, 2);
    lines[2] = sf::Vector2(2, 3);
    lines[3] = sf::Vector2(3, 0);

    // Update the shapes being drawn to the screen
    // TODO: drawn vertices and lines instead of shapes
    shape = sf::RectangleShape(sf::Vector2(pos_x + neg_x, pos_y + neg_y));
    shape.setOrigin((pos_x + neg_x) / 2.0f, (pos_y + neg_y) / 2.0f);
    shape.setPosition(position.x, position.y);
    shape.setOutlineThickness(1.0f);
    shape.setFillColor(sf::Color(20, 20, 20, 100));

    origin = sf::CircleShape();
    origin.setRadius(1.0f);
    origin.setOrigin(1.0f / 2, 1.0f / 2);
    origin.setFillColor(sf::Color::White);
}

void Enclosure::draw(sf::RenderWindow *window) {
    sf::View view{ window->getView() };
    view.setCenter(position.x, position.y);
    window->setView(view);

    window->draw(shape);
    window->draw(origin);
}

void Enclosure::UpdateShape() {
    UpdateVertices();

    shape.setSize(vertices[2] - vertices[0]); // subtract ++ corner and -- corner to get width and height
    shape.setOrigin(vertices[0] - position); // move origin to vertices
    shape.setPosition(position.x, position.y);
    shape.setOutlineThickness(1.0f);
    shape.setFillColor(sf::Color(20, 20, 20, 100));
}

void Enclosure::UpdateVertices() {
    // Adding vertices to array
    vertices[0] = sf::Vector2(position.x + dimensions[0], position.y + dimensions[2]); // ++
    vertices[1] = sf::Vector2(position.x - dimensions[1], position.y + dimensions[2]); // -+
    vertices[2] = sf::Vector2(position.x - dimensions[1], position.y - dimensions[3]); // --
    vertices[3] = sf::Vector2(position.x + dimensions[0], position.y - dimensions[3]); // +-
}
