#include "Classifica.hpp"

void Punteggio::setPosition(int x, int y)
{
    this->posX=x;
    this->posY=y;
};


Classifica::Classifica()
{
    this->win = Window();
    this->testa=fromFileToList(NULL);
};

Classifica::Classifica(Window win)
{
    this->win = win;
    this->testa=NULL;
    this->testa=fromFileToList(NULL);
};

void Classifica::setPointsPosition(){ //RIFARE
    int X=this->win.getWin()->_maxx;
    int Y=this->win.getWin()->_maxy;
    Punteggio* tmp=this->testa;
    //setto i primi 3 punteggi come se stessero su un podio
    if(tmp!=NULL)
    { tmp->posX= (X/2);
        tmp->posY=4;
        tmp=tmp->next;

        if(tmp!=NULL)
        {
            tmp->posX= (X/3);
            tmp->posY=6;
            tmp=tmp->next;

            if(tmp!=NULL)
            { tmp->posX= 2*(X/3);
                tmp->posY=10;
                tmp=tmp->next;
                int i=12;
                while(tmp!=NULL)
                { tmp->posX= (X/2);
                    tmp->posY=i;
                    i=i+2;
                }
            }
        }
    }
}

int Classifica:: Mostra() //stampo i punteggi dal file
{  int q; //variabile per uscire dalla classifica
    ifstream input; //dichiaro un tipo
    input.open("classifica.txt");
    string linea;
    int Y=4;
    int X=this->win.getWin()->_maxx;

    //setPointsPosition();

    while(!input.eof()) //si esce da questo ciclo quando il file termina (eof=end of file)
    {
        getline(input,linea);
        mvwprintw(this->win.getWin(),Y,X/2-(linea.length())/2-linea.length()%2,linea.c_str());
        Y++;
    }

    input.close();
    wrefresh(this->win.getWin());
    do{
        wattron(this->win.getWin(), A_STANDOUT);
        mvwprintw(this->win.getWin(),1,1,"esci");
        wattroff(this->win.getWin(), A_STANDOUT);
        q=wgetch(this->win.getWin());
    } while(q!=10);//esco dalla classifica solo quando l'utente preme enter
    wclear(this->win.getWin());
    refresh();
    return -1;
};


Punteggio* Classifica:: fromFileToList(Punteggio* head)
{
    ifstream input;
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
                head->p=linea;
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


Punteggio* Classifica::sortInsert(int points, Punteggio* head)
{
    if(head==NULL)
    {head= new Punteggio;
        head->p=to_string(points);
        head->next=NULL;
        return head;

    }
    else
{
        if(points>=stoi(head->p,0,10) )//inserimento del punteggio in testa alla lista
        {
            Punteggio* tmp= new Punteggio;
            tmp->next=head;
            tmp->p=to_string(points);
            head=tmp;
            return head;
        }
        else //punteggio è minore di quello in testa, va inserito in mezzo alla lista
    {
            head->next=sortInsert(points,head->next);
            return head;
        }
    }
};

void Classifica::Aggiorna(int points)
{ ofstream output; //output su file
    this->testa=sortInsert(points,testa);
    output.open("classifica.txt");

    while(testa!=NULL)
    { output<<testa->p<<endl;
        testa=testa->next;

    }
    output.close();


};