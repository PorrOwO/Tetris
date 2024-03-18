#include <ncurses.h>
#include <iostream>

using namespace std;
class Tetramino
{
private:
    /* data */
    wstring type[7];

public:
    Tetramino(char* tipo); //tyoe indica che tipo di tetramino è eg 1 tetramino linea retta, 2 il quadrato etc
    ~Tetramino();
    void draw();
    wstring getRngType();
};