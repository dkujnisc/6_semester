#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdio.h>
#include "waehrung2.h"

ClWaehrung::ClWaehrung(int ifl, int ix, int id) //Standardeingabe in Gulden
{
fl=ifl;
x=ix;
d=id;

int gpfennige;
gpfennige=240*ifl+4*ix+id;
t=gpfennige/240;
sgr=(gpfennige%240)/12;
pf=(gpfennige%240)%12;
}

ClWaehrungGulden::ClWaehrungGulden() : ClWaehrung()
{
return;
}

ClWaehrungGulden::ClWaehrungGulden(int ifl, int ix, int id) : ClWaehrung(ifl, ix, id)
{
}

ClWaehrungTaler::ClWaehrungTaler(int it, int isgr, int ipf)
{
t=it;
sgr=isgr;
pf=ipf;

int tpfennige;
tpfennige=240*it+12*isgr+ipf;
fl=tpfennige/240;
x=(tpfennige%240)/4;
d=(tpfennige%240)%4;
}

char *ClWaehrung::asGulden(void)
{
sprintf(textg,"%d Gulden, %d Kreuzer, %d Pfennige",fl,x,d);
return textg;
}

char *ClWaehrung::asTaler(void)
{
sprintf(textt,"%d Taler, %d Silbergroschen, %d Pfennige",t,sgr,pf);
return textt;
}

void ClWaehrungGulden::ladeGulden(istream &eingabe)
{
char puffer[10], zeichen;
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

int gpfennige;
gpfennige=240*fl+4*x+d;
t=gpfennige/240;
sgr=(gpfennige%240)/12;
pf=(gpfennige%240)%12;
}

void ClWaehrungTaler::ladeTaler(istream &eingabe)
{
char puffer[10], zeichen;
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

int tpfennige;
tpfennige=240*t+12*sgr+pf;
fl=tpfennige/240;
x=(tpfennige%240)/4;
d=(tpfennige%240)%4;
}
