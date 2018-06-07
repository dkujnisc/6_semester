#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <string>

int main()
{
vector<string> beispiel1;
list<string> beispiel2;
deque<string> beispiel3;
list<string> beispiel4;

vector<string>::iterator pos1;
list<string>::iterator pos2;
deque<string>::iterator pos3;
list<string>::iterator pos4;

beispiel1.push_back("Wybel");
beispiel1.push_back("Ebert");
beispiel1.push_back("Adrian");

beispiel2.push_back("Mayer");
beispiel2.push_back("Müller");
beispiel2.push_back("Schmitz");

for (pos1=beispiel1.begin(); pos1!= beispiel1.end(); pos1++)
    cout << "Array 1 am Anfang: " << *pos1 << " ";
cout << endl;
    
for (pos2=beispiel2.begin(); pos2!= beispiel2.end(); pos2++)
    cout << "Liste 1 am Anfang: " << *pos2 << " ";
cout << endl;

sort(beispiel1.begin(),beispiel1.end());
beispiel2.sort();
for (pos1=beispiel1.begin(); pos1!= beispiel1.end(); pos1++)
    cout << "Array 1 später: " << *pos1 << " ";
cout << endl;
    
for (pos2=beispiel2.begin(); pos2!= beispiel2.end(); pos2++)
    cout << "Liste 1 später: " << *pos2 << " ";
cout << endl;

copy(beispiel1.begin(),beispiel1.end(),back_inserter(beispiel3));
for (pos3=beispiel3.begin(); pos3!= beispiel3.end(); pos3++)
    cout << "Array 2 / Schritt 2: " << *pos3 << " ";
cout << endl;

copy(beispiel2.begin(),beispiel2.end(),front_inserter(beispiel3));
for (pos3=beispiel3.begin(); pos3!= beispiel3.end(); pos3++)
    cout << "Array 2 / Schritt 3: " << *pos3 << " ";
cout << endl;

pos3=find(beispiel3.begin(),beispiel3.end(),"Mayer");
copy(pos3,beispiel3.end(),back_inserter(beispiel4));
for (pos4=beispiel4.begin(); pos4!= beispiel4.end(); pos4++)
    cout << "Liste 2 vor dem Ende: " << *pos4 << " ";
cout << endl;

beispiel4.sort();
for (pos4=beispiel4.begin(); pos4!= beispiel4.end(); pos4++)
    cout << "Liste 2 am Ende: " << *pos4 << " ";
cout << endl;

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

}
