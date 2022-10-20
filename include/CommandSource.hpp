#include <string>

class CommandSource
{

public:
    virtual std::string next_command() = 0;
    virtual ~CommandSource(){};
};

class AlwaysNextTurn : public CommandSource
{
    int turns_played = 0;

public:
    std::string next_command() override;
};

class UserCommands : public CommandSource
{
    int turns_playes = 0;

public:
    std::string next_command() override;
};