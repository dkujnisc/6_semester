#include <iostream>
using namespace std;
#include <string>
#include "zk2.h"


int main()
{
ClZeichenKette zk1, zk2, zk3;
cout << "Bitte geben Sie eine beliebig lange erste Zeichenkette ein:";
cin >> zk1;
cout << "Bitte geben Sie eine beliebig lange zweite Zeichenkette ein:";
cin >> zk2;

zk3 = zk1 + zk2;
cout << zk1 << " + " << zk2 << " = " << zk3 << endl;

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

return 0;
}
