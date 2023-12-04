#include "Line.h"

Line::Line(Point a, Point b, float width, sf::Color color) :
        m_pointA(a),
        m_pointB(b),
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
            sf::Vertex(m_pointA.getPosition(), m_color),
            sf::Vertex(m_pointB.getPosition(),m_color)
    };

    window.draw(line, 2, sf::Lines);
}