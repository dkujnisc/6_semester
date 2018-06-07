#include <iostream>
using namespace std;

int main()
{
int beispiel1[1000];
int i;
struct beispiel2
   {
   int wert;
   struct beispiel2 *naechstes;
   struct beispiel2 *voriges;
   } ;
struct beispiel2 *wurzel, *jetzt, *zuletzt;


for (i=0;i<6;i++) beispiel1[i]=i;

for (i=0,wurzel=NULL,zuletzt=NULL;i<6;i++)
    {
    jetzt=new struct beispiel2;
    jetzt->naechstes=NULL;
    jetzt->wert=i;
    if (wurzel==NULL) wurzel=jetzt;
    else zuletzt->naechstes=jetzt;
    jetzt->voriges=zuletzt;
    zuletzt=jetzt;
    }

for (i=0;i < 6;i++) cout << "Array[" << i << "] = " << i << endl;

for (jetzt=wurzel;jetzt!=NULL;jetzt=jetzt->naechstes)
     cout << "Liste-> " << jetzt->wert << endl;   

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

}
