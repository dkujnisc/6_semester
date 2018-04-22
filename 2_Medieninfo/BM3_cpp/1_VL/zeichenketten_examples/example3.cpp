#include <iostream>
using namespace std;
#include "zeichenkette3.h"

int main()
{
ClZeichenkette zk1 = "abcdefg", zk2 = "hijklmn", zk3;

zk3 = zk1 + zk2;

cout << zk1 << " ist " << zk1.anzahl() << " Zeichen lang." << endl;
cout << zk2 << " ist " << zk2.anzahl() << " Zeichen lang." << endl;
cout << zk3 << " ist " << zk3.anzahl() << " Zeichen lang." << endl;

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}

