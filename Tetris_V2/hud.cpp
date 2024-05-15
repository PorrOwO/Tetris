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
void hud::setScore(int punteggio)
{
    this->punteggio=punteggio;
    
} 
void hud::computeScore(int lines)
{
    this->punteggio+=lines*this->multiplier;
}
void hud::setName(char nome)
{
    this->nome=nome;
}
void hud::nextPiece(int shape[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->nextshape[i][j] = shape[i][j];
        }
    }
}
void hud::printHUD()
{
    box(this->win, 0, 0);
    box(this->wpezzo, 0, 0);
    mvprintw(0, 0, "Punteggio: %d", this->punteggio);
    mvprintw(0, 1, "Nome: %c", this->nome);
    mvprintw(0, 5, "Prossimo pezzo: %d", this->nextshape);
}
void hud::printHUD(WINDOW* win, WINDOW* wpezzo, int punteggio, char nome)
{
    box(win, 0, 0);
    box(wpezzo, 0, 0);
    mvprintw(0, 0, "Punteggio: %d", punteggio);
    mvprintw(0, 1, "Nome: %c", nome);
    mvprintw(0, 5, "Prossimo pezzo: %d", nextshape);
}