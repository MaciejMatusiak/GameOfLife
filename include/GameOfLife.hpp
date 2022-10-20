#pragma once
#include <vector>
#include "CommandSource.hpp"

struct Cell
{
    bool isLife;
    bool change;
};

class GameOfLife
{
    virtual void play(CommandSource &command_source) = 0;
    virtual void SetDeath(int row, int col) = 0;
    virtual void SetLife(int row, int col) = 0;
    virtual int count(int row, int col) = 0;
    virtual void debug_display() = 0;
    virtual void CheckMove() = 0;
    virtual void SetMove() = 0;
    virtual void SetStart(int row, int col) = 0;
};

class PLANE : public GameOfLife
{
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;

public:
    PLANE(int width, int height);
    void debug_display() override;
    int count(int row, int col) override;
    void SetLife(int row, int col) override;
    void SetDeath(int row, int col) override;
    void CheckMove() override;
    void SetMove() override;
    void play(CommandSource &command_source);
    void SetStart(int row, int col) override;
};

class CYLINDER : public GameOfLife
{
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;

public:
    CYLINDER(int width, int height);
    void debug_display() override;
    int count(int row, int col) override;
    void SetLife(int row, int col) override;
    void SetDeath(int row, int col) override;
    void CheckMove() override;
    void SetMove() override;
    void play(CommandSource &command_source);
    void SetStart(int row, int col) override;
};

class TORUS : public GameOfLife
{
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;

public:
    TORUS(int width, int height);
    void debug_display() override;
    int count(int row, int col) override;
    void SetLife(int row, int col) override;
    void SetDeath(int row, int col) override;
    void CheckMove() override;
    void SetMove() override;
    void play(CommandSource &command_source);
    void SetStart(int row, int col) override;
};