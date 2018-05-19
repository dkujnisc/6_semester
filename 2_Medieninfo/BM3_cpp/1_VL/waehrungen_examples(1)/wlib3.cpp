#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdio.h>
#include "waehrung3.h"

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

void ClWaehrung::ladeGulden(istream &eingabe)
{
char puffer[10], zeichen;
int fl=0,x=0,d=0;
int zaehler=0;

for(;;)
   {
   eingabe.get(zeichen);
   if(zeichen=='\n') break;
    switch(zeichen)
       {
    case 'f':
       puffer[zaehler]='\0';
       zaehler=0;
       fl=atoi(puffer);
       break;
    case 'x':
       puffer[zaehler]='\0';
       zaehler=0;
       x=atoi(puffer);
       break;
    case 'd':
       puffer[zaehler]='\0';
       zaehler=0;
       d=atoi(puffer);
       break;
    case 'l':
       break;
    case ' ':
       break;
    case ',':
       break;
    default:
       puffer[zaehler]=zeichen;
       zaehler++;
       break;
       }
   }

unit=240*fl+4*x+d;
}

void ClWaehrung::ladeTaler(istream &eingabe)
{
char puffer[10], zeichen;
int t=0,sgr=0,pf=0;
int zaehler=0;

for(;;)
   {
   eingabe.get(zeichen);
   if(zeichen=='\n') break;
    switch(zeichen)
       {
    case 't':
       puffer[zaehler]='\0';
       zaehler=0;
       t=atoi(puffer);
       break;
    case 's':
       puffer[zaehler]='\0';
       zaehler=0;
       sgr=atoi(puffer);
       break;
    case 'p':
       puffer[zaehler]='\0';
       zaehler=0;
       pf=atoi(puffer);
       break;
    case 'g':
       break;
    case 'r':
       break;
    case 'f':
       break;
    case ' ':
       break;
    case ',':
       break;
    default:
       puffer[zaehler]=zeichen;
       zaehler++;
       break;
       }
   }

unit=240*t+12*sgr+pf;
}
