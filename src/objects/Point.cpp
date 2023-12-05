#include "Point.h"

Point::Point(sf::Vector2f position, bool isFilled, float radius, float thickness, sf::Color color,sf::Color outlineColor, bool centered) :
        m_position(position),
        m_filled(isFilled),
        m_radius(radius),
        m_color(color),
        m_thickness(thickness),
        m_outlineColor(outlineColor),
        m_centered(centered)
        {}

sf::Vector2f Point::getPosition() const {
    if(m_centered)
        return m_position - sf::Vector2f(m_radius,m_radius);
    return m_position;
}

float Point::getThickness() const {
    return m_thickness;
}

bool Point::getIsFilled() const {
    return m_filled;
}

float Point::getRadius() const {
    return m_radius;
}

sf::Color Point::getColor() const {
    return m_color;
}

sf::Color Point::getOutlineColor() const {
    return m_outlineColor;
}


void Point::Render(sf::RenderWindow& window) {
    sf::CircleShape point(getRadius());
    point.setFillColor(getColor());
    point.setPosition(getPosition());
    point.setOutlineColor(getOutlineColor());
    point.setOutlineThickness(getThickness());
    window.draw(point);
}