#include "TetrisGame.hpp"

#define HEIGHT 40
#define WIDTH 80

/*
    X = fatto
    ~ = funziona ma va sistemato
    - = da fare

    TODO
    X Sistemare opzioni
    X Disegnare opzioni a schermo
    X Sistemare spaziatura opzioni
    X Sistemare Highlight delle opzioni --> process input
    X Uscita attraverso l'opzione exit
    ~ funzione per aprire una nuova finestra --> *DANGER*
    - fare un metodo per distrugere e disattivare il menù principale
    - quando si apre una nuova finestra il menù rimane aperto e le opzioni possono ancora
      essere premute --> *SUPER DANGER* --> da sistemare in fretta
      --> possibili idee:
          1) eliminare il menù --> pericoloso
          2) eliminare le opzioni --> pericolosissimo
          3) mettere le opzioni non selezionabili fino alla pressione di un preciso tasto
    - rivedere e sistemare optionOpenState
    ~ matrix board
    - cambiare il tipo di matrice --> da chtype a int e poi fare il bordo intorno alla finestra creata con dei caratteri specifici
    - metodo matrix.draw() --> da cambiare?
    - matrice di finestre?
    - apertura di matrix board dall'opzione 'NEWGAME'
    - apertura della classifica dall'opzione 'LEADERBOARD'
    - matrix weight
    - matrix rotation
    - matrix speed
    - spostamento tetramino
*/

int main(int argc, char* argv[]){
    initscr();
    refresh();
    noecho();

    /*
    Window menuWin(HEIGHT, WIDTH);
    Option options[MAX_OPTIONS] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT")};
    Menu menu(menuWin, options, MAX_OPTIONS);

    TetrisGame board(menu, HEIGHT, WIDTH);   
    */

    TetrisGame board(HEIGHT, WIDTH);

    while(!board.isOver()){
        board.processInput();
        board.updateDraw();
        board.updateState();
    }

    // wgetch(board.getW().getWin());
    endwin();
    return 0;
}