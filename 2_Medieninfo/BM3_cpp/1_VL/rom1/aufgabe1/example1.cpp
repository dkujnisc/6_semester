#include <iostream>
using namespace std;
#include "rom1.h"

int main()
{
ClRomZahl zahl1, zahl2, ergebnis; 

cout << "Bitte geben Sie eine erste Zahl ein:";
zahl1.hole();
cout << "Bitte geben Sie eine zweite Zahl ein:";
zahl2.hole();

ergebnis.addiere(zahl1,zahl2);

cout << zahl1.druckbar() << " + " << zahl2.druckbar() << " = " << ergebnis.druckbar() << endl;
{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;
cin >> x;
}
}
