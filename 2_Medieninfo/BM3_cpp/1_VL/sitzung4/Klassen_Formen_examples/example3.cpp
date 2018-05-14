#include <iostream>
using namespace std;
#include "datum3.h"

int main()
{
ClDatum datum1(1,7,2001);
ClDatum datum2(17,"märz",2000);

cout << "Zwischen dem " << datum1.astext() << " und dem " << datum2.astext() <<
        " liegen " << datum1.asnumber() - datum2.asnumber() << " Tage" << endl;
{
	                /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	                int x;
			                        cin >> x;
}

}
