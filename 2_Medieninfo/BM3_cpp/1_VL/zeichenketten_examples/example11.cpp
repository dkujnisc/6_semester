#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>

int main()
{
string zk = "Ein Wort";

try
   {
   string teil1(zk,100,3);
   cout << "teil1: " << teil1 << endl;
   }
catch (out_of_range)
   {
   cout << "Das schaffe ich beim besten Willen nicht." << endl;
   }

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}

