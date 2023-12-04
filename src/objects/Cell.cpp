#include "Cell.h"

Cell::Cell(std::vector<Line> lines, Point centroid, float thickness, bool showCentroid, sf::Color color) :
        m_lines(lines),
        m_centroid(centroid),
        m_showCentroid(showCentroid),
        m_thickness(thickness),
        m_color(color)
        {}

std::vector<Line> Cell::getLines() const {
    return m_lines;
}

Point Cell::getCentroid() const {
    return m_centroid;
}

void Cell::Render(sf::RenderWindow& window) {
    for (auto& line : m_lines) {
        line.Render(window);
    }

    sf::ConvexShape convexShape;
    convexShape.setPointCount(m_lines.size());
    for (int i = 0; i < m_lines.size(); i++) {
        convexShape.setPoint(i, m_lines[i].getA().getPosition());
    }
    convexShape.setFillColor(sf::Color::Transparent);
    convexShape.setOutlineColor(sf::Color::Transparent);
    convexShape.setOutlineThickness(m_thickness);
    window.draw(convexShape);

    if(m_showCentroid)
        m_centroid.Render(window); // Render the centroid.
}