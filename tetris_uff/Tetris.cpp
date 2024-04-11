#include "Tetris.hpp"
Tetris::Tetris(Menu start)
{
    this->startMenu=start;
};


//Loop principale di gioco
void Tetris::gameLoop(){
    int esci=-1;
    do{
        box(this->startMenu.GetWin().getWin(),0,0);
        int scelta=this->startMenu.draw(); //prende l'opzione che era evidenziata nel menu nel momento in cui l'utente ha premuto enter

        switch(scelta)
        {case 0: //caso new game
            { //TO DO
                wclear(this->startMenu.GetWin().getWin());
                refresh();
                mvwprintw(this->startMenu.GetWin().getWin(),5,5 ,"finestra di gioco");
                this->cla.Aggiorna(200); //per vedere se funziona funzione aggiorna
                wgetch(this->startMenu.GetWin().getWin());
                break;}

            case 1:{ //caso classifica
                       wclear(this->startMenu.GetWin().getWin());
                       refresh();//posso passare la finestra del menu per scriverci sopra la classifica oppure una nuova
                       wborder(this->startMenu.GetWin().getWin(),'|','|','-','-','@','@','@','@');
                       this->cla= Classifica(this->startMenu.GetWin()); //assegno la finestra all'oggetto classifica
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
