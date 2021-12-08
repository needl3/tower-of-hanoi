#include "main.hpp"

int main()
{
    Hanoi game(3, 3);
    while(game.run());
    return 0;
}