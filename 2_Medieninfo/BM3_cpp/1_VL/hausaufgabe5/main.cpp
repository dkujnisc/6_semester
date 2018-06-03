#include <iostream>
#include "wtabelle.h"
#include "waehrung.h"

using namespace std;

int main() {
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
    cout << "Ausgabewaehrung? (waehrung oder =)? ";
    cin.getline(kommando,80,'\n');
    cout << "Sie haben " << betrag.zeigeWert(tabelle,kommando) << " in " << betrag.zeigeWaehrung(tabelle) << " eingegeben." << endl;
    }
return 0;
}
