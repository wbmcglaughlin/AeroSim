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

    if (ImGui::CollapsingHeader("Enclosure Settings")) {
        if (ImGui::InputFloat("+x [mm]", &geometry->enclosure.dimensions.pos_x, 1.0f, 10.0f, "%.3f")) {
            geometry->enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("-x [mm]", &geometry->enclosure.dimensions.neg_x, 1.0f, 10.0f, "%.3f")) {
            geometry->enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("+y [mm]", &geometry->enclosure.dimensions.pos_y, 1.0f, 10.0f, "%.3f")) {
            geometry->enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("-y [mm]", &geometry->enclosure.dimensions.neg_y, 1.0f, 10.0f, "%.3f")) {
            geometry->enclosure.UpdateShape();
        }
    }

    if (ImGui::CollapsingHeader("Geometry Settings")) {
        if (ImGui::InputFloat("length [mm]", &x_point, 1.0f, 10.0f, "%.3f")) {
        }
        if (ImGui::InputFloat("height [mm]", &y_point, 1.0f, 10.0f, "%.3f")) {
        }

        if (ImGui::Button("Add Rectangle")) {
            add_rectangle(geometry, x_point, y_point);
        }
    }

    if (ImGui::Button("Export To Meshing")) {

    }

    if (ImGui::Button("Menu")) {
        *state = menu;
    }

    ImGui::End();
}
