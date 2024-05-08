#include "Option.hpp"
#include "ncurses.h"

class Menu {
protected:
    //WINDOW* win;
    WINDOW* win;
    Option* options;
    int numOptions;
    // int currentCursorPos;
public:
    //WINDOW* win; // che problemi potrebbe comportare mettere la win public?
    Menu();
    Menu(WINDOW* win, Option* options, int numOptions);
    // metodo draw per disegnare a schermo le varie opzioni
    int draw();
    WINDOW* getWin();
};
