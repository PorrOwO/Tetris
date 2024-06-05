#include "Tetramino.hpp"
#include "utils.hpp"
#include <ncurses.h>
#include "TetrisBoard.hpp"
#include "Menu.hpp"
#include "Classifica.hpp"
#include "Game.hpp"
#include "Hud.hpp"

int main() {
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(utils::RED, COLOR_RED, COLOR_BLACK);
    init_pair(utils::GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(utils::YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(utils::BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(utils::PURPLE, COLOR_BLUE, COLOR_RED);
    init_pair(utils::CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(utils::ORANGE, COLOR_YELLOW, COLOR_RED);
    srand(time(nullptr));


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int winHeight = yMax - 10;
    int winWidth = xMax / 2;

    int yWinPos = (yMax / 2) - (winHeight / 2);
    int xWinPos = (xMax / 2) - (winWidth / 2);

    WINDOW* mainWin = newwin(winHeight, winWidth, yWinPos, xWinPos);
    

    
    WINDOW* boardWin = newwin(utils::BOARD_HEIGHT, utils::BOARD_WIDTH, 
                              yWinPos + (winHeight / 2) - (utils::BOARD_HEIGHT / 2),
                              xWinPos + (winWidth / 2) - (utils::BOARD_WIDTH / 2));
                                                       
    Option options[utils::NUM_OPTIONS] = {
        Option(utils::OPTION_1),
        Option(utils::OPTION_2),
        Option(utils::OPTION_3),
    };

    Menu menu = Menu(mainWin, options, utils::NUM_OPTIONS);
    int scelta=-1;
    int score;

    nodelay(boardWin, TRUE);
    keypad(boardWin, TRUE);


    Hud hud= Hud(mainWin, 0, utils::MULTIPLIER);
    TetrisBoard board = TetrisBoard(boardWin);
    Tetramino tetramino = Tetramino(boardWin);
    Game inizio= Game(mainWin,board,tetramino, hud);
    
    while(scelta!=2) {   
        Classifica leaderBoard= Classifica(mainWin);
        box(mainWin, 0, 0);
        scelta=menu.draw();
        wclear(mainWin);
        refresh();
        switch(scelta)
        {
            case 0: //caso newGame
            {   
                hud.printHUD();
                score=inizio.loop();
                leaderBoard.Aggiorna(score);
                hud.destroyHUD();
                wclear(mainWin);
                refresh();
                break;
            }
            case 1: //caso leaderboard
            {  
                leaderBoard.Mostra();
                break;
            }
            case 2: //caso exit
            {
                break;
            }
            default:
             break;

        }

    }
    
   // inizio.loop();

    
    endwin();
    return 0;
}
