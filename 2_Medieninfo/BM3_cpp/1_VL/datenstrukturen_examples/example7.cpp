#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
ifstream datei;
char puffer[101], *kopie;
char **array;
int zeilen;
int i;
std::stack<char *> stack;

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (zeilen=0;!datei.eof();zeilen++)
    {
    datei.getline(puffer,100,'\n');
    kopie=new char[strlen(puffer)+1];
    strcpy(kopie,puffer);
    stack.push(kopie);
    }

array=new char *[zeilen];

datei.close();

for (i=0;!stack.empty();i++)
    {
    array[i]=stack.top();
    stack.pop();
    }

for (i=0;i<zeilen;i++)
    cout << "Eintrag " << i << " = " << array[i] << endl;
{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
