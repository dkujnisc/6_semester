#include <iostream>
using namespace std;
#include "zeichenkette4.h"

int main()
{
ClZeichenkette zk1, zk2, zk3;

cout << "Bitte geben Sie eine beliebig lange erste Zeichenkette ein:";
cin >> zk1;
cout << "Bitte geben Sie eine beliebig lange zweite Zeichenkette ein:";
cin >> zk2;

zk3 = zk1 + zk2;

/* Soll so implementiert werden, dass '+' als 'Verkettung' definiert ist.
   D.h.: Aus den Ketten 'abc' + 'def' wird: 'abcdef' */

cout << zk1 << " + " << zk2 << " = " << zk3 << endl;

{
    /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
    int x;
    cin >> x;
}

}
