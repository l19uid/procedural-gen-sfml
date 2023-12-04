#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line {
public:
    Line(Point pointA, Point pointB, float width, sf::Color color);

    Point getA() const;
    Point getB() const;
    float getWidth() const;
    sf::Color getColor() const;
    void Render(sf::RenderWindow& window);

private:
    Point m_pointA;
    Point m_pointB;
    float m_width;
    sf::Color m_color;
};

#endif /* LINE_H */