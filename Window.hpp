#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>

class Window{
    private:
        WINDOW* win;
        // finestra centrata sullo stdscr
        void defaultConstructor(int height, int width){
            int yMax, xMax;
            getmaxyx(stdscr, yMax, xMax);
            // creazione finestra
            win = newwin(height, width, (yMax/2) - (height/2), (xMax/2) - (width/2));
        };
    public:
        // finestra di dimensione 0 0
        Window(){
            defaultConstructor(0, 0);
        };
        // finestra di dimensione arbitraria
        Window(int height, int width){
            defaultConstructor(height, width);
        };
        // inizializza una finestra
        void init(){
            clear(); // pulisce la memoria
            refresh();
        };
        // metodo per aggiungere un bordo ad una finestra
        void addBorder(){
            box(this->win, 0, 0);
        };
        // metodo per aggiungere un carattere ad una finestra TODO
        void addCharWin(chtype val);
        // metodo che ritorna il tipo di input
        chtype getInput(){
            return wgetch(this->win);
        };
        // metodo che cancella il testo ma aggiorna la finestra mantenendo il bordo
        void clear(){
            wclear(this->win);
            this->addBorder();
        }
        void refresh(){
            wrefresh(this->win);
        }
        // get
        WINDOW* getWin(){
            return this->win;
        };
};