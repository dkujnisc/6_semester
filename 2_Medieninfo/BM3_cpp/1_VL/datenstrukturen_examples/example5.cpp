#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "stack5.h"

int main()
{
ifstream datei;
char puffer[101];
char **array;
int zeilen;
int i;
ClStack stack;

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (zeilen=0;!datei.eof();zeilen++)
    {
    datei.getline(puffer,100,'\n');
    stack.push(puffer);
    }

array=new char *[zeilen];

datei.close();

for (i=0;!stack.empty();i++)
    {
    array[i]=stack.pop();
    }

for (i=0;i<zeilen;i++)
    cout << "Eintrag " << i << " = " << array[i] << endl;
{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
