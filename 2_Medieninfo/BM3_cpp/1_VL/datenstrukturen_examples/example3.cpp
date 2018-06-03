#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "stack3.h"

int main()
{
ifstream datei;
char puffer[101];
char **array;
int zeilen;
struct stack *wurzel=NULL;
struct stack *jetzt;
int i;

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (zeilen=0;!datei.eof();zeilen++)
    {
    datei.getline(puffer,100,'\n');
    jetzt=new struct stack;
    jetzt->inhalt=new char[strlen(puffer)+1];
    strcpy(jetzt->inhalt,puffer);
    jetzt->naechster=wurzel;
    wurzel=jetzt;
    }

array=new char *[zeilen];

datei.close();

jetzt=wurzel;
for (i=0;i<zeilen;i++)
    {
    array[i]=jetzt->inhalt;
    jetzt=wurzel->naechster;
    delete wurzel;
    wurzel=jetzt;
    }

for (i=0;i<zeilen;i++)
    cout << "Eintrag " << i << " = " << array[i] << endl;
	
{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
