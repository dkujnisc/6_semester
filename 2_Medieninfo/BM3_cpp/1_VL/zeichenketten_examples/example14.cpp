#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>

int main()
{
string zk = "Ein Wort";

zk.at(5)='e';

cout << "Ergebnis: " << zk << endl;

try 
   {
   zk.at(17)='e';

   cout << "Ergebnis: " << zk << endl;
   }
catch (out_of_range)
   {
   cout << "Keine Änderung, falsch gelaufen!" << endl;
   }

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}
