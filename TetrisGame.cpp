#include "TetrisGame.hpp"

// costruttore
/*
TetrisGame::TetrisGame(int height, int width){
    this->window = Window(height, width);
    this->window.addBorder(0, 0);
    this->gameOver = false;
};
*/

/*
TetrisGame::TetrisGame(Menu& menu, int height, int width){
    this->window = Window(height, width);
    this->menu = menu;
    // Option options[MAX_OPTIONS] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT")};
    // this->options = options;
    // this->menu = Menu(this->window, this->options, MAX_OPTIONS);
    this->window.addBorder(0, 0);
    this->gameOver = false;
};
*/

// INSTANCE OF BAD ALLOC --> problema con l'array options --> non posso immagazzinare
// l'indirizzo di una variabile locale ad un metodo in una variabile globale TODO

// sistemato --> costruttore che compila senza errori
TetrisGame::TetrisGame(int height, int width){
    this->window = Window(height, width);
    // this->window.init();
    // this->menu = menu;
    // Option options[MAX_OPTIONS] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT")};
    this->window.addBox();
    // this->window.addCustomBorder('v','v','v','v','v','v','v','v');
    this->menu = Menu(this->window, this->options, MAX_OPTIONS);
    this->matrixBoard = MainMatrix(); // da vedere la posizione di questa inizializzazione
    this->menu.draw(); // viene messo anche qui perchè così non bisogna premere un tasto prima di far apparire il menù a schermo
    // this->matrixBoard.draw();
    this->gameOver = false;
};

// metodo per processare gli input
void TetrisGame::processInput(){
    Window previousOpenWindow = this->menu.getWin(); // sempre la finestra del menù
    Window currentOpenWindow = Window(previousOpenWindow.getWinHeight(), previousOpenWindow.getWinWidth());                
    // Window* swapPointer;
    bool optionState = this->menu.getOption().getOptionOpenState();
    // bool optionState = true;

    // int highlight = 0;
    keypad(this->window.getWin(), true);
    chtype input = this->window.getInput();
    switch(input){
        // case inutile per il gioco in se
        // per adesso mi serve per tornare alla finestra precedentemente aperta
        case KEY_BACKSPACE:
            // currentOpenWindow.clear();
            // this->window.refresh();
            // wgetch(currentOpenWindow.getWin());
            // this->window.getInput();
            // this->menu.getOption().setOptionOpenState(false);
            this->gameOver = true;
            break;
        case KEY_UP:
        case 'w':
            this->menu.decrHighlight();
            if(this->menu.getHighlight() == -1){
                this->menu.setHighlight(2);
            }
            break;
        case KEY_DOWN:
        case 's':
            this->menu.incrHighlight();
            if(this->menu.getHighlight() == 3){
                this->menu.setHighlight(0);
            }
            break;
        case 10: // enter key
            this->menu.getOption().setOptionOpenState(true);
            // int index = this->menu.getHighlight();
            // Window previousOpenWindow = this->menu.getWin(); // sempre la finestra del menù
            // Window currentOpenWindow = Window(previousOpenWindow.getWinHeight(), previousOpenWindow.getWinWidth());                

            if(strcmp(this->menu.getOption().getOptionTitle().c_str(), "NEWGAME") == 0){
                /*
                while(!optionState){
                    this->matrixBoard.draw();
                    if(input == KEY_BACKSPACE){
                        this->menu.getOption().setOptionOpenState(true);
                    }
                }
                */

                currentOpenWindow.addBox();
                this->window.refresh();
                currentOpenWindow.addDrawableObj(DrawableInterface(1, 1, "HELLO WORLD"));
                // previousOpenWindow.clear();
                // previousOpenWindow = this->menu.getWin();
                this->window = currentOpenWindow;
            } 
            
            if(strcmp(this->menu.getOption().getOptionTitle().c_str(), "LEADERBOARD") == 0){
                // this->window.clear();
                // this->window.init();
            }
            if(strcmp(this->menu.getOption().getOptionTitle().c_str(), "EXIT") == 0){
                this->window.clear();
                this->gameOver = true;
            } 
            break;
        default:
            break;
    }
};

// metodo per aggiornare lo stato del gioco
void TetrisGame::updateState(){
    /*
    this->window.addDrawableObj(DrawableInterface(this->window.getWinHeight()-3, (this->window.getWinWidth()/2)-22, "press 'w(s)' or 'key_up(down)' to navigate")); // quel 22 è la metà della lunghezza della stringa
    this->window.addDrawableObj(DrawableInterface(this->window.getWinHeight()-2, (this->window.getWinWidth() / 2)-18, "press 'key_enter to select an option"));
    */
    // this->window.addStringAt(this->window.getWinHeight()-2, (this->window.getWinWidth() / 2) - 22, "press 'w(s)' or 'key_up(down)' to navigate");
    this->menu.draw();
    // this->matrixBoard.draw();
};

// metodo per riaggiornare ciò che c'è a schermo
void TetrisGame::updateDraw(){
    this->window.refresh();
};

// metodi get
bool TetrisGame::isOver(){
    return this->gameOver;
};

Window TetrisGame::getW(){
    return this->window;
};

/*
Menu TetrisGame::getMenu(){
    return this->menu;
};
*/