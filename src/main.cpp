#include "GameOfLife.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>

int main()
{
    std::string game_mode;
    std::string width_alp;
    std::string height_alp;
    std::string lineGame;
    char setstart;
    int rowCounter = 0;
    int colCounter = 0;

    std::fstream plik;
    plik.open("plik.txt", std::ios::in);
    if (not plik.is_open())
        return 1;

    getline(plik, game_mode);
    getline(plik, width_alp);
    getline(plik, height_alp);
    int width = stoi(width_alp);
    int height = stoi(height_alp);

    const char *a = game_mode.c_str();

    std::string PLANE_TYPE = "plane";
    const char *b = PLANE_TYPE.c_str();
    int result1 = strcmp(a, b);

    std::string CYLINDER_TYPE = "cylinder";
    const char *c = CYLINDER_TYPE.c_str();
    int result2 = strcmp(a, c);

    std::string TORUS_TYPE = "torus";
    const char *d = TORUS_TYPE.c_str();
    int result3 = strcmp(a, d);

    if (result1 == 0)
    {
        PLANE P(width, height);

        while (!plik.eof())
        {
            getline(plik, lineGame);
            for (unsigned int i = 0; i < lineGame.size(); i++)
            {
                setstart = lineGame[i];
                ;
                if (setstart == '#')
                {
                    P.SetStart(rowCounter, colCounter);
                }
                colCounter++;
            }
            colCounter = 0;
            rowCounter++;
        }
        plik.close();

        AlwaysNextTurn auto_command_source;
        UserCommands user_command_source;
        std::string choice_game;
        std::cout << "Select command source [user, auto]: ";
        std::cin >> choice_game;
        if (choice_game == "user")
            P.play(user_command_source);
        if (choice_game == "auto")
            P.play(auto_command_source);
    }

    if (result2 == 0)
    {
        CYLINDER C(width, height);

        while (!plik.eof())
        {
            getline(plik, lineGame);
            for (unsigned int i = 0; i < lineGame.size(); i++)
            {
                setstart = lineGame[i];
                ;
                if (setstart == '#')
                {
                    C.SetStart(rowCounter, colCounter);
                }
                colCounter++;
            }
            colCounter = 0;
            rowCounter++;
        }
        plik.close();

        AlwaysNextTurn auto_command_source;
        UserCommands user_command_source;
        std::string choice_game;
        std::cout << "Select command source [user, auto]: ";
        std::cin >> choice_game;
        if (choice_game == "user")
            C.play(user_command_source);
        if (choice_game == "auto")
            C.play(auto_command_source);
    }

    if (result3 == 0)
    {
        TORUS T(width, height);

        while (!plik.eof())
        {
            getline(plik, lineGame);
            for (unsigned int i = 0; i < lineGame.size(); i++)
            {
                setstart = lineGame[i];
                ;
                if (setstart == '#')
                {
                    T.SetStart(rowCounter, colCounter);
                }
                colCounter++;
            }
            colCounter = 0;
            rowCounter++;
        }
        plik.close();

        AlwaysNextTurn auto_command_source;
        UserCommands user_command_source;
        std::string choice_game;
        std::cout << "Select command source [user, auto]: ";
        std::cin >> choice_game;
        if (choice_game == "user")
            T.play(user_command_source);
        if (choice_game == "auto")
            T.play(auto_command_source);
    }

    return 0;
}