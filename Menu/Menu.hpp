#include "../includeManager.hpp"

class Menu {
protected:
    //WINDOW* win;
    Window win;
    Option* options;
    int numOptions;
    // int currentCursorPos;
public:
    //WINDOW* win; // che problemi potrebbe comportare mettere la win public?
    Menu();
    Menu(Window win, Option* options, int numOptions);
    // metodo draw per disegnare a schermo le varie opzioni
    int draw();
    Window getWinObj();
};