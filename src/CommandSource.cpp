#include "CommandSource.hpp"
#include <iostream>
#include <chrono>
#include <thread>

namespace GAME
{
    const int GFX_PLAY_INDEX = 49;
    const int GFX_END_INDEX = 50;
}

std::string AlwaysNextTurn::next_command()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(200ms);

    if (turns_played++ > 50)
        return "quit";
    return "next";
}

std::string UserCommands::next_command()
{
    char choice = ' ';

    std::cout << "Press '1' to make a move." << std::endl;
    std::cout << "Press '2' to end a game." << std::endl;
    std::cout << "To continue, select the number and confirm by pressing Enter" << std::endl;

    std::cin >> choice;

    switch (choice)
    {
    case GAME::GFX_PLAY_INDEX: // 1
        return "move";
        std::cout << "Press '1' to make a move." << std::endl;
        std::cout << "Press '2' to end a game." << std::endl;
        std::cout << "To continue, select the number and confirm by pressing Enter" << std::endl;
        break;
    case GAME::GFX_END_INDEX: // 2
        std::cout << "Program Closed." << std::endl;
        return "quit";
        break;
    default:
        std::cout << "An error has occurred." << std::endl;
        std::cout << "Please, select another option" << std::endl;
        return "error";
        break;
    }
}