#include <iostream>
#include "zeichenkette.h"

using namespace std;

int main(){
    ClZeichenkette zk1, zk2, zk3;
    // quelle: http://www.cplusplus.com/reference/string/string/copy/
    std::string str ("klappt doch");
      std::size_t length = str.copy(zk2.text, str.length());
      zk2.text[length]='\0';
      cout << zk2.text << endl;
    std::string str1 ("klappt auch");
      std::size_t length1 = str1.copy(zk1.text, str1.length());
      zk1.text[length1]='\0';
    //cout << "Bitte geben Sie eine beliebig lange erste Zeichenkette ein:";
   // cin >> zk1;
   // cout << "Bitte geben Sie eine beliebig lange zweite Zeichenkette ein:";
   // cin >> zk2;

    zk3 = zk1 + zk2;
    cout << zk3.text << endl;
    //cout << zk1 << " + " << zk2 << " = " << zk3 << endl;
}
