#include "header.h"
#include <string.h>
#include <iostream>

void methoden::funktion1(string *string1, string *string2){
    // Enthaelt der erste einen Punkt, wird er nicht verändert.
    std::string strNew = *string1;
    if (std::string::npos!=strNew.find(".")) {
        //do nothing
    } else {
        // punkt und string2 an string1 angefuegt
        *string1 = *string1 + "." + *string2;
    }
}

string methoden::funktion2(string tanga){
    // suche nach /
    if (std::string::npos!=tanga.find("/")) {
        // ausschneiden des teils vor /
        return tanga.substr(0,tanga.find("/"));
    }
    return "";
}

string methoden::funktion3(string datei){
    string dateiName = datei;
    // suche nach .
    if (string::npos!=dateiName.find(".")) {
        // ausschneidend des teils vor .
        dateiName=dateiName.substr(0,dateiName.find("."));
    }
    // suche nach letztem /
    if (string::npos!=dateiName.find_last_of("/")) {
        // ausschneiden des inhalts nach letztem /
        dateiName=dateiName.substr(dateiName.find_last_of("/")+1,string::npos);
    }
    return dateiName;
}
