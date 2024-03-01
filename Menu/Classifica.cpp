#include "Tetris.hpp"

Classifica::Classifica()
{
    this->winC=nullptr;
    this->testa=nullptr;
};

Classifica::Classifica(WINDOW* win)
{
    this->winC=win;
    this->testa=NULL;
    this->testa=fromFileToList(testa);
};

int Classifica:: Mostra() //stampo i punteggi dal file
{  int q; //variabile per uscire dalla classifica
  ifstream input; //dichiaro un tipo
  input.open("classifica.txt");
          string linea;
          int Y=4;
          int X=50;

           while(!input.eof()) //si esce da questo ciclo quando il file termina (eof=end of file)
           {
             getline(input,linea);
             mvwprintw(this->winC,Y,X,linea.c_str());
             Y++;
            }
            input.close();
    wrefresh(this->winC);
    do{
        wattron(this->winC, A_STANDOUT);
            mvwprintw(this->winC,1,1,"esci");
            wattroff(this->winC, A_STANDOUT);
    q=wgetch(this->winC);
    } while(q!=10);//esco dalla classifica solo quando l'utente preme enter
    wclear(this->winC);
    refresh();
    return -1;
};


Punteggio* Classifica:: fromFileToList(Punteggio* head) //da sistemare
{ ifstream input;
  string linea;
  input.open("classifica.txt");
  Punteggio* tmp=NULL;
  while(!input.eof())
{   getline(input, linea); //prende una linea dalla variabile input (che sarebbe file classifica) e la mette in linea
  if(linea!="\0")
  {
  if(head==NULL) //inserimento di una linea in una lista vuota
{
  head=new Punteggio;
  head->p=linea; // 10 è la base
  head->next=NULL;
  tmp=head;
}
else  //inserimento di una linea in una lista non vuota
{
  while(tmp->next!=NULL) tmp=tmp->next; //arrivo alla fine della lista

  tmp->next=new Punteggio;
  tmp=tmp->next;
  tmp->p=linea;
  tmp->next=NULL;

}
  }
}
  return head;
};

