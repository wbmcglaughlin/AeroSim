//
// Created by wbmcg on 31/10/2022.
//

#include "Application.h"

Application::Application() {
    // Initialise application to the menu
    state = MENU;

    geometry = Geometry();
}

void Application::loop() {
    switch (state) {
        case MENU : ShowMenuWindow(&state); break;
        case GEOMETRY : ShowGeometryWindow(&state, &geometry); break;
        case MESHING:
            break;
        case DEMO :
            ImGui::ShowDemoWindow();
            break;
    }
}

void Application::draw(sf::RenderWindow *window) {
    switch(state) {
        case GEOMETRY:
            geometry.draw(window);
            break;
    }
}
