#include <iostream>
using namespace std;
#include "zeichenkette1.h"

ClZeichenkette::ClZeichenkette(
char                          *anfangswert)
{
char *c,*q,*z;

for (laenge=0,c=anfangswert;*c!='\0';c++) laenge++;
text=new char[laenge+1];
for (z=text,q=anfangswert; (*z = *q); z++, q++);
}

void ClZeichenkette::verbinde(
const ClZeichenkette         &zk1,
const ClZeichenkette             &zk2)
{
char *c,*q,*z;

for (laenge=0,c=zk1.text;*c!='\0';c++) laenge++;
for (c=zk2.text;*c!='\0';c++) laenge++;
text=new char[laenge+1];
for (z=text,q=zk1.text; (*z = *q); z++, q++);
for (q=zk2.text; (*z = *q); z++, q++);
}
