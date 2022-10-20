#include "GameOfLife.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

PLANE::PLANE(int width, int height)
{
    this->height = height;
    this->width = width;

    for (int row = 0; row < height; ++row)
    {
        cells.push_back({});
        for (int col = 0; col < width; ++col)
        {
            cells[row].push_back(Cell{false, false});
        }
    }
}

void PLANE::debug_display()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            std::cout << " ";

            if (cells[row][col].isLife)
                std::cout << "#";
            else
                std::cout << ".";

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int PLANE::count(int row, int col)
{
    int count = 0;
    for (int i = (row - 1); i <= (row + 1); i++)
    {
        for (int j = (col - 1); j <= (col + 1); j++)
        {
            if ((i != row || j != col) && ((i >= 0 && i <= height - 1) && (j >= 0 && j <= width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
        }
    }
    return count;
}

void PLANE::SetLife(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife == false))
        cells[row][col].isLife = true;
}

void PLANE::SetDeath(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife))
        cells[row][col].isLife = false;
}

void PLANE::CheckMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if ((cells[row][col].isLife == false) && (count(row, col) == 3))
                cells[row][col].change = true;
            if ((cells[row][col].isLife) && (count(row, col) < 2 || count(row, col) > 3))
                cells[row][col].change = true;
        }
    }
}

void PLANE::SetMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (cells[row][col].change)
            {
                if (cells[row][col].change && cells[row][col].isLife)
                {
                    SetDeath(row, col);
                    cells[row][col].change = false;
                }
                if (cells[row][col].change && cells[row][col].isLife == false)
                {
                    SetLife(row, col);
                    cells[row][col].change = false;
                }
            }
        }
    }
}

void PLANE::play(CommandSource &command_source)
{
    while (true)
    {
        std::string command = command_source.next_command();

        if (command == "quit")
            return;
        if (command == "next")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
        if (command == "move")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
    }
}

void PLANE::SetStart(int row, int col)
{
    if (cells[row][col].isLife == false)
        cells[row][col].isLife = true;
}

CYLINDER::CYLINDER(int width, int height)
{
    this->height = height;
    this->width = width;

    for (int row = 0; row < height; ++row)
    {
        cells.push_back({});
        for (int col = 0; col < width; ++col)
        {
            cells[row].push_back(Cell{false, false});
        }
    }
}

void CYLINDER::debug_display()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            std::cout << " ";

            if (cells[row][col].isLife)
                std::cout << "#";
            else
                std::cout << ".";

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int CYLINDER::count(int row, int col)
{
    int count = 0;
    for (int i = (row - 1); i <= (row + 1); i++)
    {
        for (int j = (col - 1); j <= (col + 1); j++)
        {
            if ((i != row || j != col) && ((i >= 0 && i <= height - 1) && (j >= 0 && j <= width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
            if ((i != row || j != col) && ((i >= 0 && i <= height - 1) && (j == width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
        }
    }
    return count;
}

void CYLINDER::SetLife(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife == false))
        cells[row][col].isLife = true;
}

void CYLINDER::SetDeath(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife))
        cells[row][col].isLife = false;
}

void CYLINDER::CheckMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if ((cells[row][col].isLife == false) && (count(row, col) == 3))
                cells[row][col].change = true;
            if ((cells[row][col].isLife) && (count(row, col) < 2 || count(row, col) > 3))
                cells[row][col].change = true;
        }
    }
}

void CYLINDER::SetMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (cells[row][col].change)
            {
                if (cells[row][col].change && cells[row][col].isLife)
                {
                    SetDeath(row, col);
                    cells[row][col].change = false;
                }
                if (cells[row][col].change && cells[row][col].isLife == false)
                {
                    SetLife(row, col);
                    cells[row][col].change = false;
                }
            }
        }
    }
}

void CYLINDER::play(CommandSource &command_source)
{
    while (true)
    {
        std::string command = command_source.next_command();

        if (command == "quit")
            return;
        if (command == "next")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
        if (command == "move")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
    }
}

void CYLINDER::SetStart(int row, int col)
{
    if (cells[row][col].isLife == false)
        cells[row][col].isLife = true;
}

TORUS::TORUS(int width, int height)
{
    this->height = height;
    this->width = width;

    for (int row = 0; row < height; ++row)
    {
        cells.push_back({});
        for (int col = 0; col < width; ++col)
        {
            cells[row].push_back(Cell{false, false});
        }
    }
}

void TORUS::debug_display()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            std::cout << " ";

            if (cells[row][col].isLife)
                std::cout << "#";
            else
                std::cout << ".";

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int TORUS::count(int row, int col)
{
    int count = 0;
    for (int i = (row - 1); i <= (row + 1); i++)
    {
        for (int j = (col - 1); j <= (col + 1); j++)
        {
            if ((i != row || j != col) && ((i >= 0 && i <= height - 1) && (j >= 0 && j <= width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
            if ((i != row || j != col) && ((i >= 0 && i <= height - 1) && (j == width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
            if ((i != row || j != col) && ((i == height - 1) && (j >= 0 && j <= width - 1)))
            {
                if (cells[i][j].isLife)
                    count++;
            }
        }
    }
    return count;
}

void TORUS::SetLife(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife == false))
        cells[row][col].isLife = true;
}

void TORUS::SetDeath(int row, int col)
{
    if ((cells[row][col].change) && (cells[row][col].isLife))
        cells[row][col].isLife = false;
}

void TORUS::CheckMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if ((cells[row][col].isLife == false) && (count(row, col) == 3))
                cells[row][col].change = true;
            if ((cells[row][col].isLife) && (count(row, col) < 2 || count(row, col) > 3))
                cells[row][col].change = true;
        }
    }
}

void TORUS::SetMove()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if (cells[row][col].change)
            {
                if (cells[row][col].change && cells[row][col].isLife)
                {
                    SetDeath(row, col);
                    cells[row][col].change = false;
                }
                if (cells[row][col].change && cells[row][col].isLife == false)
                {
                    SetLife(row, col);
                    cells[row][col].change = false;
                }
            }
        }
    }
}

void TORUS::play(CommandSource &command_source)
{
    while (true)
    {
        std::string command = command_source.next_command();

        if (command == "quit")
            return;
        if (command == "next")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
        if (command == "move")
        {
            system("clear");
            CheckMove();
            SetMove();
            debug_display();
            system("sleep .1");
        }
    }
}

void TORUS::SetStart(int row, int col)
{
    if (cells[row][col].isLife == false)
        cells[row][col].isLife = true;
}
