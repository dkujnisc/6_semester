#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "stack4.h"

int main()
{
ifstream datei;
char puffer[101];
char **array;
int zeilen;
int i;
ClStack *wurzel=NULL;
ClStack *jetzt;

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (zeilen=0;!datei.eof();zeilen++)
    {
    datei.getline(puffer,100,'\n');
    jetzt=new ClStack(puffer);
    jetzt->verbinde(wurzel);
    wurzel=jetzt;
    }

array=new char *[zeilen];

datei.close();

jetzt=wurzel;
for (i=0;i<zeilen;i++)
    {
    array[i]=jetzt->hole();
    jetzt=wurzel->positioniere();
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
