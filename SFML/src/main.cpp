#include "game.hpp"

using std::cout;
using std::endl;

// TODO: vertically align numbers on screen

int main()
{
    Game game;
    game.Run();

    return 0;
}

// ---- code to maybe use later idk ----

// convert a float 'elapsed' to display with 2 decimal places
//std::stringstream stream;
//stream << std::fixed << std::setprecision(2) << elapsed;
//std::string s = stream.str();
