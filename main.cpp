#include "Game.h"


int main(int argc,char* argv[])
{
    int width = 800;
    int height = 600;

    if (argc == 3)
    {
        try
        {
            width = std::stoi(argv[1]);
            height = std::stoi(argv[2]);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid arguments has to be integers" << std::endl;
            return 1;
        }
    }

    Game *game = new Game(width, height);
    return run(game);
}
