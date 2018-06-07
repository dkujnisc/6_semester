#include <iostream>
using namespace std;
#include "waehrung4.h"

int main()
{
char kommando[10];
ClWaehrung betrag;

for(;;)
    {
    cout << "Bitte geben Sie einen Betrag ein (* == Ende): ";
    cin >> betrag;
    if (betrag.wert() < 0) break;

    cout << "Soll der Betrag in Gulden oder in Talern ausgegeben werden (g oder t)? ";
    cin.getline(kommando,9,'\n');
    if(kommando[0]=='g')
      cout << "Sie haben " << betrag.asGulden() << " eingegeben." << endl;
    else if(kommando[0]=='t')
      cout << "Sie haben " << betrag.asTaler() << " eingegeben." << endl;       
    else cout << "Das Kommando " << kommando << " verstehe ich nicht!" << endl; 
    } 
{
	                        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	                        int x;
				                                                cin >> x;
}

}
