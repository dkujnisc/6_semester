#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>

int main()
{
int i;
vector<char> beispiel1;
list<char> beispiel2;

vector<char>::iterator pos1;
list<char>::iterator pos2;

char random[] = "FDACBE";

for (i=0;i<6;i++) beispiel1.push_back(random[i]);
for (i=0;i<6;i++) beispiel2.push_back(random[i]);

for (pos1=beispiel1.begin(); pos1!= beispiel1.end(); pos1++)
    cout << "Array am Anfang: " << *pos1 << " ";
cout << endl;

for (pos2=beispiel2.begin(); pos2!= beispiel2.end(); pos2++)
    cout << "Liste am Anfang: " << *pos2 << " ";
cout << endl;

/*
MANCHE Implementationen sehen sort() auch für Vektoren vor.
beispiel1.sort();
ALLE für Listen.
*/
beispiel2.sort();

for (pos1=beispiel1.begin(); pos1!= beispiel1.end(); pos1++)
    cout << "Array am Ende: " << *pos1 << " ";
cout << endl;

for (pos2=beispiel2.begin(); pos2!= beispiel2.end(); pos2++)
    cout << "Liste am Ende: " << *pos2 << " ";
cout << endl;

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

}
