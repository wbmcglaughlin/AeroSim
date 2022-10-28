#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include "menu.h"
#include "geometry/Geometry.h"
#include "state.h"

int main() {
    bool show_demo = true;

    State state = menu;
    Geometry geom = Geometry(100, 100, 100, 100);

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Aero Sim");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        switch (state) {
            case menu : ShowMenuWindow(&state); break;
            case geometry : ShowGeometryWindow(&state); break;
            case demo :
                ImGui::ShowDemoWindow();
                break;
        }

        window.clear();

        geom.draw(&window);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}

