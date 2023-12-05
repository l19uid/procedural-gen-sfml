#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "objects/World.h"

using namespace sf;
using namespace std;

#include "utils/random.h"

int main()
{
    auto window = sf::RenderWindow{ { 800u, 650u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    FastNoiseLite gen;
    gen.SetSeed(111);
    gen.SetFractalOctaves(4);
    gen.SetFrequency(10);
    gen.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_Perlin);

    World world = World(20, gen);
    world.generate();

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
        world.render(window);
        window.display();
    }
}