#include <iostream>
using namespace std;
#include "wtabelle6.h"
#include "waehrung6.h"

int main()
{
char kommando[80];
ClWaehrung betrag;
ClWTabelle tabelle;

tabelle.oeffnen("waehrung.txt");
if (tabelle.zustand()!=bereit) return 0;

for(;;)
    {
    cout << "Bitte geben Sie einen Betrag ein (* == Ende): ";
    betrag.ladeBetrag(cin,tabelle);
    if (betrag.wert() < 0) break;

    cout << "Ausgabewährung? (waehrung oder =)? ";
    cin.getline(kommando,80,'\n');
    cout << "Sie haben " << betrag.zeigeWert(tabelle,kommando) << "in " << betrag.zeigeWaehrung(tabelle) << " eingegeben." << endl;
    }

{
	                        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	                        int x;
				                                                cin >> x;
return 0;
}

}
