#include <iostream>
using namespace std;
#include <string>

int main()
{
string zk = "Das ist eine Zeichenkette";

cout << "Untersuche: " << zk << endl;
if (zk.find("eine")!=string::npos)
   cout << "Die Zeichenkette enthält 'eine'" << endl;
else cout << "Die Zeichenkette enthält 'eine' nicht" << endl;
if (zk.find("xxxx")!=string::npos)
   cout << "Die Zeichenkette enthält 'xxxx'" << endl;
else cout << "Die Zeichenkette enthält 'xxxx' nicht" << endl;

cout << endl;
string zk2;
zk2=zk;
for (int i=0;i<zk2.length();i++) zk2[i]=tolower(zk2[i]);
cout << "klein: " << zk2 << endl;

cout << endl;
string zk3;
zk3=zk;
for (int j=0;j<zk3.length();j++) zk3[j]=toupper(zk3[j]);
cout << "gross: " << zk3 << endl;

{
	/* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	int x;
	cin >> x;
}

}
