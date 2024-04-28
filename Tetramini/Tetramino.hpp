#include "../includeManager.hpp"

using namespace std;
class Tetramino
{
private:
    /* data */
    const char *type;
public:
    Tetramino(); //tyoe indica che tipo di tetramino è eg 1 tetramino linea retta, 2 il quadrato etc
    int rotateBlock(int i, int mode);
    void drawColorSqare(WINDOW* win, int x, int y);
    void draw(WINDOW* win, int row, int col, int rot);

};