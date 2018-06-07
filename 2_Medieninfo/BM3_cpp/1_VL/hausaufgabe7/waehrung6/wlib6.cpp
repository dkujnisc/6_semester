#include <iostream>
using namespace std;
#include <ctype.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "wtabelle6.h"
#include "waehrung6.h"

char *ClWaehrung::zeigeWert(
ClWTabelle                 &tab,
char                           *verwende)
{
/* S. Aufgabenstellung zum Tag */

sprintf(text,"Numerisch: %d",unit);
return text;
}

char *ClWaehrung::zeigeWaehrung(
ClWTabelle                    &tab)
{
return tab.holeWText(waehrung);
}

void ClWaehrung::ladeBetrag(
istream                    &eingabe,
ClWTabelle                         &tab)
{
enum zustand {anfang,betrag,einheit};
enum typ {ziffer,buchstabe,stern,whiteSpace};
enum zustand zustand;
enum typ typ;
int teilBetrag[10];
char teilEinheit[10][10];
int anzahl,zaehler;
char puffer[10], zeichen;

waehrung=-1;

for(zustand=anfang,anzahl=0,zaehler=0;;)
   {
   eingabe.get(zeichen);
   if (zeichen=='\n') break;
   if (isdigit(zeichen)) typ=ziffer;
   else if (isalpha(zeichen)) typ=buchstabe;
   else if (zeichen=='*') typ=stern;
   else typ=whiteSpace;
   
   switch(typ)
      {
   case ziffer:
      if (zustand==anfang) zustand=betrag;
      else if (zustand!=betrag)
         {
         cout << "Formatfehler!" << endl;
         unit=-1;
         return;
         }
      puffer[zaehler]=zeichen;
      zaehler++;
      break;
   case buchstabe:
      if (zustand==betrag)
         {
         puffer[zaehler]='\0';
         teilBetrag[anzahl]=atoi(puffer);
         zustand=einheit;
         zaehler=0;
         }
       else if (zustand!=einheit)
         {
         cout << "Formatfehler!" << endl;
         unit=-1;
         return;
         }
      puffer[zaehler]=zeichen;
      zaehler++;
      break;
   case whiteSpace:
      if (zustand==einheit)
         {
         puffer[zaehler]='\0';
         strcpy(teilEinheit[anzahl],puffer);
         anzahl++;
         zustand=anfang;
         zaehler=0;
         }
       else if (zustand!=anfang)
         {
         cout << "Formatfehler!" << endl;
         unit=-1;
         return;
         }
       break;
   case stern:
       unit=-1;
       return;
       }
   }

if (zustand==einheit)
   {
   puffer[zaehler]='\0';
   strcpy(teilEinheit[anzahl],puffer);
   anzahl++;
   }
else if (zustand!=anfang)
   {
   cout << "Formatfehler!" << endl;
   unit=-1;
   return;
   }

unit=0;
for (int i=0;i<anzahl;i++)
    {
    char *symbol;
    for (symbol=tab.erstesSymbol();
         symbol!=NULL && strcmp(teilEinheit[i],symbol);
         symbol=tab.naechstesSymbol());
    if (symbol==NULL)
       {
       cout << "Unbekannte Währung: " << teilEinheit[i] << endl;
       unit = -1;
       return;
       }
    if (waehrung==-1) waehrung=tab.holeWaehrung();
    else if (waehrung!=tab.holeWaehrung())
       {
       cout << "Unverträgliche Denominationen!" << endl;
       unit= -1;
       return;
       }
    unit += teilBetrag[i] * tab.holeWert();
    }
}
