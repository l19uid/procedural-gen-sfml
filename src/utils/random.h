#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <random>

class random {
public:
    static int randomInt(int min, int max)
    {
        std::srand(std::time(NULL)); // set seed to current time
        return rand() % max + min; // returns random int between min and max
    }

    static float randomFloat(float min, float max)
    {
        std::srand(std::time(nullptr)); // set seed to current time
        return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min))); // returns random float between min and max
    }

    static sf::Color randomColor()
    {
        static std::mt19937 generator(std::time(nullptr));
        std::uniform_int_distribution<int> distribution(0, 255);
        return sf::Color(distribution(generator), distribution(generator), distribution(generator)); // returns random color
    }

    static sf::Vector2f randomVector2f(int min, int max)
    {
        static std::mt19937 generator(std::time(nullptr));
        std::uniform_real_distribution<float> distribution(min, max);
        return sf::Vector2f(distribution(generator), distribution(generator)); // returns random vector2 float
    }

};
#endif //RANDOM_H
