#include <iostream>
using namespace std;
#include <ctype.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "waehrung5.h"

char *ClWaehrung::asGulden(void)
{
int fl,x,d;

fl=unit/240;
x=unit%240;
d=x%4;
x=x/4;
sprintf(text,"%d Gulden, %d Kreuzer, %d Pfennige",fl,x,d);
return text;
}

char *ClWaehrung::asTaler(void)
{
int t,sgr,pf;

t=unit/240;
sgr=unit%240;
pf=sgr%12;
sgr=sgr/12;
sprintf(text,"%d Taler, %d Silbergroschen, %d Pfennige",t,sgr,pf);
return text;
}

char *ClWaehrung::asIs(void)
{
if (waehrung==gulden) return asGulden();
return asTaler();
}

void ClWaehrung::ladeBetrag(istream &eingabe)
{
enum zustand {anfang,betrag,einheit};
enum typ {ziffer,buchstabe,stern,whiteSpace};
enum zustand zustand;
enum typ typ;
int teilBetrag[10];
char teilEinheit[10][10];
int anzahl,zaehler;
char puffer[10], zeichen;
char *symbol[] = {"fl","x","d","t","sgr","pf",NULL};
int wert[] = {240, 4, 1, 240, 12, 1};
enum waehrung teilVon[] = {gulden, gulden, gulden, taler, taler, taler};

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
for (int i=0,j;i<anzahl;i++)
    {
    for (j=0;symbol[j]!=NULL && strcmp(teilEinheit[i],symbol[j]);j++);
    if (symbol[j]==NULL)
       {
       cout << "Unbekannte Währung: " << teilEinheit[i] << endl;
       unit = -1;
       return;
       }
    if (waehrung==keine) waehrung=teilVon[i];
    else if (waehrung!=teilVon[i])
       {
       cout << "Unverträgliche Denominationen!" << endl;
       unit= -1;
       return;
       }
    unit += teilBetrag[i] * wert[j];
    }
}
