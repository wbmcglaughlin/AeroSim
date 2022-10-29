//
// Created by wbmcg on 27/10/2022.
//

#include "Geometry.h"

void Geometry::draw(sf::RenderWindow *window) {
    enclosure.draw(window);

    unsigned int vecSize = vertices.size();

    if (vecSize > 0) {
        // run for loop from 0 to vecSize
        for (unsigned int i = 0; i < vecSize - 1; i++) {
            sf::Vertex line[] =
                    {
                            sf::Vertex(vertices[i]),
                            sf::Vertex(vertices[i + 1])
                    };

            window->draw(line, 2, sf::Lines);
        }

        sf::Vertex line[] =
                {
                        sf::Vertex(vertices[vecSize - 1]),
                        sf::Vertex(vertices[0])
                };

        window->draw(line, 2, sf::Lines);
    }
}

Geometry::Geometry() = default;
