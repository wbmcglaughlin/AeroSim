//
// Created by wbmcg on 28/10/2022.
//

#include "geometry_gui.h"

void ShowGeometryWindow(State *state, Geometry *geometry) {
    if (!ImGui::Begin("Geometry"))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    if (ImGui::Button("Export To Meshing")) {

    }

    if (ImGui::Button("Menu")) {
        *state = menu;
    }

    ImGui::End();
}
