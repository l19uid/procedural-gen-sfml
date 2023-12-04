#include "Point.h"

Point::Point(sf::Vector2f position, bool isFilled, float radius, float thickness, sf::Color color,sf::Color outlineColor) :
        m_position(position),
        m_isFilled(isFilled),
        m_radius(radius),
        m_color(color),
        m_thickness(thickness),
        m_outlineColor(outlineColor)
        {}

sf::Vector2f Point::getPosition() const {
    return m_position;
}

bool Point::getIsFilled() const {
    return m_isFilled;
}

float Point::getRadius() const {
    return m_radius;
}

sf::Color Point::getColor() const {
    return m_color;
}

void Point::Render(sf::RenderWindow& window) {
    sf::CircleShape point(m_radius);
    point.setFillColor(m_color);
    point.setPosition(m_position);
    point.setOutlineColor(m_outlineColor);
    point.setOutlineThickness(m_thickness);
    window.draw(point);
}