#include <iostream>
using namespace std;
#include <string.h>
#include "zeichenkette5.h"

ClZeichenkette::ClZeichenkette(
const char                    *anfangswert)
{
laenge=strlen(anfangswert);
text=new char[laenge+1];
strcpy(text,anfangswert);
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
char buffer[10];
char *teil=NULL, *ganzes=NULL;
int gesamt,i,j,k;

for (gesamt=0;;)
    {
    for (i=0;i<9;i++)
        {
        eingabe.get(buffer[i]);
        if (buffer[i]=='\n') break;
        }
    if (buffer[i]=='\n') break;
    ganzes=new char[gesamt+i];
    for (j=0;j<gesamt;j++) ganzes[j]=teil[j];
    for (k=0;k<i;k++,j++) ganzes[j]=buffer[k];
    gesamt+=i;
    if (teil!=NULL) delete teil;
    teil=ganzes;    
    }

laenge=gesamt+i;
text=new char[laenge+1];
for (j=0;j<gesamt;j++) text[j]=teil[j];
for (k=0;k<i;k++,j++) text[j]=buffer[k];
text[j]='\0'; 
if (teil!=NULL) delete teil;
}
