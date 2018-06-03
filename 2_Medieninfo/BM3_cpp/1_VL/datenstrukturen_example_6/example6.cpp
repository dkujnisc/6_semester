#include <iostream>
using namespace std;
#include <fstream>
#include "queue6.h"

int main()
{
ifstream datei;
char puffer[101];
char **array;
int zeilen;
int i;
ClQueue queue;

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (;!datei.eof();)
    {
    datei.getline(puffer,100,'\n');
    queue.push(puffer);
    }

zeilen=queue.size();
array=new char *[zeilen];

datei.close();

for (i=0;!queue.empty();i++)
    {
    array[i]=queue.pop();
    }

for (i=0;i<zeilen;i++)
    cout << "Eintrag " << i << " = " << array[i] << endl;
{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
