#include <iostream>
#include "zeichenkette.h"

using namespace std;

int main(){
    // anlegen von 3 objekten von ClZeichenkette
    ClZeichenkette zk1;
    ClZeichenkette zk2;
    ClZeichenkette zk3;
      cout << "Bitte geben Sie eine beliebig lange erste Zeichenkette ein:";
      cin >> zk1;
      cout << "Bitte geben Sie eine beliebig lange zweite Zeichenkette ein:";
      cin >> zk2;

      zk3 = zk1 + zk2;
      cout << zk1 << " + " << zk2 << " = " << zk3 << endl;
}
