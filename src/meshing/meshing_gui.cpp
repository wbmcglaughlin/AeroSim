//
// Created by wbmcg on 31/10/2022.
//

#include "meshing_gui.h"

void ShowMeshingWindow(State *state, Meshing *meshing) {
    if (!ImGui::Begin("Meshing"))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    ImGui::End();
}