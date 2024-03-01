#include "Tetris.hpp"
Tetris::Tetris(Menu start)
{
    this->startMenu=start;
};


//Loop principale di gioco
void Tetris::gameLoop(){
    int esci=-1;
    do{
        box(this->startMenu.win,0,0);
        int scelta=this->startMenu.draw(); //prende l'opzione che era evidenziata nel menu nel momento in cui l'utente ha premuto enter

    switch(scelta)
    {case 0: //caso new game
    { //TO DO
        wclear(this->startMenu.win);
        refresh();
         mvwprintw(this->startMenu.win,5,5 ,"finestra di gioco");
        wgetch(this->startMenu.win);
        break;}

        case 1:{ //caso classifica
        wclear(this->startMenu.win);
        refresh();//posso passare la finestra del menu per scriverci sopra la classifica oppure una nuova
        wborder(this->startMenu.win,'|','|','-','-','@','@','@','@');
        this->cla= Classifica(this->startMenu.win);
        esci=cla.Mostra();
        break;

    }
        case 2:{ //caso exit
            esci=0;
            break;
        }

        default:
        {break;}

    }
    }while(esci==-1);
};
