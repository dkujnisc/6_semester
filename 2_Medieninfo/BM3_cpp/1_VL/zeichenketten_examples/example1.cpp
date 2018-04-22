#include <iostream>
using namespace std;

#include "zeichenkette1.h"

int main()
{
ClZeichenkette zk1 = "abcdefg", zk2 = "hijklmn", zk3;

zk3.verbinde(zk1,zk2);

cout << zk1.kette() << " ist " << zk1.anzahl() << " Zeichen lang." << endl;
cout << zk2.kette() << " ist " << zk2.anzahl() << " Zeichen lang." << endl;
cout << zk3.kette() << " ist " << zk3.anzahl() << " Zeichen lang." << endl;

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}

