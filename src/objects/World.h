//
// Created by Liquid on 3/29/2023.
//

#ifndef VORONOI_WORLD_GEN_WORLD_H
#define VORONOI_WORLD_GEN_WORLD_H


#include "Point.h"
#include "Cell.h"
#include "../utils/random.h"

class World {
private:
    int m_size;
    int m_seed;
    int m_numPoints;
    int m_numCells;
    int m_numLines;

    std::vector<Point> m_points;
    std::vector<Cell> m_cells;
    std::vector<Line> m_lines;

public:
    World(int size, int seed);
    void Generate();
    void Render(sf::RenderWindow& window);
    int GetSize() const;
    int GetSeed() const;
    int GetNumPoints() const;
    int GetNumCells() const;
    int GetNumLines() const;
    std::vector<Point> GetPoints() const;
    std::vector<Cell> GetCells() const;
    std::vector<Line> GetLines() const;
};


#endif //VORONOI_WORLD_GEN_WORLD_H
