
#include"src/Classifica/Classifica.hpp"
#include "src/Tetramino/Tetramino.hpp"

class Tetris
{
protected:
    Menu startMenu;
    Classifica cla;
    //Tetramino t;
public:
    Tetris(Menu start);
    void gameLoop();
};
