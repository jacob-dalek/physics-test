#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Ball.h"

constexpr int width{ 800 };
constexpr int height{ 800 };

int main()
{
    sf::Texture texture("resources/vertex-array-tilemap-tileset.png");
    sf::RectangleShape square{ {80.f, 80.f} };
    sf::Sprite sprite1(texture);

    sf::RenderWindow window(sf::VideoMode({ width, height }), "SFML works!");
    ImGui::SFML::Init(window);




    window.setFramerateLimit(60);
    Ball ball{ 400.0f, 400.0f, 100.0f };

    sf::Color green = sf::Color::Green;

    sf::Clock clock;
	float delta_time = 0.0f;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

        }


        window.clear();

        ball.render(window, green);
        ball.update(delta_time);


        window.display();

    }
    ImGui::SFML::Shutdown();
    return 0;
};