#include <iostream>
using namespace std;
#include <string.h>
#include "zeichenkette4.h"

ClZeichenkette::ClZeichenkette(
const char                    *anfangswert)
{
// jetzt wird nur die laenge gespeichert
laenge=strlen(anfangswert);
//text=new char[laenge+1];
//strcpy(text,anfangswert);
}

void ClZeichenkette::verbinde(
const ClZeichenkette         &zk1,
const ClZeichenkette             &zk2)
{
laenge=strlen(zk1.text)+strlen(zk2.text);
text=new char[laenge+1];
strcpy(text,zk1.text);
strcpy(text+zk1.laenge,zk2.text);
}

void ClZeichenkette::ladeZk(
istream                    &eingabe)
{
int i;
char buffer[100];

for (i=0;i<99;i++)
    {
    eingabe.get(buffer[i]);
    if (buffer[i]=='\n') break;
    }
buffer[i]='\0';

laenge=i;
text=new char[i+1];
strcpy(text,buffer);
}

