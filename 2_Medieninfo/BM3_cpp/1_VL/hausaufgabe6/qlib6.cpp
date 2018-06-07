#include <iostream>
#include <string.h>
using namespace std;
#include "queue6.h"

ClQueue::ClQueue()
{
start=NULL;
end=NULL;
zaehler=0;
}

ClQueue::~ClQueue()
{
struct satom *atom;

while (start!=NULL)
   {
   atom=start;
   delete atom->inhalt;
   start=atom->naechstes;
   delete atom;
   }
}

void ClQueue::push(
char         *zkette)
{
struct satom *neu;

// aufbau des neuen items
neu=new struct satom;
neu->inhalt=new char[strlen(zkette)+1];
strcpy(neu->inhalt,zkette);
neu->naechstes=NULL;
cout << neu->inhalt << endl;
int aktuellesPopItem= atoi(neu->inhalt);
if(zaehler==0){
    cout << "erster eintrag"<< endl;
    //wird nur aufgerufen wenn das erste element reingestellt wird,
    start=neu;
    end=neu;
    zaehler++;
    return;
}
struct satom *anfang = start;
int anfangWert= atoi(anfang->inhalt);

if(anfangWert<=aktuellesPopItem){
    cout << "B" << endl;
    neu->naechstes=anfang;
    start=neu;
    zaehler++;
    return;
}
struct satom *ende = end;
int endWert= atoi(ende->inhalt);
if(endWert>=aktuellesPopItem){
    cout << "C" << endl;

    ende->naechstes=neu;
    end=neu;
    zaehler++;
    return;
}

// ermittlung des vorgaengers=start
struct satom *vorgaenger = start;
struct satom *nachfolger = vorgaenger->naechstes;
while(NULL != vorgaenger->naechstes){
    int vorgaengerWert = atoi(vorgaenger->inhalt);
    int nachfolgerWert = atoi(nachfolger->inhalt);
    cout << vorgaenger->inhalt <<"-"<<neu->inhalt<<"-"<<nachfolger->inhalt<<endl;
    if(vorgaengerWert<= aktuellesPopItem && aktuellesPopItem <= nachfolgerWert){
              vorgaenger->naechstes=neu;
              neu->naechstes=nachfolger;
              zaehler++;
              return;
    }
    vorgaenger = nachfolger;
    nachfolger = vorgaenger->naechstes;
}
cout << "NICHT GUT weil eigentlich hätte eine der bedinungen zutreffen müssen"<< "-" << start->inhalt<< "-" << end->inhalt<< "-" << neu->inhalt << endl;
}
char *ClQueue::pop(void)
{
char *wert;
struct satom *atom;

atom=start;
wert=atom->inhalt;
start=atom->naechstes;
delete atom;
if (start==NULL) end=NULL;
zaehler--;

return wert;
}

int ClQueue::empty(void)
{
if (start==NULL) return 1;
return 0;
}

int ClQueue::size(void)
{
return zaehler;
}
