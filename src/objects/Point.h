#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Point {
public:
    Point(sf::Vector2f position, bool isFilled, float radius, float thickness,
          sf::Color color = sf::Color::White, sf::Color outlineColor = sf::Color::White,
          bool centered = true);

    sf::Vector2f getPosition() const;
    bool getIsFilled() const;
    float getThickness() const;
    float getRadius() const;
    sf::Color getColor() const;
    sf::Color getOutlineColor() const;
    void Render(sf::RenderWindow& window);

private:
    sf::Vector2f m_position;
    float m_radius;
    float m_thickness;
    bool m_filled;
    bool m_centered;
    sf::Color m_color;
    sf::Color m_outlineColor;
};

#endif /* POINT_H */