#include <iostream>
using namespace std;
#include <list>
#include "beispiel8.h"

int main()
{

ClBeispiel *jetzt;

list<ClBeispiel> beispiel;
list<ClBeispiel>::iterator pos;

beispiel.push_back(ClBeispiel(77));
beispiel.push_back(ClBeispiel(44));
beispiel.push_back(ClBeispiel(66));

for (pos=beispiel.begin(); pos!= beispiel.end(); pos++)
    cout << "Klasse: " << (*pos).zeige() << " ";
cout << endl;

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

}
