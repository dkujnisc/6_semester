#include <iostream>
using namespace std;
#include "waehrung5.h"

int main()
{
char kommando[10];
ClWaehrung betrag;

for(;;)
    {
    cout << "Bitte geben Sie einen Betrag ein (* == Ende): ";
    cin >> betrag;
    if (betrag.wert() < 0) break;

    cout << "Betrag in Gulden, Talern oder Eingabeform? (g, t, =)? ";
    cin.getline(kommando,9,'\n');
    switch(kommando[0])
       {
    case 'g':
      cout << "Sie haben " << betrag.asGulden() << " eingegeben." << endl;
      break;
    case 't':
      cout << "Sie haben " << betrag.asTaler() << " eingegeben." << endl;
      break;
    case '=':
      cout << "Sie haben " << betrag.asIs() << " eingegeben." << endl;
      break;
    default:
      cout << "Das Kommando " << kommando << " verstehe ich nicht!" << endl;
      break;
      }
    }
{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;
cin >> x;
}

}
