#include "hud.hpp"
#include "Tetramino.hpp"


hud::hud(WINDOW *win, WINDOW* wpezzo, int punteggio, char nome)
{
    this->win= win;
    this->wpezzo=wpezzo;
    this->punteggio=punteggio;
    this->nome=nome;
}
hud::~hud(){

}

void hud::punteggioAttuale(int punteggio)
{
    this->punteggio=punteggio;
    mvprintw(0, 0, char (punteggio) , this->win);
} 
void hud::Nome(WINDOW* win, char nome)
{
    this->nome=nome;
    mvprintw(0,1, nome, this->win);
}
void hud::nextPiece(int shape[4][4])
{
    this->shape=shape;
  
}
void hud::printHUD()
{
    box(this->win, 0, 0);
    box(this->wpezzo, 0, 0);
    mvprintw(0, 0, "Punteggio: %d", this->punteggio);
    mvprintw(0, 1, "Nome: %c", this->nome);
    mvprintw(0, 0, "Prossimo pezzo: ");
    mvprintw(0, 0, Tetramino::setShape(shape));
}