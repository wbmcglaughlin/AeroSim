//
// Created by wbmcg on 28/10/2022.
//

#ifndef AEROSIM_ENCLOSUREDIMENSIONS_H
#define AEROSIM_ENCLOSUREDIMENSIONS_H

#include "SFML/Graphics.hpp"

class EnclosureDimensions {
public:
    float pos_x{};
    float neg_x{};
    float pos_y{};
    float neg_y{};

    EnclosureDimensions(float p_x, float n_x, float p_y, float n_y);
};


#endif //AEROSIM_ENCLOSUREDIMENSIONS_H
