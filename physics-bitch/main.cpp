#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Ball.h"
#include "Racket.h"

constexpr int width{ 800 };
constexpr int height{ 800 };

int main()
{

    Racket racket{ 100.0f, 10.0f };
    sf::RenderWindow window(sf::VideoMode({ width, height }), "SFML works!");
    ImGui::SFML::Init(window);

    window.setFramerateLimit(60);
    Ball ball{ 400.0f, 352.0f, 100.0f };
    Ball ball2{ 500.0f, 100.0f, 200.0f };



    sf::Clock clock;
	float delta_time = 0.0f;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            racket.update(delta_time);

        }
        ball.game_over(window);



        window.clear();

        ball.render(window);
        ball.update(delta_time);
        
        racket.render(window);
        
        racket.detect_colision(&ball);

        window.display();

    }
    ImGui::SFML::Shutdown();
    return 0;
};