#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>

constexpr int width{ 800 };
constexpr int height{ 800 };

int main()
{
    sf::RenderWindow window(sf::VideoMode({width, height}), "SFML works!");
    ImGui::SFML::Init(window);
    bool circle_exists = true;
    float circle_radius = 100.f;
    sf::CircleShape shape(circle_radius);
    shape.setFillColor(sf::Color::Red);

    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            ImGui::SFML::ProcessEvent(window, *event);
        }
        ImGui::SFML::Update(window, clock.restart());

        ImGui::Begin("Game Engine");
        ImGui::Checkbox("Circle", &circle_exists);
        ImGui::SliderFloat("Radius", &circle_radius, 50.f, 300.f);


        ImGui::End();

        window.clear();
        if (circle_exists)
            window.draw(shape);
            shape.setRadius(circle_radius);
            

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}