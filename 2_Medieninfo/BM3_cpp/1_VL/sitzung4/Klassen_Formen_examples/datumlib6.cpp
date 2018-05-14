#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include "datum6.h"

ClDatum::ClDatum(
int              itag,
int                   imonat,
int                          ijahr)
{
tag=itag;
monat=imonat;
jahr=ijahr;
}

ClNDatum::ClNDatum():
ClDatum()
{
return;
}

ClNDatum::ClNDatum(
int                itag,
int                     imonat,
int                            ijahr):
ClDatum(itag,imonat,ijahr)
{
}

ClZDatum::ClZDatum(
int                itag,
char                   *cmonat,
int                            ijahr):
ClDatum(itag,0,ijahr)
{
char *monate[]={"jan", "feb", "mär", "apr", "mai", "jun",
                "jul", "aug", "sep", "okt", "nov", "dez"};

strcpy(zmonat,cmonat);

for (monat=0;monat<12;monat++)
    if (!strncmp(cmonat,monate[monat],3)) break;

if (monat==12) cout << "\"" << cmonat << "\"" << " ist kein korrekter Monatsname." << endl;
else monat++;
}

char *ClNDatum::astext(void)
{
sprintf(text,"%d.%d.%d",tag,monat,jahr);

return text;
}

char *ClZDatum::astext(void)
{
sprintf(text,"%d %s %d",tag,zmonat,jahr);

return text;
}

int ClDatum::asnumber(void)
{
int tage[] = {31,59,90,120,151,181,212,243,273,304,334};
int basejahr;
int resultat;

basejahr=jahr-1;
resultat=jahr * 365 + basejahr/4 - basejahr/100 + basejahr/400;
if (monat>1) resultat+= tage[monat-2];
resultat += tag;
if (monat > 2 && (jahr % 4 == 0) && (jahr % 100 != 0 || jahr % 400 == 0)) resultat++;

return resultat;
}
