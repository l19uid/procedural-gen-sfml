#include "Cell.h"

Cell::Cell(std::vector<Line> lines, Point centroid, float thickness, bool showCentroid, sf::Color color, bool useLineColor) :
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
    //for (auto& line : m_lines) {
    //    line.Render(window);
    //}

    sf::ConvexShape convexShape;
    convexShape.setPointCount(m_lines.size());
    for (int i = 0; i < m_lines.size(); i++) {
        convexShape.setPoint(i, m_lines[i].getA().getPosition());
    }
    if(m_useLineColor)
        convexShape.setFillColor(m_lines[0].getColor());
    else
        convexShape.setFillColor(m_color);

    convexShape.setOutlineColor(sf::Color::Transparent);
    convexShape.setOutlineThickness(m_thickness);
    window.draw(convexShape);

    if(m_showCentroid)
        m_centroid.Render(window); // Render the centroid.
}

Point Cell::generateCentroid(std::vector<Line> lines) {
    float x = 0;
    float y = 0;
    for (auto& line : lines) {
        x += line.getA().getPosition().x;
        y += line.getA().getPosition().y;
    }
    return Point(sf::Vector2f(x/lines.size(), y/lines.size()), true, 2, 0, sf::Color::White);
}