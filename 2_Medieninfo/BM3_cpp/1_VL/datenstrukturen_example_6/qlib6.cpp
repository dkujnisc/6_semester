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

neu=new struct satom;
neu->inhalt=new char[strlen(zkette)+1];
strcpy(neu->inhalt,zkette);
neu->naechstes=NULL;
if (end!=NULL) end->naechstes=neu;
else start=neu;
end=neu;
zaehler++;
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
