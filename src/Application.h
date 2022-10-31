//
// Created by wbmcg on 31/10/2022.
//

#ifndef AEROSIM_APPLICATION_H
#define AEROSIM_APPLICATION_H

#include "geometry/Geometry.h"
#include "geometry/geometry_gui.h"
#include "menu.h"
#include "state.h"

class Application {
public:
    State state;

    Geometry geometry;

    Application();

    void loop();

    void draw(sf::RenderWindow *window);
};


#endif //AEROSIM_APPLICATION_H
