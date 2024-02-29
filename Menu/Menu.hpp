/*#include <iostream>
#include <cstring>
#include <string>
#include <ncurses.h>
using namespace std;


    TODO:
    X funzione per scorrere le opzioni
    - decidere e sistemare dimensioni finestra 
    X posizionare al centro le opzioni
    - apertura di altre finestre quando si preme un'opzione
    - apertura file di classifica dalla rispettiva opzione
    - funzioni di lettura e scrittura su file classifica *main?*
*/
#include <iostream>
#include <cstring>
#include <string>
#include <ncurses.h>
#include<fstream>
using namespace std;

// gestione le opzioni del menù
class Option{
    protected:
        string optionTitle;
        int currentCursorXPos;
        int currentCursorYPos;
    public:
        Option(string optionTitle);

        // get
        string getTitle();
        int getCurrentCursorXpos();
        int getCurrentCursorYpos();

        // set
        void setCurrentCursorXPos(int val);
        void setCurrentCursorYPos(int val);
};

// gestione degli attributi e della finestra menù visualizzata a schermo
class Menu{
    protected:
       // WINDOW* win;
        Option* options;
        int numOptions;
        // int currentCursorPos;
    public:
         WINDOW* win; // che problemi potrebbe comportare mettere la win public?
         Menu();
        Menu(WINDOW* win, Option* options, int numOptions);
        // metodo draw per disegnare a schermo le varie opzioni
        int draw();
};
