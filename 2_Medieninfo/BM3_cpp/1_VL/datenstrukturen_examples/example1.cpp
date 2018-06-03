#include <iostream>
using namespace std;
#include <fstream>
#include <string>

int main()
{
ifstream datei;
char puffer[101];

datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }

for (;!datei.eof();)
    {
    datei.getline(puffer,100,'\n');
    cout << puffer << endl;
    }

{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
