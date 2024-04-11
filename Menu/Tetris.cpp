#include "Tetris.hpp"
Tetris::Tetris(Menu start)
{
    this->tetramino = Tetramino();
    this->startMenu=start;
};

void Tetris::processInput(){
    srand(time(0));
    int rotation = 0;
    bool isOver = false;
    bool pushDown = false;
    chtype input;
    int fallDownRate = 20;
    int fallDownCount = 0;
    int currentX=19;
    int currentY=0;

    nodelay(this->board.getMatrixWin().getWin(), true);
    refresh();
         while (!isOver)
    {
        // clear();
        //box(win, 0, 0);
        // test.draw(currentY, currentX, rotation);
        this_thread::sleep_for(50ms); //game tick rate

        //testBoard.draw();

        //every n game tick push down the tetromino

        fallDownCount++;
        pushDown = (fallDownCount == fallDownRate);

        if(pushDown){
            fallDownCount = 0;
            currentY++;
        }

        input = wgetch(this->board.getMatrixWin().getWin());
        switch (input)
        {
        case 'a':
            wclear(this->board.getMatrixWin().getWin());
            this->board.draw();
            rotation--;
            if (rotation < 0)
            {
                rotation = 3;
            }
            this->tetramino.draw(this->board.getMatrixWin().getWin(), currentX, currentY, rotation);
            wrefresh(this->board.getMatrixWin().getWin());
            break;
        case 'd':
            wclear(this->board.getMatrixWin().getWin());
            this->board.draw();
            rotation++;
            if (rotation > 3)
            {
                rotation = 0;
            }
            // rotation++;
            this->tetramino.draw(this->board.getMatrixWin().getWin(), currentX, currentY, rotation);
            wrefresh(this->board.getMatrixWin().getWin());
            break;
        case 10:
            isOver = true;
            break;
        case KEY_LEFT:
            currentX--;
            wclear(this->board.getMatrixWin().getWin());
            this->tetramino.draw(this->board.getMatrixWin().getWin(), currentX, currentY, rotation);
            break;
        case KEY_RIGHT:
            currentX++;
            wclear(this->board.getMatrixWin().getWin());
            this->tetramino.draw(this->board.getMatrixWin().getWin(), currentX, currentY, rotation);
            break;
        default:
            if(pushDown){
                wclear(this->board.getMatrixWin().getWin());
            }

            // testBoard.draw();
            this->tetramino.draw(this->board.getMatrixWin().getWin(), currentX, currentY, rotation);
            break;
        }
        refresh();
    }


};

//Loop principale di gioco
void Tetris::gameLoop(){
    int esci=-1;

    // nodelay(stdscr, true);

    do{
        box(this->startMenu.GetWin().getWin(),0,0);
        int scelta=this->startMenu.draw(); //prende l'opzione che era evidenziata nel menu nel momento in cui l'utente ha premuto enter
        wclear(this->startMenu.GetWin().getWin());
        refresh();
        switch(scelta)
        {case 0: //caso new game
            { //TO DO
                this->board=Board(this->startMenu.GetWin());
                this->board.draw();
                // Tetramino testTetramino = Tetramino();
                this->tetramino.draw(this->board.getMatrixWin().getWin(), 19, 0, 0);

                wrefresh(this->board.getMatrixWin().getWin());
                this->processInput();
                //this->testTetramino.draw(this->startMenu.GetWin().getWin(), 1, 1, 0);
                //mvwprintw(this->startMenu.GetWin().getWin(),5,5 ,"finestra di gioco");
                //this->cla.Aggiorna(200); //per vedere se funziona funzione aggiorna
                wgetch(this->startMenu.GetWin().getWin());
                break;}

            case 1:{ //caso classifica

                       box(this->startMenu.GetWin().getWin(),0,0);
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
