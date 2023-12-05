//
// Created by Liquid on 3/29/2023.
//

#include "World.h"

World::World(int size, FastNoiseLite gen) {
    m_size = size;
    m_gen = gen;
    m_numPoints = 0;
    m_numCells = 0;
    m_numLines = 0;
}

int World::getSize() const {
    return m_size;
}
int World::getNumPoints() const {
    return m_numPoints;
}
int World::getNumCells() const {
    return m_numCells;
}
int World::getNumLines() const {
    return m_numLines;
}

std::vector<Point> World::getPoints() const {
    return m_points;
}
std::vector<Cell> World::getCells() const {
    return m_cells;
}
std::vector<Line> World::getLines() const {
    return m_lines;
}

void World::generate() {
    random random;
    // Generate points
    std::vector<Point> points;
    for (int x = 0; x < m_size; x++) {
        for (int y = 0; y < m_size; y++) {
                points.push_back(Point( sf::Vector2f((x+1)*25, (y+1)*25),true,2, 0,
                                        BiomeHandler::ConvertToColor(GetNoiseHeight(x,y),enums::Biome::GRASSLAND)));
        }
    }
    m_points = points;
    m_numPoints = points.size();

    std::vector<Line> lines;
    for (int x = 0; x < m_numPoints-1; x++) {
        if(x+m_size<m_numPoints)
            lines.push_back(Line(&m_points[x], &m_points[x+m_size], 1, random.randomColor()));
        if(x%m_size-19!=0)
        {
            lines.push_back(Line(&m_points[x], &m_points[x+1], 1, random.randomColor()));
        }
    }

    m_lines = lines;
    m_numLines = lines.size();
}

void World::render(sf::RenderWindow& window) {
    // Render points
    for (int i = 0; i < m_numPoints; i++) {
        m_points[i].Render(window);
    }

    // Render lines
    for (int i = 0; i < m_numLines; i++) {
        m_lines[i].Render(window);
    }
}

float World::GetNoiseHeight(float x, float y) {
    return m_gen.GetNoise(x,y);
}