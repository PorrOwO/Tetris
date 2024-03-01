#include "Menu.hpp"

/* TO DO
 * aggiungere a punteggio un metodo che inizializzi le varie posizioni dei punteggi (come opzioni)
 * Importare la funzione di inserimento di un numero in una lista ordinata (GIA ESISTENTE)
 * Importare funzione che aggiorna il file di testo "classifica.txt" (GIA ESISTENTE)
 */
class Punteggio{
public:
  string p;
    //int posX;
    //int posY;
    Punteggio* next; //ogni punteggio punta a quello successivo
//public:


};

class Classifica{
protected:
    int numPunteggi=10; //voglio stampare solo i primi  10 punteggi più alti
    Punteggio* testa; //puntatore alla testa della lista di punteggi
public:
    WINDOW* winC;
    Classifica();
    Classifica(WINDOW* win);
    void Aggiorna(int points);
    int Mostra();
    Punteggio* fromFileToList(Punteggio* head);
};





