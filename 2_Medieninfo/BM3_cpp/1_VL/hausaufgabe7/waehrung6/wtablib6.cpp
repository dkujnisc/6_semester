#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "wtabelle6.h"
#include <vector>

using namespace std;

void ClWTabelle::oeffnen(
char                    *dateiname)
{
ifstream datei;
char puffer[640];
char basis[80];
char teil[80];
int start;
int anzahl;
int nwaehrung;
struct denomination
   {
   char wname[80];
   char symbol[80];
   int wert;
   struct denomination *naechste;
   } ;
struct denomination *jetzt,*wurzel=NULL,*last; 

vector<denomination> test;

datei.open(dateiname);
if (!datei)
   {
   cout << "Datei " << dateiname << " nicht gefunden!" << endl;
   return;
   }

anzahl=0,nwaehrung=0;
datei.getline(puffer,639,'\n');
while (!datei.eof())
   {
   int i;
   for (i=0;puffer[i]!='\0';i++)
       {
       basis[i]=puffer[i];
       if (puffer[i]==':') break;
       }
   if (puffer[i]=='\0')
      {
      cout << "Beschädigte Zeile: " << puffer << endl;
      cout << "Abbruch!" << endl;
      return;
      }
   basis[i]='\0';
   nwaehrung++;
   for (int weiter=1;weiter!=0;)
       {
       int j;

       for (i++;puffer[i]==' ';i++);
       for (j=0;puffer[i]!='\0' && puffer[i]!='=';i++,j++)
           teil[j]=puffer[i];
       if (puffer[i]=='\0')
          {
          cout << "Beschädigte Zeile: " << puffer << endl;
          cout << "Abbruch!" << endl;
          return;
          }
       teil[j]='\0';
       for (i++;puffer[i]==' ';i++);
       start=i;
       for (j=0;puffer[i]!='\0' && puffer[i]!=',';i++,j++);
       if (puffer[i]=='\0') weiter=0;
       puffer[i]='\0';
       jetzt=new struct denomination;
       denomination temp;
       if (wurzel==NULL) wurzel=jetzt;
       else last->naechste=jetzt;
       jetzt->naechste=NULL;
       last=jetzt;
       anzahl++;
       strcpy(jetzt->wname,basis);
       strcpy(jetzt->symbol,teil);
       jetzt->wert=atoi(puffer+start);

       strcpy(temp.wname,basis);
       strcpy(temp.symbol,teil);
       temp.wert=atoi(puffer+start);
       test.push_back(denomination());
       }
datei.getline(puffer,639,'\n');
   }
waehrungen=new char*[nwaehrung+1];
symbol=new char*[anzahl+1];
symbol[anzahl]=NULL;
wert=new int[anzahl+1];
waehrung=new int[anzahl+1];

*basis='\0';
for (int i= -1,j=0;wurzel!=NULL;j++)
    {
    jetzt=wurzel;
    if (strcmp(basis,jetzt->wname))
       {
       i++;
       strcpy(basis,jetzt->wname);

       string temp(basis);
       waehrungenxxx.push_back(temp);

       waehrungen[i]=new char[strlen(basis)+1];
       strcpy(waehrungen[i],basis);
       }
    waehrung[j]=i;
    symbol[j]=new char[strlen(jetzt->symbol)+1];
    strcpy(symbol[j],jetzt->symbol);

    string symboltemp(jetzt->symbol);
    symbolxxx.push_back(symboltemp);

    wert[j]=jetzt->wert;


    wertxxx.push_back(jetzt->wert);

    jetzt=wurzel->naechste;
    delete wurzel;
    wurzel=jetzt;
    }

status=bereit;
}
