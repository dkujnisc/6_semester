#include <iostream>
using namespace std;
#include "datum1.h"

int main()
{
ClDatum datum1(1,7,2001);
ClDatum datum2(17,3,2000);

cout << "Zwischen dem " << datum1.astext() << " und dem " << datum2.astext() <<
        " liegen " << datum1.asnumber() - datum2.asnumber() << " Tage" << endl;

{
	                /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	                int x;
			                        cin >> x;
}

}
