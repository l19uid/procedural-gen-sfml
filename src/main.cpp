#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "objects/World.h"

using namespace sf;
using namespace std;

int main()
{
    auto window = sf::RenderWindow{ { 800u, 650u }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    World world = World(20, 0);
    world.Generate();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        world.Render(window);
        window.display();
    }
}