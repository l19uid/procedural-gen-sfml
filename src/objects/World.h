//
// Created by Liquid on 3/29/2023.
//

#ifndef VORONOI_WORLD_GEN_WORLD_H
#define VORONOI_WORLD_GEN_WORLD_H


#include "Point.h"
#include "Cell.h"
#include "../utils/random.h"
#include "../utils/FastNoiseLite.h"
#include "../utils/BiomeHandler.h"
class World {
private:
    int m_size;
    FastNoiseLite m_gen;
    int m_numPoints;
    int m_numCells;
    int m_numLines;
    int m_gap = 20;

    std::vector<Point> m_points;
    std::vector<Cell> m_cells;
    std::vector<Line> m_lines;

public:
    World(int size, int gap, FastNoiseLite gen);
    void generate();
    void render(sf::RenderWindow& window);
    int getSize() const;
    int getSeed() const;
    int getNumPoints() const;
    int getNumCells() const;
    int getNumLines() const;
    std::vector<Point> getPoints() const;
    std::vector<Cell> getCells() const;
    std::vector<Line> getLines() const;
    float GetNoiseHeight(float x, float y);
};


#endif //VORONOI_WORLD_GEN_WORLD_H
