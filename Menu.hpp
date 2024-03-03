#include "Window.hpp"
#include "Options.hpp"

class Menu{
    protected:
        Window win;
        Option* options;
        int numOptions;
        int highlight = 0;
    public:
        // costruttori
        Menu();
        Menu(Window window, Option* options, int numOptions);
        
        // distruttore
        //~Menu();

        // metodo per stampare a schermo il menù
        void draw();

        // metodi per la gestione dell'highlight
        void incrHighlight(); // incrementa di 1 
        void decrHighlight(); // decrementa di 1
        void setHighlight(int val); // setter
        
        // metodi get
        Window getWin();
        Option getOption();
        int getNumOptions();
        int getHighlight();
};