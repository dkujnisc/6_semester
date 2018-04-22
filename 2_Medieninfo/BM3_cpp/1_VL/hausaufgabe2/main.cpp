#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    string test = "abc";
    string test2 = "def";
    methoden m;
    m.funktion1(&test, &test2);
    cout << "test:" + test << endl;

    cout << m.funktion2("hhjbhjb/hbjh/datei") << endl;
    cout << m.funktion2("yeah/datei") << endl;

    cout << m.funktion3("datei") << endl;
    cout << m.funktion3("datei.ext") << endl;
    cout << m.funktion3("asda/asda/akk/datei.ext") << endl;
    return 0;
}
