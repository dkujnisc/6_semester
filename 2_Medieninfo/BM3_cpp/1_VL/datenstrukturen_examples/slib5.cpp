#include <string.h>
using namespace std;
#include "stack5.h"

ClStack::ClStack()
{
start=NULL;
}

ClStack::~ClStack()
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

void ClStack::push(
char         *zkette)
{
struct satom *neu;

neu=new struct satom;
neu->inhalt=new char[strlen(zkette)+1];
strcpy(neu->inhalt,zkette);
neu->naechstes=start;
start=neu;
}

char *ClStack::pop(void)
{
char *wert;
struct satom *atom;

atom=start;
wert=atom->inhalt;
start=atom->naechstes;
delete atom;

return wert;
}

int ClStack::empty(void)
{
if (start==NULL) return 1;
return 0;
}
