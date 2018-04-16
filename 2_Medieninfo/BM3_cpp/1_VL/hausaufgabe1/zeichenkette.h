#include <iostream>
#include <string.h>

using namespace std;

#ifndef ZEICHENKETTE_H
#define ZEICHENKETTE_H

class ClZeichenkette{
    public:
        char text[10000];
        int laenge;
};

// quelle: http://public.beuth-hochschule.de/~kempfer/skript_cpp/Kap11.html
// +operator overload
ClZeichenkette operator+ (const ClZeichenkette &a, const ClZeichenkette &b){
    ClZeichenkette c;
    // text von a an c dranhaengen
    strcat (c.text, a.text);
    // text von b an c dranhaengen
    //strcat (c.text,b.text);
    cout << "erfolgreich overloaded" << endl;
    return c;
};

// quelle: http://www.cplusplus.com/forum/beginner/64186/
// cin operator overload
std::istream& operator>> (std::istream &input, ClZeichenkette &z){
    input>>z.text;
    return input;
};

// cout operator overload
std::ostream& operator<<(std::ostream& output, ClZeichenkette &z){
    output<<z.text;
    return output;
};

#endif // ZEICHENKETTE_H
