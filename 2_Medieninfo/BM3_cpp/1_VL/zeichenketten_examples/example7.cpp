#include <iostream>
using namespace std;
#include <string>

int main()
{
string zk1 = "Das ist eine Zeichenkette";

cout << "Untersuche: " << zk1 << endl;
cout << "'eine' beginnt in der Kette an Position " << zk1.find("eine") << endl;
cout << endl;

string zk2 = "To be or not to be, that is the question";
cout << "Untersuche: " << zk2 << endl;
cout << "'be' laut find an Position " << zk2.find("be") << endl;
cout << "'be' laut rfind an Position " << zk2.rfind("be") << endl;
cout << endl;

string zk3 = "Zeichen, nichts als Zeichen!";
string vokale = "aeiou";

cout << "Untersuche: " << zk3 << endl;
cout << "find_first_of(vokale): " << zk3.find_first_of(vokale) << endl;
cout << "find_last_of(vokale): " << zk3.find_last_of(vokale) << endl;
cout << "find_first_not_of(vokale): " << zk3.find_first_not_of(vokale) << endl;
cout << "find_last_not_of(vokale): " << zk3.find_last_not_of(vokale) << endl;
cout << endl;

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}

