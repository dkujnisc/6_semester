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
if(zaehler!=0){
    // ermittlung des vorgaengers=start
    struct satom *vorgaenger = start;

    int vorgaengerWert= atoi(vorgaenger->inhalt);
    for(int i=0;i<zaehler;i++){
        if(NULL!=vorgaenger->naechstes){
            struct satom *nachfolger = vorgaenger->naechstes;
            int nachfolgerWert = atoi(nachfolger->inhalt);

            if(vorgaengerWert<=aktuellesPopItem && aktuellesPopItem<=nachfolgerWert){
                cout << "vorgaenger -neu -nachfolger" << endl;
                cout << vorgaenger->inhalt << "-" << neu->inhalt << "-" << nachfolger->inhalt << endl;
                //vorgaenger -neu -nachfolger
                vorgaenger->naechstes=neu;
                neu->naechstes=nachfolger;
                break;
            }
        }else{
            //vorgaenger=6;
            //aktuellesPopItem=4
            if(vorgaengerWert<=aktuellesPopItem){
                cout << "vorgaenger - neu"<< endl;
                //vorgaenger - neu
                vorgaenger->naechstes=neu;
                end=neu;
                break;
            }else{
                cout << "neu - vorgaenger"<< endl;
                //neu - vorgaenger
                start=neu;
                neu->naechstes=vorgaenger;
                end=vorgaenger;
                vorgaenger->naechstes=NULL;
                break;
            }
        }
    }

}else{
    cout << "erster eintrag"<< endl;
    //wird nur aufgerufen wenn das erste element reingestellt wird,
    start=neu;
    end=neu;
}
zaehler++;
cout << "inkrementi"<< endl;
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
