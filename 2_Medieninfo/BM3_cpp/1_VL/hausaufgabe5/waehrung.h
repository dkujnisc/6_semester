#ifndef WAEHRUNG_H
#define WAEHRUNG_H

#include <istream>
#include <vector>
#include "wtabelle.h"

using namespace std;

class ClWaehrung
   {
protected:
   int unit;
   char text[64];

   int waehrung;
public:
   ClWaehrung() { unit=-1; *text='\0'; waehrung= -1; }
   ~ClWaehrung() { return; }
   vector<string> split(const char *str);
   void ladeBetrag(istream &eingabe,ClWTabelle &tab);
   char *zeigeWert(ClWTabelle &tab,char *verwende);
   char *zeigeWaehrung(ClWTabelle &tab);
   int wert(void) {return unit; }
   };
#endif // WAEHRUNG_H
