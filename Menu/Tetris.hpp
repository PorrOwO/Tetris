
#include"Classifica.hpp"
#include "Board.hpp"

class Tetris
{
protected:
    Menu startMenu;
    Classifica cla;
    Board board;
public:
    Tetris(Menu start);
    void gameLoop();
};
