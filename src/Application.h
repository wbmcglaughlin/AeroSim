//
// Created by wbmcg on 31/10/2022.
//

#ifndef AEROSIM_APPLICATION_H
#define AEROSIM_APPLICATION_H

#include "geometry/Geometry.h"
#include "geometry/add_shapes.h"

#include "meshing/Meshing.h"

#include "state.h"

static float x_point = 50.0f;
static float y_point = 50.0f;

class Application {
public:
    State state;
    Geometry geometry;
    Meshing meshing;

    Application();

    void loop();
    void draw(sf::RenderWindow *window);

private:
    void ShowMenuWindow();
    void ShowGeometryWindow();
    void ShowMeshingWindow();
};


#endif //AEROSIM_APPLICATION_H
