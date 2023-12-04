#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>

class Point {
public:
    Point(sf::Vector2f position, bool isFilled, float radius, float thickness, sf::Color color, sf::Color outlineColor);

    sf::Vector2f getPosition() const;
    bool getIsFilled() const;
    float getRadius() const;
    sf::Color getColor() const;
    void Render(sf::RenderWindow& window);

private:
    sf::Vector2f m_position;
    float m_radius;
    float m_thickness;

    bool m_isFilled;
    sf::Color m_color;
    sf::Color m_outlineColor;
};

#endif /* POINT_H */