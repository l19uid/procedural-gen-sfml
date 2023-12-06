#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Line.h"

class Cell {
public:
    Cell(std::vector<Line> lines, Point centroid, float thickness, bool showCentroid, sf::Color color = sf::Color::Green,bool useLineColor = false);

    std::vector<Line> getLines() const;
    Point getCentroid() const;
    void Render(sf::RenderWindow& window);
    static Point generateCentroid(std::vector<Line> lines);

private:
    std::vector<Line> m_lines;
    Point m_centroid;
    bool m_showCentroid;
    float m_thickness;
    sf::Color m_color;
    bool m_useLineColor;
};


#endif /* CELL_H */