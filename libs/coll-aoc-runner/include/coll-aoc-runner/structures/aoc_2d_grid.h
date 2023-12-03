#ifndef COLL_AOC_RUNNER_AOC_2D_GRID_H
#define COLL_AOC_RUNNER_AOC_2D_GRID_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
class AoC2DGrid {
private:
    int width;
    int height;

    T** grid;
public:
    AoC2DGrid(int gridWidth, int gridHeight): width(gridWidth), height(gridHeight)
    {
        grid = new T*[height];
        for (int y = 0; y < height; y++)
            grid[y] = new T[gridWidth];
    }

    ~AoC2DGrid()
    {
        for (int y = height - 1; y >= 0; y--)
            delete grid[y];
        delete grid;
    }

    int getWidth() { return width; }
    int getHeight() { return height; }

    void setCell(const int& x, const int& y, const T& value)
    {
        grid[y][x] = value;
    }

    T getCell(const int& x, const int& y)
    {
        return grid[y][x];
    }

    vector<T> getAdjacentCells(const int& x, const int& y)
    {
        vector<T> adjacentCells;

        for (int dy = -1; dy <= 1; dy++)
            for (int dx = -1; dx <= 1; dx++)
                if ((dx != 0 || dy != 0) && (0 <= y + dy && y + dy < getHeight()) && (0 <= x + dx && x + dx < getWidth()))
                    adjacentCells.push_back(grid[y + dy][x + dx]);

        return adjacentCells;
    }

    T* operator[](const size_t& index)
    {
        return grid[index];
    }
};

#endif
