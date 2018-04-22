#include <iostream>
using namespace std;
#include <string.h>
#include "zeichenkette3.h"

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
