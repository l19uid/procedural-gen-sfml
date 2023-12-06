#include "Line.h"

Line::Line(Point pointA, Point pointB, float width, sf::Color color) :
        m_pointA(pointA),
        m_pointB(pointB),
        m_width(width),
        m_color(color) {}

Point Line::getA() const {
    return m_pointA;
}

Point Line::getB() const {
    return m_pointB;
}

float Line::getWidth() const {
    return m_width;
}

sf::Color Line::getColor() const {
    return m_color;
}

void Line::Render(sf::RenderWindow& window) {
    sf::Vertex line[] = {
            sf::Vertex(getA().getPosition(), m_color),
            sf::Vertex(getB().getPosition(),m_color)
    };

    window.draw(line, 2, sf::Lines);
}