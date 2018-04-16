#include <iostream>
using namespace std;
#include "rom8.h"

int main()
{
int zahl1;
ClRomZahl zahl2, ergebnis;

cout << "Bitte geben Sie eine erste (arabische) Zahl ein:";
cin >> zahl1;
cout << "Bitte geben Sie eine zweite (roemische) Zahl ein:";
cin >> zahl2;


// kein int sondern roemische zahl
ergebnis = zahl1 + zahl2;
cout << zahl1 << " + " << zahl2 << " = " << ergebnis << endl;
{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;
cin >> x;
}
}
