//
// Created by Liquid on 3/29/2023.
//

#include "World.h"

World::World(int size, int gap, FastNoiseLite gen) {
    m_size = size;
    m_gen = gen;
    m_numPoints = 0;
    m_numCells = 0;
    m_numLines = 0;
    m_gap = gap;
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
    // Generate points
    std::vector<Point> points;
    for (int x = 0; x < m_size; x++) {
        for (int y = 0; y < m_size; y++) {
                points.emplace_back( sf::Vector2f((x+1)*m_gap, (y+1)*m_gap),true,16, 0,
                                        BiomeHandler::ConvertToColor(GetNoiseHeight(x,y),enums::Biome::GRASSLAND));
                std::cout << "Point: " << x << ", " << y << " : " << GetNoiseHeight(x,y) << std::endl;
        }
    }
    m_points = points;
    m_numPoints = (int)points.size();

    std::vector<Line> lines;
    for (int x = 0; x < m_numPoints-1; x++) {
        if(x%m_size!=0 && x+m_size<m_numPoints)
        {
            lines.emplace_back(m_points[x-1], m_points[x], 1, sf::Color::White);
            lines.emplace_back(m_points[x], m_points[x+m_size], 1, sf::Color::White);
            lines.emplace_back(m_points[x+m_size], m_points[x-1], 1, sf::Color::White);
        }
        if(x%m_size!=m_size-1 && x-m_size>=0)
        {
            lines.emplace_back(m_points[x-m_size], m_points[x], 1, sf::Color::White);
            lines.emplace_back(m_points[x], m_points[x+1], 1, sf::Color::White);
            lines.emplace_back(m_points[x+1], m_points[x-m_size], 1, sf::Color::White);
        }
    }
    m_lines = lines;
    m_numLines = (int)lines.size();

    std::vector<Cell> cells;
    for (int x = 0; x < m_numLines; x+=3) {
        std::vector<Line> lines;
        lines.emplace_back(m_lines[x]);
        lines.emplace_back(m_lines[x+1]);
        lines.emplace_back(m_lines[x+2]);
        cells.emplace_back(lines, Cell::generateCentroid(lines), 1, false, sf::Color::Green, true);
    }

    m_cells = cells;
    m_numCells = (int)cells.size();
}

void World::render(sf::RenderWindow& window) {
    window.clear(sf::Color(30,100,200));
    // Render points
    for (int i = 0; i < m_numPoints; i++) {
        m_points[i].Render(window);
    }

    // Render lines
    //for (int i = 0; i < m_numLines; i++) {
    //    m_lines[i].Render(window);
    //}
//
    //// Render cells
    //for (int i = 0; i < m_numCells; i++) {
    //    m_cells[i].Render(window);
    //}
}

float World::GetNoiseHeight(float x, float y) {
    return m_gen.GetNoise(x,y) * 64 ;
}