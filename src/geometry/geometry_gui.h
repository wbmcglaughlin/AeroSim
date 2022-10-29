//
// Created by wbmcg on 28/10/2022.
//
#include <imgui-SFML.h>

#ifndef AEROSIM_GEOMETRY_GUI_H
#define AEROSIM_GEOMETRY_GUI_H

#include "imgui.h"
#include "Geometry.h"
#include "../state.h"
#include "add_shapes.h"

void ShowGeometryWindow(State *state, Geometry *geometry);

#endif //AEROSIM_GEOMETRY_GUI_H
