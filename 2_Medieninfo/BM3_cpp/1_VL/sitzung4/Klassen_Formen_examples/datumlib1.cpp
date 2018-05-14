#include <iostream>
using namespace std;
#include <stdio.h>
#include "datum1.h"

ClDatum::ClDatum(
int              itag,
int                   imonat,
int                          ijahr)
{
tag=itag;
monat=imonat;
jahr=ijahr;
}

char *ClDatum::astext(void)
{
sprintf(text,"%d.%d.%d",tag,monat,jahr);

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



