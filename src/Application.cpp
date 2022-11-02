//
// Created by wbmcg on 31/10/2022.
//

#include "Application.h"

Application::Application() {
    // Initialise application to the menu
    state = MENU;

    geometry = Geometry();
    meshing = Meshing();
}

void Application::loop() {
    switch (state) {
        case MENU :
            ShowMenuWindow();
            break;
        case GEOMETRY :
            ShowGeometryWindow();
            break;
        case MESHING:
            ShowMeshingWindow();
            break;
        case DEMO :
            ImGui::ShowDemoWindow();
            break;
        case SETUP:
            break;
        case SOLVER:
            break;
    }
}

void Application::draw(sf::RenderWindow *window) {
    switch(state) {
        case GEOMETRY:
            geometry.draw(window);
            break;
        case MENU:
            break;
        case MESHING:
            break;
        case SETUP:
            break;
        case SOLVER:
            break;
        case DEMO:
            break;
    }
}

void Application::ShowGeometryWindow() {
    if (!ImGui::Begin("Geometry"))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    if (ImGui::CollapsingHeader("Enclosure Settings")) {
        if (ImGui::InputFloat("+x [mm]", &geometry.enclosure.dimensions[0], 1.0f, 10.0f, "%.3f")) {
            geometry.enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("-x [mm]", &geometry.enclosure.dimensions[1], 1.0f, 10.0f, "%.3f")) {
            geometry.enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("+y [mm]", &geometry.enclosure.dimensions[2], 1.0f, 10.0f, "%.3f")) {
            geometry.enclosure.UpdateShape();
        }
        if (ImGui::InputFloat("-y [mm]", &geometry.enclosure.dimensions[3], 1.0f, 10.0f, "%.3f")) {
            geometry.enclosure.UpdateShape();
        }
    }

    if (ImGui::CollapsingHeader("Geometry Settings")) {
        if (ImGui::InputFloat("length [mm]", &x_point, 1.0f, 10.0f, "%.3f")) {
        }
        if (ImGui::InputFloat("height [mm]", &y_point, 1.0f, 10.0f, "%.3f")) {
        }

        if (ImGui::Button("Add Rectangle")) {
            add_rectangle(&geometry, x_point, y_point);
        }
    }

    if (ImGui::Button("Export To Meshing")) {
        state = MESHING;
    }

    if (ImGui::Button("Menu")) {
        state = MENU;
    }

    ImGui::End();
}

void Application::ShowMeshingWindow() {
    if (!ImGui::Begin("Meshing"))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    if (ImGui::Button("Menu")) {
        state = MENU;
    }

    ImGui::End();
}

void Application::ShowMenuWindow() {
    // Demonstrate the various window flags. Typically you would just use the default!
    static bool no_titlebar = false;
    static bool no_scrollbar = false;
    static bool no_menu = false;
    static bool no_move = false;
    static bool no_resize = false;
    static bool no_collapse = false;
    static bool no_close = false;
    static bool no_nav = false;
    static bool no_background = false;
    static bool no_bring_to_front = false;

    ImGuiWindowFlags window_flags = 0;
    if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
    if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
    if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
    if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
    if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
    if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
    if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
    if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
    if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
//    if (no_close)           p_open = NULL; // Don't pass our bool* to Begin

    // Main body of the Demo window starts here.
    if (!ImGui::Begin("Aero Sim", nullptr, window_flags))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    ImVec2 button_width = ImVec2(ImGui::GetWindowSize().x * 1.0f, 0.0f);

    if (ImGui::Button("Geometry", button_width)) {
        state = GEOMETRY;
    }

    if (ImGui::Button("Meshing", button_width)) {
        state = MESHING;
    }

    if (ImGui::Button("Setup", button_width)) {

    }

    if (ImGui::Button("Solver", button_width)) {

    }

    if (ImGui::Button("Demo", button_width)) {
        state = DEMO;
    }

    ImGui::End();
}

//void Application::ExportGeometryToMeshing() {
//    sf::Vector2<float> enclosureDimensions[4] = {
//            sf::Vector2(geometry.enclosure.position)
//    }
//}
