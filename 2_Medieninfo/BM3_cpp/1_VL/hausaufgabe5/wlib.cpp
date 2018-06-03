#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "wtabelle.h"
#include "waehrung.h"

using namespace std;

// quelle: https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
vector<string> ClWaehrung::split(const char *str)
{
    char c = ' ';
    vector<string> result;
    do
    {
        const char *begin = str;
        while(*str != c && *str)
            str++;
        result.push_back(string(begin, str));
    } while (0 != *str++);
    return result;
}
void ClWaehrung::ladeBetrag(istream &eingabe,ClWTabelle &tab) {
    string input = "";
    unit++;
    // usereingabe in input schreiben
    getline(eingabe,input);
    cout << input << endl;
    // eingabe wird in teile zerstueckelt
    vector<string> x=split(input.c_str());
    // quelle:
    // https://stackoverflow.com/questions/15027282/c-for-each-pulling-from-vector-elements
    for (string &tempString : x)
    {
        char* symbol=tab.erstesSymbol();
        for (int i=1;i<atoi(to_string(tab.anzahlSymbole).c_str());i++){
            string::size_type pos=tempString.find(symbol,0);

            if(string::npos!=pos){
                unit = unit + atoi(tempString.substr(0,pos).c_str()) *tab.holeWert();
                waehrung=tab.holeWaehrung();
            }
            symbol=tab.naechstesSymbol();
        }
    }
};
char *ClWaehrung::zeigeWert(ClWTabelle &tab,char *verwende) {
    //verwende ist der kommando input (taler/gulden)
    tab.erstesSymbol();
    char* symbol=tab.erstesSymbol();
    for (int i=1;i<atoi(to_string(tab.anzahlSymbole).c_str());i++){
        string temp=verwende;
        string::size_type pos=temp.find(symbol,0);
        if(string::npos!=pos){
            waehrung=tab.holeWaehrung();
            string aktuelleWaehrung=tab.zeigeWaehrung();
            string guldenStr="gulden";
            cout << "Aktuelle Waehrung: "+aktuelleWaehrung << endl;
            if(0==strcmp(guldenStr.c_str(), aktuelleWaehrung.c_str())){
                string temp=to_string(unit/240)+","+to_string(unit%240/4)+","+to_string(unit%4);
                char * writable = new char[temp.size() + 1];
                std::copy(temp.begin(), temp.end(), writable);
                writable[temp.size()] = '\0';
                return writable;
            }
            string talerStr="taler";
            if(0==strcmp(talerStr.c_str(), aktuelleWaehrung.c_str())){
                string temp=to_string(unit/240)+","+to_string(unit%240/12)+","+to_string(unit%12);
                char * writable = new char[temp.size() + 1];
                std::copy(temp.begin(), temp.end(), writable);
                writable[temp.size()] = '\0';
                return writable;
            }
        }
        symbol=tab.naechstesSymbol();
    }
    return "Es wurde keine Waehrung zur Eingabe gefunden!";
};
char *ClWaehrung::zeigeWaehrung(ClWTabelle &tab) {
    return tab.holeWText(waehrung);
};
