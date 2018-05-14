#include <iostream>
#include <string.h>
#include <header.h>

using namespace std;
//„24fl“,“5x“,“2d“
ClGulden::ClGulden(long gulden, long kreuzer, long pfennige){
    if (gulden>0) {
        w=gulden*240;
    }
    if (kreuzer>0) {
        w=w+kreuzer*4;
    }
    w=w+pfennige;
};

ClGulden::ClGulden(){
};


string ClGulden::asGulden(){
    // wie viele gulden gibts
    // nicht mit nachkommastellen rechnen, daher modulo
    long ersterRest=w % 240;
    long gulden=(w-ersterRest)/240;

    // wie viele kreuzer gibts
    long zweiterRest=ersterRest % 4;
    long kreuzer=(ersterRest-zweiterRest)/4;

    // wie viele pfennige gibts
    long pfennige=zweiterRest;
    // quelle: https://stackoverflow.com/questions/947621/how-do-i-convert-a-long-to-a-string-in-c
    return to_string(gulden) + " Gulden " + to_string(kreuzer) + " Kreuzer " + to_string(pfennige) + " Pfennige";
};
string ClGulden::asTaler(){
    return ClTaler(0, 0, w).asTaler();
}

ClTaler::ClTaler(long taler, long silbergroschen, long pfennige){
    if (taler>0) {
        w=taler*240;
    }
    if (silbergroschen>0) {
        w=w+silbergroschen*12;
    }
    w=w+pfennige;
};

ClTaler::ClTaler(){
};

string ClTaler::asTaler(){
    // wie viele taler gibts
    // nicht mit nachkommastellen rechnen, daher modulo
    long ersterRest=w % 240;
    long taler=(w-ersterRest)/240;

    // wie viele silbergroschen gibts
    long zweiterRest=ersterRest % 12;
    long silbergroschen=(ersterRest-zweiterRest)/12;

    // wie viele pfennige gibts
    long pfennige=zweiterRest;
    // quelle: https://stackoverflow.com/questions/947621/how-do-i-convert-a-long-to-a-string-in-c
    return to_string(taler) + " Taler " + to_string(silbergroschen) + " Silbergroschen " + to_string(pfennige) + " Pfennige";
};

string ClTaler::asGulden() {
    return ClGulden(0, 0, w).asGulden();
};

