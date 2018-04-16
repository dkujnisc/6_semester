// HKI C++ Programmierpraktikum SoSe 2018 - 12.04.2018
#include <iostream>
using namespace std;

void verbinden(char *a, char *b)
{
   char zk3[100];

   /* Bitte die Zeilen hier vervollständigen. */

   cout << a << " + " << b << " = " << zk3 << endl;
}

int main()
{
   int n = 50;
   char zk1[n], zk2[n];
   cout << "Bitte geben Sie die erste Zeichenkette ein : ";
   cin >> zk1;
   cout << "Bitte geben Sie die zweite Zeichenkette ein: ";
   cin >> zk2;

   verbinden(zk1,zk2);

   return 0;
}
