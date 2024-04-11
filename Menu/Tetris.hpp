
#include"Classifica.hpp"
#include "Board.hpp"
#include "../Tetramini/Tetramino.hpp"
#include <thread>

class Tetris
{
protected:
    Menu startMenu;
    Classifica cla;
    Board board;
    Tetramino tetramino;
public:
   // void graviti();
    void processInput();
    Tetris(Menu start);
    void gameLoop();
};
