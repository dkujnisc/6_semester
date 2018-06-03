#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>

int main()
{
ifstream datei1, datei2;
char puffer[101];
char **array;
int zeilen;
int i;

datei1.open("koeln.txt");
if (!datei1)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (zeilen=0;!datei1.eof();zeilen++)
    datei1.getline(puffer,100,'\n');

array=new char *[zeilen];

datei1.close();
datei2.open("koeln.txt");

for (i=0;i<zeilen;i++)
    {
    datei2.getline(puffer,100,'\n');
    array[i]=new char[strlen(puffer)+1];
    strcpy(array[i],puffer);
    }
datei2.close();

for (i=zeilen-1;i>=0;i--)
    cout << "Eintrag " << i << " = " << array[i] << endl;

{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
