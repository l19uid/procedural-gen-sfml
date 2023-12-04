#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Line.h"

class Cell {
public:
    Cell(std::vector<Line> lines, Point centroid, float thickness, bool showCentroid, sf::Color color);

    std::vector<Line> getLines() const;
    Point getCentroid() const;
    void Render(sf::RenderWindow& window);

private:
    std::vector<Line> m_lines;
    Point m_centroid;
    bool m_showCentroid;
    float m_thickness;
    sf::Color m_color;
};


#endif /* CELL_H */