#include <iostream>
using namespace std;
#include <vector>
#include <list>

int main()
{
vector<int> beispiel1;
list<int> beispiel2;
int i;

vector<int>::iterator pos1;
list<int>::iterator pos2;

for (i=0;i<6;i++) beispiel1.push_back(i);
for (i=0;i<6;i++) beispiel2.push_back(i);

for (pos1=beispiel1.begin(); pos1!= beispiel1.end(); pos1++)
    cout << "Array: " << *pos1 << endl;

for (pos2=beispiel2.begin(); pos2!= beispiel2.end(); pos2++)
    cout << "Liste: " << *pos2 << endl;

{
/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
int x;

cin >> x;
}

}
