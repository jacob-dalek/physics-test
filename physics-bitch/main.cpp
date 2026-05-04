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

    
    float offset_x = (width / 2);
    float offset_y = (height / 2);

    

    shape.setFillColor(sf::Color::Red);
    sf::Clock clock;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            ImGui::SFML::ProcessEvent(window, *event);
        }

        float circle_x = shape.getPosition().x;
        float circle_y = shape.getPosition().y;

        float xspeed = 1;
        float yspeed = .5f;

        ImGui::SFML::Update(window, clock.restart());
        ImGui::Begin("Game Engine");
        ImGui::Checkbox("Circle", &circle_exists);
        ImGui::SliderFloat("Radius", &circle_radius, 50.f, 300.f);
        ImGui::SliderFloat("X axis", &circle_x, -offset_x, offset_x);
        ImGui::SliderFloat("Y axis", &circle_y, -offset_y, offset_y);
        ImGui::End();

        shape.setPosition({ circle_x + xspeed, circle_y + yspeed});


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